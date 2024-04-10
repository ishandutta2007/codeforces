#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m,w[N];
ll K,a[N],g,p[N],c[N],dp[13][1<<12];
map<ll,vector<int> > mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>K;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		g=__gcd(g,a[i]);
	}
	if(g==1){
		cout<<0<<'\n';return 0;
	}
	for(int i=1;i<=n;++i){
		cin>>w[i];
	}
	for(ll i=2;i*i<=g;++i){
		if(g%i==0){
			p[m++]=i;
			while(g%i==0)g/=i;	
		}
	}
	if(g>1)p[m++]=g;
	for(int i=1;i<=n;++i){
		c[i]=1;
		for(int j=0;j<m;++j){
			while(a[i]%p[j]==0){
				c[i]*=p[j],a[i]/=p[j];	
			}	
		}
		mp[c[i]].push_back(w[i]);
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(auto [jb,W]:mp){
		static bool ok[1<<12];
		static ll pw[12];
		ll tmp=jb;
		for(int i=0;i<m;++i){
			pw[i]=1;
			while(tmp%p[i]==0)tmp/=p[i],pw[i]*=p[i];	
		}
		for(int s=0;s<(1<<m);++s){
			ll tmp=1;
			for(int i=0;i<m;++i){
				if(s>>i&1){
					tmp*=pw[i];
				}
			}
			ok[s]=tmp<=K;
		}
		sort(W.begin(),W.end());
		for(auto w:W){
			bool tr=false;
			for(int i=m-1;i>=0;--i){
				for(int s=0;s<(1<<m);++s){
					if(dp[i][s]<inf){
						for(int t=(s+1)|s;t<(1<<m);t=(t+1)|s){
							if(ok[s^t]&&dp[i][s]+w<dp[i+1][t]){
								dp[i+1][t]=dp[i][s]+w;
								tr=true;	
							}	
						}	
					}
				}
			}
			if(!tr)break;
		}
	}
	ll ans=inf;
	for(int i=1;i<=m;++i){
		if(dp[i][(1<<m)-1]<inf)ans=min(ans,dp[i][(1<<m)-1]*i);
	}
	cout<<(ans==inf?-1:ans)<<'\n';
	return 0;
}