// Super Idol
//    
//  
//    
//  105C
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

int n;
int arr[105];
int brr[105];
int tot[105];

int memo[2][10005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) cin>>brr[x];
		rep(x,1,n+1) tot[x]=tot[x-1]+arr[x]+brr[x];
		
		memset(memo,1,sizeof(memo));
		int a=0,b=1;
		memo[a][0]=0;
		
		rep(x,1,n+1){
			memset(memo[b],1,sizeof(memo[b]));
			
			rep(y,0,10005) if (memo[a][y]<=1e15){
				memo[b][y+arr[x]]=min(memo[b][y+arr[x]],memo[a][y]+arr[x]*y+brr[x]*(tot[x-1]-y));
				memo[b][y+brr[x]]=min(memo[b][y+brr[x]],memo[a][y]+brr[x]*y+arr[x]*(tot[x-1]-y));
			}
			
			swap(a,b);
		}
		
		int ans=1e15;
		rep(x,0,10005) ans=min(ans,memo[a][x]);
		
		ans*=2;
		rep(x,1,n+1) ans+=(n-1)*(arr[x]*arr[x]+brr[x]*brr[x]);
		
		cout<<ans<<endl;
	}
}