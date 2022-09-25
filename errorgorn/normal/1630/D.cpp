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
int arr[1000005];
int brr[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) cin>>arr[x];
		rep(x,0,m) cin>>brr[x];
		
		int g=0;
		rep(x,0,m) g=__gcd(g,brr[x]);
		
		ll ans0=0,ans1=0;
		rep(x,0,g){
			ll tot=0;
			vector<int> v;
			for (int y=x;y<n;y+=g) tot+=arr[y],v.pub(arr[y]);
			
			ll c0=tot,c1=-1e10*sz(v);
			sort(all(v));
			rep(y,0,sz(v)){
				tot-=2*v[y];
				if (y%2==0) c1=max(c1,tot);
				else c0=max(c0,tot);
			}
			
			ans0+=c0,ans1+=c1;
		}
		
		cout<<max(ans0,ans1)<<endl;
	}
}