#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005,mod=1000000007;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){(a+=b)>=mod&&(a-=mod);}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){(a-=b)<0&&(a+=mod);}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
ll fac[N],inv[N],ifac[N];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int f[N];std::map<int,int> mp;int cnt[N],pw[N];
int main(){
	init();
	int n,k;read(n,k);
	for(int i=0;i<=n;++i)pw[i]=ksm(k-1,i);
	f[0]=0;for(int i=0;i<n;++i)f[i+1]=(1LL*(k-1)*i%mod*f[i]%mod+1)*inv[n-i]%mod;
	for(int i=1;i<=n;++i)add(f[i],f[i-1]);
	int a=0,s=0;for(int i=1,x;i<=n;++i){read(x);if(x!=-1)++mp[x];else ++a;}
	for(auto it:mp)++cnt[it.second];
	cnt[0]+=k-mp.size();
	for(int i=0;i<=n;++i)if(cnt[i]){
		int tmp=0;for(int j=0;j<=a;++j)add(tmp,1LL*f[i+j]*C(a,j)%mod*pw[a-j]%mod);
		add(s,1LL*tmp*cnt[i]%mod);
	}
	s=ksm(k,mod-1-a)*s%mod;
	printf("%lld\n",1LL*(f[n]-s+mod)*n%mod);
	return 0;
}