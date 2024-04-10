//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int TC;
int n,m;
vector<ii> al[200005];
vector<ii> al2[200005];

bool vis[200005];
int state[200005];

int glob;
int cc;

void dfs(int i){
	vis[i]=true;
	cc++;
	if (state[i]) glob++;
	
	for (auto &it:al[i]){
		int val=state[i]^it.se;
		
		if (vis[it.fi]){
			if (state[it.fi]!=val) glob-=1e9;
		}
		else{
			state[it.fi]=val;
			dfs(it.fi);
		}
	}
	for (auto &it:al2[i]){
		int val=(state[i]!=it.se);
		
		if (vis[it.fi]){
			if (state[it.fi]!=val) glob-=1e9;
		}
		else{
			state[it.fi]=val;
			dfs(it.fi);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		
		cin>>n>>m;
		
		rep(x,1,n+1){
			al[x].clear();
			al2[x].clear();
			vis[x]=false;
			state[x]=0;
		}
		
		int a,b;
		string s;
		rep(x,0,m){
			cin>>a>>b>>s;
			
			if (s=="crewmate"){
				al[a].pub(ii(b,0));
				al2[b].pub(ii(a,0));
			}
			else{
				al[a].pub(ii(b,1));
				al2[b].pub(ii(a,1));
			}
		}
		
		ll ans=0;
		rep(x,1,n+1) if (!vis[x]){
			cc=0; glob=0;
			dfs(x);
			
			if (glob<0) ans+=glob;
			else ans+=max(glob,cc-glob);
		}
		
		if (ans<0) cout<<"-1"<<endl;
		else cout<<ans<<endl;
	}
}