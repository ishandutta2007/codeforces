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
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
ll arr[105];
bitset<200005> b;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	ll tot=0;
	rep(x,0,n){
		tot+=arr[x];
	}
	
	b[0]=1;
	rep(x,0,n){
		b=b|(b<<arr[x]);
	}
	
	if (tot%2==1 || !b[tot/2]){
		cout<<"0"<<endl;
		return 0;
	}
	
	ll g=0;
	rep(x,0,n) g=__gcd(g,arr[x]);
	rep(x,0,n) arr[x]/=g;
	
	rep(x,0,n){
		if (arr[x]&1){
			cout<<1<<endl<<x+1<<endl;
			return 0;
		}
	}
}