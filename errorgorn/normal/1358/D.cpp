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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

ll n,k;
ll arr[400005];
ll pre[400005];
ll presq[400005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	rep(x,1,n+1){
		cin>>arr[x];
		arr[x+n]=arr[x];
	}
	
	rep(x,1,2*n+1){
		pre[x]=pre[x-1]+arr[x];
		presq[x]=presq[x-1]+arr[x]*(arr[x]+1)/2;
	}
	
	ll ans=0;
	
	int l=0,r=1;
	while (r<=2*n){
		while (pre[r]-pre[l]>=k) l++;
		
		//cout<<l<<" "<<r<<endl;
		
		ll extra=pre[r]-pre[l-1]-k;
		if (l) ans=max(ans,presq[r]-presq[l-1]-extra*(extra+1)/2);
		
		r++;
	}
	
	cout<<ans<<endl;
}