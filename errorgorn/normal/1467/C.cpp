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

int a,b,c;
int arr[300005];
int brr[300005];
int crr[300005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
		
	cin>>a>>b>>c;
	
	ll ans=0;
	rep(x,0,a) cin>>arr[x],ans+=arr[x];
	rep(x,0,b) cin>>brr[x],ans+=brr[x];
	rep(x,0,c) cin>>crr[x],ans+=crr[x];
	
	sort(arr,arr+a);
	sort(brr,brr+b);
	sort(crr,crr+c);
	
	//cout<<ans<<endl;
	
	ll best=min({arr[0]+brr[0],arr[0]+crr[0],brr[0]+crr[0]});
	
	ll curr=0;
	rep(x,0,a) curr+=arr[x];
	best=min(best,curr);
	
	curr=0;
	rep(x,0,b) curr+=brr[x];
	best=min(best,curr);
	
	curr=0;
	rep(x,0,c) curr+=crr[x];
	best=min(best,curr);
	
	cout<<ans-best*2<<endl;
}