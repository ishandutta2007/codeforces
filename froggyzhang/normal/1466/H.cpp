#include<bits/stdc++.h>
using namespace std;
#define N 66
#define M 2333333
const int mod=1e9+7;
typedef long long ll;
int n,p[N],cnt[N];
int C[N][N],dp[M],fac[N],tr[N][N],siz[M];
void init(int n){
	C[0][0]=fac[0]=1;
	for(int i=1;i<=n;++i){
		C[i][0]=1;
		fac[i]=1LL*fac[i-1]*i%mod;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	for(int i=0;i<n;++i){
		tr[i][0]=1;
		int w=0;
		for(int j=0;j<=i;++j){
			w=(w+1LL*fac[j]*C[i][j]%mod*fac[n-j-1])%mod;
		}
		for(int j=1;j<=n;++j){
			tr[i][j]=1LL*tr[i][j-1]*w%mod;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	init(n);
	for(int i=1;i<=n;++i){
		cin>>p[i];
	}
	for(int i=1;i<=n;++i){
		static int vis[N];
		int sz=0;
		if(vis[i])continue;
		for(int u=i;!vis[u];u=p[u]){
			vis[u]=1,++sz;
		}
		++cnt[sz];
	}
	static int jb[N];
	jb[0]=1;
	for(int i=1;i<=n;++i){
		jb[i]=jb[i-1]*(cnt[i]+1);	
	}
	dp[0]=1;
	for(int S=1;S<jb[n];++S){
		static int q[M],w[M],tot;
		q[tot=1]=0,w[tot=1]=mod-1;
		for(int i=1;i<=n;++i){
			int las=tot;
			int d=(S/jb[i-1])%(cnt[i]+1);
			siz[S]+=d*i;
			for(int j=1;j<=d;++j){
				for(int k=1;k<=las;++k){
					++tot;
					q[tot]=q[k]+j*jb[i-1];
					w[tot]=1LL*(j&1?mod-w[k]:w[k])*C[d][j]%mod;
				}
			}
		}
		for(int i=2;i<=tot;++i){
			dp[S]=(dp[S]+1LL*dp[S-q[i]]*w[i]%mod*tr[siz[S]-siz[q[i]]][siz[q[i]]])%mod;	
		}
	}
	cout<<dp[jb[n]-1]<<'\n';
	return 0;
}