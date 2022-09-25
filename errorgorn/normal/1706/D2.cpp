//
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

int n,k;
int arr[100005];
vector<ii> al[100005];
int curr[100005];
int cnt[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		rep(x,0,100005) cnt[x]=0;
		
		cin>>n>>k;
		rep(x,1,n+1){
			cin>>arr[x];
			al[arr[x]].pub({x,1});
			curr[x]=arr[x];
			cnt[arr[x]]++;
		}
		
		int mx=100004;
		int ans=1e9;
		rep(x,100004,1){
			for (auto [a,b]:al[x]){
				cnt[curr[a]]--;
				curr[a]=x;
				cnt[curr[a]]++;
				
				if (b==k || arr[a]/k==x) continue;
				
				if (b==-1 || arr[a]/(b+1)==arr[a]/b) al[x-1].pub({a,-1});
				else al[arr[a]/(b+1)].pub({a,b+1});
			}
			al[x].clear();
			al[x].shrink_to_fit();
			
			while (cnt[mx]==0) mx--;
			
			if (x<=arr[1]) ans=min(ans,mx-x);
		}
		
		cout<<ans<<endl;
	}
}