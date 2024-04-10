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
#define iii pair<ll,ii>
#define fi first
#define se second
//#define endl '\n'
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

const int MOD=1000000007;

int n;

int memo[1005][1005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int a,b;
	
	rep(x,0,n){
		cin>>a>>b;
		
		memset(memo,0,sizeof(memo));
		
		memo[b][1]=1;
		
		bool f=true;
		rep(x,b+1,1){
			if (f) rep(y,1,a+1){
				memo[x][y+1]=(memo[x][y+1]+memo[x][y])%MOD;
				memo[x-1][y-1]=(memo[x-1][y-1]+memo[x][y])%MOD;
			}
			else rep(y,a+1,1){
				memo[x][y-1]=(memo[x][y-1]+memo[x][y])%MOD;
				memo[x-1][y+1]=(memo[x-1][y+1]+memo[x][y])%MOD;
			}
			
			f^=true;
		}
		
		// rep(x,b+1,1){
			// rep(y,1,a+1) cout<<memo[x][y]<<" ";
			// cout<<endl;
		// }
		
		ll ans=0;
		rep(x,1,b+1) ans=(ans+memo[x][a])%MOD;
		rep(x,1,b+1) ans=(ans+memo[x][0])%MOD;
		cout<<ans<<endl;
	}
}