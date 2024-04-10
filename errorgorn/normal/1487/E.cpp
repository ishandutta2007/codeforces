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

int arr[4];
vector<ll> cost[4];

vector<int> links[3][150005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,4) cin>>arr[x];
	rep(x,0,4){
		rep(y,0,arr[x]){
			int t;
			cin>>t;
			cost[x].pub(t);
		}
	}
	
	rep(x,0,3){
		int t;
		cin>>t;
		
		int a,b;
		rep(y,0,t){
			cin>>a>>b;
			a--,b--;
			links[x][b].pub(a);
		}
	}
	
	rep(x,0,3){
		multiset<ll> s={(ll)1e18};
		
		rep(y,0,arr[x]) s.insert(cost[x][y]);
		
		rep(y,0,arr[x+1]){
			for (auto &it:links[x][y]) s.erase(s.find(cost[x][it]));
			cost[x+1][y]+=*s.begin();
			for (auto &it:links[x][y]) s.insert(cost[x][it]);
		}
	}
	
	ll mn=1e18;
	rep(x,0,arr[3]) mn=min(mn,cost[3][x]);
	
	if (mn==1e18) cout<<"-1"<<endl;
	else cout<<mn<<endl;
}