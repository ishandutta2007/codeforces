#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=205;
typedef unsigned int uint;
uint C[N][N],mod,f[N][N],g[N];
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
int main(){
	int n,d;read(n,d,mod);
	for(int i=0;i<=n;++i)for(int j=C[i][0]=1;j<=i;++j)C[i][j]=C[i-1][j-1],add(C[i][j],C[i-1][j]);
	f[1][0]=1,g[1]=1;
	for(int i=2;i<=n;++i){
		for(int j=1;j<=d;++j)for(int k=1;k<i;++k)add(f[i][j],1ULL*f[i-k][j-1]*C[i-2][k-1]%mod*g[k]%mod);
		for(int j=0;j<d;++j)add(g[i],f[i][j]);
	}
	uint ans=0;for(int i=0;i<n;++i)for(int j=0;j<=d;++j)for(int k=0;j+k<=d;++k)if(k!=1)add(ans,1LL*f[i+1][j]*f[n-i][k]%mod);
	printf("%lld\n",2LL*n*(n-1)*ans%mod);
	return 0;
}