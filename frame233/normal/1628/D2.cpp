#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=1000005,mod=1000000007,inv2=(mod+1)/2;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
ll fac[N],inv[N],ifac[N],ipw[N];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int main(){
	init();ipw[0]=1;for(int i=1;i<N;++i)ipw[i]=1LL*ipw[i-1]*inv2%mod;
	int _;read(_);
	while(_--){
		int n,m,k;read(n,m,k);if(n==m){printf("%lld\n",1LL*m*k%mod);continue;}
		int A=0,B=0;
		for(int i=0;i<=m;++i)add(A,C(n,i));
		for(int i=0;i<=m-1;++i)add(B,C(n,i));
		int ans=(1LL*A*m-1LL*B*(n-m))%mod+mod;
		printf("%lld\n",1LL*ans*k%mod*ipw[n]%mod);
	}
	return 0;
}