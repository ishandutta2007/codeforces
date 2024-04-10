#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int M=12252240,mod=998244353;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int a[10000005],f[M],g[M],C[18][18];
int main(){
	for(int i=0;i<18;++i)for(int j=C[i][0]=1;j<=i;++j)C[i][j]=C[i-1][j-1],add(C[i][j],C[i-1][j]);
	int n,x,y,k,m;read(n,a[0],x,y,k,m);
	for(int i=1;i<n;++i)a[i]=(1LL*a[i-1]*x+y)%m;
	int coef=0;for(int i=0;i<=k;++i)add(coef,1LL*i*C[k][i]*ksm(n-1,k-i)%mod);
	int sum=0;for(int i=0;i<n;++i)add(sum,a[i]/M*M),++f[a[i]%M];
	int ans=1LL*sum*coef%mod;
	for(int i=1;i<=k;++i){
		memset(g,0,sizeof(g));int tot=0;
		for(int j=0;j<M;++j){
			add(tot,1ULL*j*f[j]%mod);
			add(g[j],1ULL*(n-1)*f[j]%mod);
			add(g[j-j%i],f[j]);
		}
		memcpy(f,g,sizeof(f)),add(ans,1LL*tot*ksm(n,k-i)%mod);
	}
	printf("%d\n",ans);
	return 0;
}