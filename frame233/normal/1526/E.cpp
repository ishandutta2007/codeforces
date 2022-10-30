#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=400005,mod=998244353;
typedef long long ll;
int sa[N],rk[N];
ll fac[N],inv[N],ifac[N];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int main(){
	init();
	int n,k;read(n,k);
	for(int i=1;i<=n;++i)read(sa[i]),rk[++sa[i]]=i;
	int cnt=0;for(int i=1;i<n;++i)cnt+=rk[sa[i]+1]<rk[sa[i+1]+1];
	printf("%lld\n",C(k+cnt,n));
	return 0;
}