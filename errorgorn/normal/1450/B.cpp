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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
vector<ii> arr;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		arr.clear();
		cin>>n>>k;
		
		int a,b;
		rep(x,0,n){
			cin>>a>>b;
			arr.push_back(ii(a,b));
		}
		
		rep(x,0,n){
			rep(y,0,n){
				if (abs(arr[x].fi-arr[y].fi)+abs(arr[x].se-arr[y].se)>k){
					goto bad;
				}
			}
			cout<<1<<endl;
			goto ok;
			bad:;
		}
		cout<<"-1"<<endl;
		ok:;
	}
}