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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	
	while (TC--){
		ll n,k;
		ll l1,r1;
		ll l2,r2;
		
		cin>>n>>k;
		cin>>l1>>r1;
		cin>>l2>>r2;
		
		ll l=max(l1,l2),r=min(r1,r2);
		
		ll cost=max(l-r,0LL);
		ll range=max(r1,r2)-min(l1,l2)-max(r-l,0LL);
		ll curr=max(r-l,0LL);
		
		//cout<<cost<<" "<<range<<" "<<curr<<endl;
		
		if (curr*n>=k){
			cout<<0<<endl;
			continue;
		}
		
		ll best=1e18;
		rep(x,1,n+1){
			ll inter=curr*n;
			ll tcost=cost*x;
			
			if (inter+range*x>=k){
				best=min(best,tcost+(k-inter));
				continue;
			}
			
			inter+=range*x;
			tcost+=range*x;
			
			best=min(best,tcost+(k-inter)*2);
		}
		
		cout<<best<<endl;
	}
}