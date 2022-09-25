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

ll n,k;
ll arr[500005];
ll cnt[500005];

ll p1[500005];
ll p2[500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	k++;
	
	rep(x,0,n) cin>>arr[x];
	sort(arr,arr+n);
	//rep(x,0,n) cout<<arr[x]<<" "; cout<<endl;
	
	rep(x,n,0){
		p1[x]=p1[x+1]+arr[x];
		p2[x]=p2[x+1]+arr[x]*x;
	}
	
	ll ans=p2[0];
	ll curr=0;
	
	int idx=0;
	rep(x,0,n){
		curr+=arr[x]*cnt[idx];
		cnt[idx]++;
		
		ll temp=p2[x+1];
		temp-=p1[x+1]*(x+1);
		//cout<<temp<<endl;
		ans=max(ans,curr+temp+p1[x+1]*cnt[idx]);
		
		
		idx=(idx+1)%k;
	}
	
	cout<<ans<<endl;
}