#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch=getchar();bool f=false;while(!isdigit(ch))f|=ch=='-',ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=300005,mod=998244353;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a<b?a+mod-b:a-b;}
ll fac[N],inv[N],ifac[N];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int f[N],g[N],pw[N];
void MAIN(){
	int n;read(n);int ans=0;
	for(int i=0;4*i<=n;++i){
		int tmp=1LL*pw[i]*C(n-2*i,i*2)%mod*g[n-4*i]%mod*f[2*i]%mod;
		add(ans,tmp);
	}
	printf("%d\n",ans);
}
int main(){
	init();
	pw[0]=1;for(int i=1;i<N;++i)pw[i]=2LL*pw[i-1]%mod;
	f[0]=1;for(int i=2;i<N;++i)f[i]=1LL*(i-1)*f[i-2]%mod;
	g[0]=1,g[1]=1;for(int i=2;i<N;++i)g[i]=(g[i-1]+1LL*g[i-2]*(i-1))%mod;
	int _;read(_);
	while(_--)MAIN();
	return 0;
}