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
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
ll arr[200005];

ll ps1[200005];
ll ps2[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	rep(tc,0,TC){
		cin>>n;
		rep(x,0,n) cin>>arr[x];
		
		if (tc==1000000){
			cout<<n<<endl;
			rep(x,0,n) cout<<arr[x]<<" "; cout<<endl;
			return 0;
		}
		
		indexed_set s[2];
		ll g[2]={0,0};
		
		ps1[n]=ps2[n]=0;
		ps1[n-1]=-arr[n-1];
		ps2[n-1]=arr[n-1];
		rep(x,n-1,0){
			ps1[x]=ps1[x+1]+arr[x];
			ps2[x]=ps2[x+1]+arr[x];
		}
		
		ll s1=0,s2=0;
		ll ans=0;
		
		if (ps1[0]>0) ans++;
		if (ps2[0]>0) ans++;
		
		rep(x,0,n){
			if (x>=2){
				g[x%2]+=arr[x-1];
				g[x%2]-=arr[x];
			}
			
			ll t1=ps1[x+1];
			ll t2=ps2[x+1];
			
			if (x==0) s1+=arr[x];
			else s1-=arr[x];
			s2-=arr[x];
			
			if (x!=0) s[x%2].insert(s1-g[x%2]);
			s[x%2].insert(s2-g[x%2]);
			
			//t1+s[x%2]+g[x%2]>0
			//s[x%2]> -g[x%2]-t1
			
			if (x<n-3) ans+=sz(s[x%2])-s[x%2].order_of_key(-g[x%2]-t1+1);
			ans+=sz(s[x%2])-s[x%2].order_of_key(-g[x%2]-t2+1);
			
			//for (auto &it:s[x%2]) cout<<it+g[x%2]<<" "; cout<<endl;
			//cout<<t1<<" "<<t2<<" "<<endl;
			//debug(ans);
			//cout<<endl;
		}
		
		if (n==2){
			if (arr[0]>arr[1]) ans--;
		}
		if (n>3){
			ll tot=0;
			rep(x,0,n-1) tot+=arr[x];
			tot-=arr[n-1];
			
			rep(x,n-1,2){
				tot-=2*arr[x];
				if (tot>0) ans++;
			}
		}
		
		cout<<(ans)%998244353<<endl;
		
	}
}