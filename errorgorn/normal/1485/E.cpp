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
#define debug(x) cout << #x << " is " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
vector<int> al[200005];
ll w[200005];
ll cost1[200005];
ll cost2[200005];

vector<int> layer[200005];

int d;
void dfs(int i,int depth){
	d=max(d,depth);
	layer[depth].pub(i);
	
	for (auto &it:al[i]){
		dfs(it,depth+1);
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
		cin>>n;
		rep(x,0,n+5) layer[x].clear();
		rep(x,0,n+5) al[x].clear();
		
		rep(x,2,n+1){
			int t;
			cin>>t;
			al[t].pub(x);
		}
		rep(x,2,n+1) cin>>w[x];
		
		d=0;
		dfs(1,0);
		
		rep(x,d+1,1){
			sort(all(layer[x]),[](int i,int j){
				return w[i]<w[j];
			});
			
			//for (auto &it:layer[x]) cout<<it<<" "; cout<<endl;
			
			for (auto &it:layer[x]){
				cost1[it]=0;
				for (auto &it2:al[it]) cost1[it]=max(cost1[it],cost2[it2]);
			}
			
			multiset<ll,greater<ll> > lower={(ll)-1e18},upper={(ll)-1e18};
			
			for (auto &it:layer[x]){
				upper.insert(cost1[it]+w[it]);
			}
			
			for (auto &it:layer[x]){
				cost2[it]=max(*lower.begin()+w[it],*upper.begin()-w[it]);
				
				lower.insert(cost1[it]-w[it]);
				upper.erase(upper.find(cost1[it]+w[it]));
			}
			
			for (auto &it:layer[x]){
				cost2[it]=max(cost2[it],cost1[it]
					+max(w[it]-w[layer[x].front()],w[layer[x].back()]-w[it]));
			}
		}
		
		ll ans=0;
		for (auto &it:al[1]) ans=max(ans,cost2[it]);
		
		//rep(x,2,n+1) cout<<cost2[x]<<" "; cout<<endl;
		cout<<ans<<endl;
	}
}