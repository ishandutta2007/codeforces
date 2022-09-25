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

const int MOD=1000000007;

int n;
ll arr[500005];
ll bits[65];

ll b[62];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,62) b[x]=(1LL<<x)%MOD;
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		
		memset(bits,0,sizeof(bits));
		
		rep(x,0,n){
			rep(bit,0,60){
				if (arr[x]&(1LL<<bit)) bits[bit]++;
			}
		}
		
		//cout<<(arr[0]&(2))<<" "<<(arr[1]&(2))<<endl;
		//rep(x,0,3) cout<<bits[x]<<" "; cout<<endl;
		
		ll ans=0;
		rep(x,0,n){
			ll v1=0,v2=0;
			
			rep(bit,0,60){
				if (arr[x]&(1LL<<bit)){
					v1=(v1+b[bit]*(bits[bit]))%MOD;
					v2=(v2+b[bit]*n)%MOD;
				}
				else{
					v2=(v2+b[bit]*bits[bit])%MOD;
				}
			}
			
			//cout<<v1<<" "<<v2<<endl;
			ans=(ans+v1*v2)%MOD;
		}
		
		cout<<ans<<endl;
	}
}