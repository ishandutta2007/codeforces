//
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

int n,q;
int arr[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n) arr[x]=abs(arr[x+1]-arr[x]);
	
	int a,b;
	while (q--){
		cin>>a>>b;
		b--;
		
		//rep(x,a,b+1) cout<<arr[x]<<" "; cout<<endl;
		
		vector<ii> stk={{1e18,a-1}};
		int ans=0;
		rep(x,a,b+1){
			while (!stk.empty() && stk.back().fi<=arr[x]){
				ii temp=stk.back(); stk.pob();
				ans+=(x-temp.se)*(temp.se-stk.back().se)*temp.fi;
			}
			stk.pub({arr[x],x});
		}
		while (sz(stk)>=2){
			ii temp=stk.back(); stk.pob();
			ans+=(b+1-temp.se)*(temp.se-stk.back().se)*temp.fi;
		}
		
		cout<<ans<<endl;
	}
}