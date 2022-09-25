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

const int MOD=1000000007;

int n,k,q;
ll arr[5005];
ll ways[5005][5005];
ll tot[5005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
		
	cin>>n>>k>>q;
	rep(x,1,n+1) cin>>arr[x];
	
	rep(x,1,n+1) ways[0][x]=1;
	
	int a=0,b=1;
	rep(x,0,k){
		rep(y,1,n+1) ways[x+1][y]=(ways[x][y-1]+ways[x][y+1])%MOD;
	}
	
	rep(x,0,k+1){
		rep(y,1,n+1) tot[y]=(tot[y]+ways[x][y]*ways[k-x][y])%MOD;
	}
	
	//rep(x,1,n+1) cout<<tot[x]<<" "; cout<<endl;
	
	ll ans=0;
	
	rep(x,1,n+1) ans=(ans+arr[x]*tot[x])%MOD;
	//cout<<ans<<endl;
	
	while (q--){
		cin>>a>>b;
		ans=(ans+tot[a]*(b-arr[a]))%MOD;
		arr[a]=b;
		
		cout<<(ans+MOD)%MOD<<endl;
	}
}