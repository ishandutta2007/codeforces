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
#define iii pair<ll,ii>
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

ll fr[6];
int n;
ll arr[100005];

priority_queue<iii,vector<iii>,greater<iii> > pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,6) cin>>fr[x];
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	sort(fr,fr+6);
	
	ll mx=0;
	rep(x,0,n){
		pq.push(iii(arr[x]-fr[5],ii(x,5)));
		mx=max(mx,arr[x]-fr[5]);
	}
	
	ll ans=mx-pq.top().fi;
	while (pq.top().se.se){
		int idx,num;
		tie(idx,num)=pq.top().se;
		pq.pop();
		
		pq.push(iii(arr[idx]-fr[num-1],ii(idx,num-1)));
		mx=max(mx,arr[idx]-fr[num-1]);
		
		ans=min(ans,mx-pq.top().fi);
	}
	cout<<ans<<endl;
	
}