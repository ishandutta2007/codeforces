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
ii arr[5005];
bool used[5005];
vector<int> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;	
	
	rep(x,0,n) cin>>arr[x].fi>>arr[x].se;
	
	used[0]=true;
	ans.pub(0);
	
	rep(x,1,n){
		int idx=-1;
		ll best=0;
		
		rep(y,0,n) if (!used[y]){
			ll temp=(arr[y].fi-arr[ans.back()].fi)*(arr[y].fi-arr[ans.back()].fi)+
					(arr[y].se-arr[ans.back()].se)*(arr[y].se-arr[ans.back()].se);
					
			if (best<temp){
				best=temp;
				idx=y;
			}
		}
		
		ans.pub(idx);
		used[idx]=true;
	}
	
	for (auto &it:ans) cout<<it+1<<" "; cout<<endl;
}