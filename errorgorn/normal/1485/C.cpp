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


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	
	while (TC--){
		ll a,b;
		cin>>a>>b;
		
		ll ans=0;
		ll brt=100000;
		rep(x,2,min(brt,b)+1){
			ans+=min((ll)x-1,a/(x+1));
		}
		
		//cout<<ans<<endl;
		
		brt++;
		while (brt<=b){
			ll lo=brt,hi=b+1,mi;
			while (hi-lo>1){
				mi=hi+lo>>1;
				
				if (a/(mi+1)==a/(brt+1)) lo=mi;
				else hi=mi;
			}
			
			//cout<<brt<<" "<<lo<<endl;
			ans+=(lo-brt+1)*(a/(brt+1));
			brt=lo+1;
		}
		
		cout<<ans<<endl;
	}
}