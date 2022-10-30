#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return !b?a:gcd(b,a%b);}
const int N=1000005,mod=998244353;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
ll fac[N],inv[N],ifac[N];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
bool pr[N];int p[N],pos,phi[N];
void sieve(){
	phi[1]=1;
	for(int i=2;i<N;++i){
		if(!pr[i])p[++pos]=i,phi[i]=i-1;
		for(int j=1;j<=pos&&i*p[j]<N;++j){
			pr[i*p[j]]=1;
			if(i%p[j]==0){
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
			phi[i*p[j]]=phi[i]*(p[j]-1);
		}
	}
}
int a[N],cnt[N];
void MAIN(){
	int n;read(n);memset(cnt,0,(n+3)<<2);
	for(int i=1;i<=n;++i)read(a[i]),++cnt[a[i]];
	bool flag=1;for(int i=2;i<=n;++i)flag&=a[1]==a[i];
	if(flag)return puts("1"),void();
	int l=n;for(int i=1;i<=n;++i)l=gcd(l,cnt[i]);
	int A=0,B=0;
	for(int g=1;g<=l;++g)if(l%g==0){
		ll coef=fac[n/g];
		for(int i=1;i<=n;++i)if(cnt[i])coef=1LL*coef*ifac[cnt[i]/g]%mod;
		add(A,1LL*phi[g]%mod*coef%mod),coef=1LL*coef*ifac[n/g]%mod*fac[n/g-2]%mod;
		int tmp=0;for(int i=1;i<=n;++i)if(cnt[i]>=2*g)add(tmp,1LL*fac[cnt[i]/g]*ifac[cnt[i]/g-2]%mod);
		add(B,1LL*phi[g]*tmp%mod*coef%mod);
	}
	int cnt=1LL*A*inv[n]%mod;
	printf("%lld\n",1LL*(A-B+mod)%mod*ksm(cnt)%mod);
}
int main(){
	sieve(),init();int _;read(_);
	while(_--)MAIN();
	return 0;
}