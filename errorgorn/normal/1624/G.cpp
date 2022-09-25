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
vector<ii> al[200005];
bool vis[200005];

void dfs(int i,int k){
	vis[i]=true;
	
	for (auto &it:al[i]){
		if ((it.se&k)!=it.se || vis[it.fi]) continue;
		dfs(it.fi,k);
	}
}

bool can(int i){
	rep(x,1,n+1) vis[x]=false;
	
	dfs(1,i);
	
	rep(x,1,n+1) if (!vis[x]) return false;
	return true;
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
		rep(x,1,n+1) al[x].clear();
		
		int a,b,c;
		rep(x,0,m){
			cin>>a>>b>>c;
			al[a].pub({b,c});
			al[b].pub({a,c});
		}
		
		int ans=(1<<30)-1;
		rep(x,30,0){
			if (can(ans^(1<<x))) ans^=(1<<x);
		}
		
		cout<<ans<<endl;
	}
}