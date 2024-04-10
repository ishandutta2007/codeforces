#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=55,mod=1000000007;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
int f[N][N],g[N][N],ff[N][N],inv[N],tp[N][N];
int main(){
	inv[0]=inv[1]=1;for(int i=2;i<N;++i)inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	int n,m;read(n,m);
	f[0][1]=1,ff[0][1]=ff[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i+1;++j){
			for(int k=0;k<=i-1;++k){
				add(g[i][j],(1LL*ff[k][j]*f[i-1-k][j]+1LL*f[k][j]*ff[i-1-k][j+1])%mod);
			}
			int coef=1;memcpy(tp,f,sizeof(tp));
			for(int c=1;c*i<=n;++c){
				int a=c*i,b=c*j;coef=1LL*coef*(g[i][j]+c-1)%mod*inv[c]%mod;
				for(int x=0;x+a<=n;++x){
					for(int y=0;y+b<=n+1;++y){
						add(tp[x+a][y+b],1LL*f[x][y]*coef%mod);
					}
				}
			}
			memcpy(f,tp,sizeof(f));
		}
		for(int j=i+1;j>=1;--j)ff[i][j]=f[i][j],add(ff[i][j],ff[i][j+1]);
	}
	printf("%d\n",f[n][m]);
	return 0;
}