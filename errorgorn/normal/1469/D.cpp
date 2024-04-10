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

int n;
vector<ii> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		vector<int> v;
		if (2<=n) v.push_back(2);
		if (4<=n) v.push_back(4);
		if (16<=n) v.push_back(16);
		if (256<=n) v.push_back(256);
		if (65536<=n) v.push_back(65536);
		if (v.back()!=n) v.push_back(n);
		
		ans.clear();
		rep(x,2,n+1) if (!count(all(v),x)){
			ans.push_back(ii(x,n));
		}
		
		rep(x,sz(v)-1,0){
			ans.push_back(ii(v[x+1],v[x]));
			ans.push_back(ii(v[x+1],v[x]));
		}
		
		cout<<sz(ans)<<endl;
		for (auto &it:ans) cout<<it.fi<<" "<<it.se<<endl;
	}
}