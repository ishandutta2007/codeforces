// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[500005];
int id[500005];

vector<int> pos[500005];
int dp[500005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	rep(x,1,n+1) pos[arr[x]].pub(x);
	
	rep(x,1,n+1) rep(y,0,sz(pos[x])) id[pos[x][y]]=y;
	
	rep(x,1,n+1){
		dp[x]=dp[x-1];
		if (sz(pos[arr[x]])==id[x]+1) dp[x]=max(dp[x],dp[pos[arr[x]][0]-1]+sz(pos[arr[x]]));
	}
	
	//rep(x,1,n+1) cout<<dp[x]<<" "; cout<<endl;
	
	int ans=0;
	rep(x,1,n+1) ans=max(ans,dp[x-1]+sz(pos[arr[x]])-id[x]);
	
	cout<<n-ans<<endl;
}