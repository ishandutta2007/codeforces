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

int n;
ii arr[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>arr[x].fi>>arr[x].se;
		arr[n].fi=1e10;
		
		ll goal=0;
		ll pos=0;
		ll pt=0;
		
		int ans=0;
		rep(x,0,n){
			ll npos;
			if (pos==goal) goal=arr[x].se;
			
			if (pos<goal){
				npos=min(goal,pos+arr[x+1].fi-arr[x].fi);
			}
			else if (pos==goal){
				npos=pos;
			}
			else{
				npos=max(goal,pos-arr[x+1].fi+arr[x].fi);
			}
			
			if (min(pos,npos)<=arr[x].se && arr[x].se<=max(pos,npos)) ans++;
			
			pos=npos;
		}
		
		cout<<ans<<endl;
	}
}