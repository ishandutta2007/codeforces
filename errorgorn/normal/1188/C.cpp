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

const int MOD=998244353;

int n,k;
int arr[1005];
int p[1005];
int memo[2][1005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	rep(x,1,n+1) cin>>arr[x];
	sort(arr,arr+n+1);
	
	ll ans=0;
	
	rep(x,1,100000){
		if (x*(k-1)>100000) break;
		
		p[0]=0;
		rep(y,1,n+1){
			p[y]=p[y-1];
			while (p[y]<y-1 && arr[p[y]+1]+x<=arr[y]) p[y]++;
		}
		
		memset(memo,0,sizeof(memo));
		
		int a=0,b=1;
		
		memo[a][0]=1;
		rep(zzz,0,k){
			rep(x,1,n+1) memo[a][x]=(memo[a][x]+memo[a][x-1])%MOD;
			
			memo[b][0]=0;
			rep(x,1,n+1) memo[b][x]=memo[a][p[x]];
			
			swap(a,b);
		}
		
		ll tot=0;
		rep(x,1,n+1) tot=(tot+memo[a][x])%MOD;
		
		//cout<<x<<" "<<tot<<endl;
		ans=(ans+tot)%MOD;
	}
	
	cout<<ans<<endl;
}