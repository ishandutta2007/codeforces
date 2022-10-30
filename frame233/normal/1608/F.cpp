#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=2005,mod=998244353;typedef long long ll;
template<typename _Tp1,typename _Tp2>inline void add(_Tp1 &a,_Tp2 b){a=a+b>=mod?a+b-mod:a+b;}
template<typename _Tp1,typename _Tp2>inline void sub(_Tp1 &a,_Tp2 b){a=a-b<0?a-b+mod:a-b;}
ll ksm(ll a,ll b=mod-2){ll res=1;while(b){if(b&1)res=res*a%mod;a=a*a%mod,b>>=1;}return res;}
int b[N],dp[105][N],g[105][N],f[105][N];
ll fac[N],inv[N],ifac[N];
void init(){fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;for(int i=2;i<N;++i)fac[i]=fac[i-1]*i%mod,inv[i]=inv[mod%i]*(mod-mod/i)%mod,ifac[i]=ifac[i-1]*inv[i]%mod;}
inline ll C(int n,int m){return n<m||m<0?0:fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int main(){
	init();int n,L;read(n,L);for(int i=1;i<=n;++i)read(b[i]);
	dp[L][0]=1;
	for(int i=0;i<n;++i){
		memset(g,0,sizeof(g));
		for(int j=0;j<=L+L;++j){
			int v=b[i]+j-L;
			if(b[i+1]-L<=v&&v<=b[i+1]+L){
				for(int k=0;k<=i;++k)add(g[v-b[i+1]+L][k],1LL*(v+k)*dp[j][k]%mod);
				for(int k=0;k<=i;++k)add(g[v-b[i+1]+L][k+1],dp[j][k]);
			}
		}
		memset(f,0,sizeof(f));
		for(int j=0;j<=L+L;++j)for(int k=0;k<=i;++k){
			int tmp=std::max(1,-(j+b[i]-b[i+1]));
			if(j+b[i]-b[i+1]+tmp<=L+L&&tmp-1<=k)add(f[j+b[i]-b[i+1]+tmp][k-tmp+1],1LL*dp[j][k]*fac[k]%mod*ifac[k-tmp+1]%mod);
		}
		for(int j=1;j<=L+L;++j)for(int k=0;k<=i;++k)add(f[j][k],1LL*f[j-1][k+1]*(k+1)%mod);
		for(int j=0;j<=L+L;++j)for(int k=0;k<=i+1;++k)add(g[j][k],f[j][k]);
		memcpy(dp,g,sizeof(dp));
	}
	int ans=0;
	for(int i=0;i<=L+L;++i){
		int v=b[n]+i-L;if(v>n)continue;
		v=n-v;for(int j=0;j<=v;++j)add(ans,1LL*dp[i][j]*fac[v]%mod*ifac[v-j]%mod);
	}
	printf("%d\n",ans);
	return 0;
}