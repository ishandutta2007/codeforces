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
int arr[1005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	int ans=0;
	rep(x,1,n+1) rep(y,x+1,n+1) if (x%2==1 && y%2==0){
		int mn=0;
		int curr=0;
		rep(z,x+1,y){
			if (z%2==0) curr-=arr[z];
			else curr+=arr[z];
			mn=min(mn,curr);
		}
		
		int l=arr[x],r=arr[y];
		
		if (curr>0) r-=curr;
		else l+=curr,mn-=curr;
		
		l+=mn,r+=mn;
		
		if (x+1!=y) l++,r++;
		ans+=max(0LL,min(l,r));
	}
	
	cout<<ans<<endl;
}