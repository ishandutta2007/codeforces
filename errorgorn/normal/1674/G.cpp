// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
vector<int> al[200005];
int in[200005];
int out[200005];

bool vis[200005];
vector<int> topo;
void dfs(int i){
	vis[i]=true;
	for (auto it:al[i]) if (!vis[it]) dfs(it);
	topo.pub(i);
}

int memo[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		al[a].pub(b);
		out[a]++;
		in[b]++;
	}
	
	rep(x,1,n+1) if (!vis[x]) dfs(x);
	
	reverse(all(topo));
	
	int ans=0;
	for (auto it:topo){
		memo[it]=max(memo[it],1LL);
		ans=max(ans,memo[it]);
		for (auto it2:al[it]){
			if (out[it]>1 && in[it2]>1) memo[it2]=max(memo[it2],memo[it]+1);
		}
	}
	
	cout<<ans<<endl;
}