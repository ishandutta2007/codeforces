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

int arr[3][3];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,3){
		rep(y,0,2) cin>>arr[x][y];
	}
	
	vector<int> v1;
	vector<int> v2;
	
	rep(x,0,3){
		v1.pub(arr[x][0]);
		v2.pub(arr[x][1]);
	}
	
	sort(all(v1));
	sort(all(v2));
	
	vector<tuple<int,int,int,int> > ans;
	ans.pub({v1[1],v2[0],v1[1],v2[2]});
	if (v1[0]!=v1[1]){
		rep(x,0,3) if (arr[x][0]==v1[0]){
			ans.pub({arr[x][0],arr[x][1],v1[1],arr[x][1]});
		}
	}
	if (v1[2]!=v1[1]){
		rep(x,0,3) if (arr[x][0]==v1[2]){
			ans.pub({v1[1],arr[x][1],arr[x][0],arr[x][1]});
		}
	}
	
	cout<<sz(ans)<<endl;
	for (auto [a,b,c,d]:ans) cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
}