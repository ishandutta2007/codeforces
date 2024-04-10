#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head 
const int N=5005;
int n,vis[N*2];
ll ans;
VI a,e[N];

void dfs(int u) {
	vis[u]=1; a.pb(u);
	for (auto v:e[u]) if (!vis[v]) {
		dfs(v);	
	}
}
int main() {
	scanf("%d",&n);
	rep(i,1,2*n+1) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v),e[v].pb(u);
	}
	rep(i,1,n+1) if (!vis[i]) {
		a.clear();
		dfs(i);
		
		int m=SZ(a);
		// rep(i,0,m) printf("%d ",a[i]);puts("");
		int lm=inf,lM=-1,rm=inf,rM=-1;
		rep(i,0,m) {
			if (a[i]<=n) lm=min(lm,a[i]),lM=max(lM,a[i]);
			else rm=min(rm,a[i]),rM=max(rM,a[i]);
		}
		ans+=1ll*m/2*lm*(n-lM+1)*(rm-n)*(2*n-rM+1);
		// debug(ans);
		
		rep(i,0,m) {
			int s=a[i],pr=a[(i-1+m)%m];
			int Ml=-1,ml=inf,Mr=-1,mr=inf;
			// x -> nx , not pr
			rep(j,0,m) {
				int x=a[(i+j)%m];
				// bug(x);
				if (x<=n) Ml=max(Ml,x),ml=min(ml,x);
				else Mr=max(Mr,x),mr=min(mr,x);
				
				if (j&1) {
					// bug(s),bug(pr),bug(ml),bug(Ml),bug(mr),debug(Mr);
					if (s<=n) {
						if (pr<mr) {
							ans+=1ll*(n-Ml+1)*ml*(mr-pr)*(2*n-Mr+1);
						}
						if (Mr<pr) {
							ans+=1ll*(n-Ml+1)*ml*(mr-n)*(pr-Mr);
						}
					}else {
						if (pr<ml) {
							ans+=1ll*(mr-n)*(2*n-Mr+1)*(ml-pr)*(n-Ml+1);
						}
						if (Ml<pr) {
							ans+=1ll*(mr-n)*(2*n-Mr+1)*ml*(pr-Ml);
						}
					}
				}
			}
			// puts("");
		}
	}
	printf("%lld\n",ans);
		
	return 0;
}