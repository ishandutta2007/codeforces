//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
int arr[100005];
vector<ii> edges;
int deg[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		edges.clear();
		
		cin>>n>>m;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) deg[x]=0;
		
		int a,b;
		rep(x,0,m){
			cin>>a>>b;
			edges.pub({a,b});
			deg[a]++,deg[b]++;
		}
		
		int ans=1e9;
		if (m%2==0) ans=0;
		rep(x,1,n+1) if (deg[x]%2==1) ans=min(ans,arr[x]);
		for (auto [a,b]:edges) ans=min(ans,arr[a]+arr[b]);
		
		cout<<ans<<endl;
	}
}