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
ll arr[1005][1005];
ll sum[1005];
ll sqsum[1005]; 

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>m>>n;
	rep(x,0,n) rep(y,0,m) cin>>arr[x][y];
	
	rep(x,0,n) rep(y,0,m) sum[x]+=arr[x][y],sqsum[x]+=arr[x][y]*arr[x][y];
	
	// rep(x,0,n){
		// cout<<sum[x]<<" "<<sqsum[x]<<endl;
	// }
	
	int idx=-1;
	rep(x,1,n-1) if (sum[x]!=sum[0]+(sum[n-1]-sum[0])/(n-1)*x){
		idx=x;
		break;
	}
	
	int ans;
	
	if (idx>=3){
		ll d1=(sqsum[idx-3]-sqsum[idx-1]),d2=(sqsum[idx-2]-sqsum[idx-1]);
		ll av=d1/4-d2;
		ll v2=d2+2*av;
		ll delta=sqsum[idx]-(sqsum[idx-1]+2*av+v2);
		ll dv=(sum[idx]-sum[idx-1])-(sum[idx-1]-sum[idx-2]);
		
		rep(x,1,1000005){
			if (delta==x*x-(x-dv)*(x-dv)) ans=x-dv;
		}
	}
	else{
		ll d1=(sqsum[idx+3]-sqsum[idx+1]),d2=(sqsum[idx+2]-sqsum[idx+1]);
		ll av=d2-d1/4;
		ll v2=d2-2*av;
		ll delta=sqsum[idx]-(sqsum[idx+1]-2*av+v2);
		ll dv=(sum[idx]-sum[idx+1])-(sum[idx+1]-sum[idx+2]);
		
		rep(x,1,1000005){
			if (delta==x*x-(x-dv)*(x-dv)) ans=x-dv;
		}
	}
	
	cout<<idx<<" "<<ans<<endl;
}