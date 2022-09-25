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

ll n,r1,r2,r3,d;
ll arr[1000005];
ll memo[1000005];
ll memob[1000005]; //back memo

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>r1>>r2>>r3>>d;
	rep(x,1,n+1) cin>>arr[x];
	
	r1=min(r1,r3); //too OP
	
	//cout<<0<<" "<<memo[0]<<endl;
	rep(x,1,n+1){
		memo[x]=memo[x-1]+min({arr[x]*r1+r3,r2+r1+2*d,(arr[x]+2)*r1+2*d});
		if (x!=1){
			memo[x]=min(memo[x],memo[x-2]+min(r2+r1,(arr[x-1]+2)*r1)+min(r2+r1,(arr[x]+2)*r1)+2*d);
		}
		
		//cout<<x<<" "<<memo[x]<<endl;
	}
	
	memob[n]=min({arr[n]*r1+r3,r2+r1+2*d,(arr[n]+2)*r1+2*d});
	rep(x,n,1){
		memob[x]=memob[x+1]+min({arr[x]*r1+r3,r2+r1,(arr[x]+2)*r1})+d;
	}
	
	ll ans=1e18;
	rep(x,0,n+1) ans=min(ans,memo[x]+memob[x+1]);
	
	cout<<ans+(n-1)*d<<endl; //add travel time
}