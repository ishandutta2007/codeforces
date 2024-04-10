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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

ll n,k;
ii arr[100005];

ll ss[100005];
ll pref[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>k;
		
		rep(x,0,k){
			cin>>arr[x].fi>>arr[x].se;
			ss[x]=arr[x].fi;
		}
		
		sort(ss,ss+k);
		rep(x,0,k) pref[x+1]=pref[x]+ss[x];
		
		ll ans=0;
		
		rep(x,0,k){
			auto it=upper_bound(ss,ss+k,arr[x].se);
			
			ll bigger=MIN(n,k-(it-ss));
			
			//cout<<bigger<<endl;
			
			ll curr=arr[x].se*(n-bigger)+pref[k]-pref[k-bigger];
			
			if (arr[x].fi<arr[x].se){
				curr-=arr[x].se;
				curr+=arr[x].fi;
			}
			
			ans=max(ans,curr);
			//cout<<curr<<endl;
		}
		
		cout<<ans<<endl;
	}
}