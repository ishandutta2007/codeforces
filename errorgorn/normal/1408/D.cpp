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

int n,m;
ii arr[2005];
ii brr[2005];

ll dist[1000100];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) cin>>arr[x].fi>>arr[x].se;
	rep(x,0,m) cin>>brr[x].fi>>brr[x].se;
	brr[m]=ii(1e6+10,-1);
	brr[m+1]=ii(-1,1e6+10);
	m+=2;
	sort(brr,brr+m);
	reverse(brr,brr+m);
	rep(x,0,m-1) brr[x+1].se=max(brr[x+1].se,brr[x].se);
	
	//rep(x,0,m) cout<<"debug: "<<brr[x].fi<<" "<<brr[x].se<<endl;
	
	rep(x,0,n){
		rep(y,0,m){
			if (brr[y].fi<arr[x].fi) break;
			
			int out=brr[y].fi-arr[x].fi;
			//cout<<out<<endl;
			dist[out]=max(dist[out],max(brr[y].se-arr[x].se+1,0LL));
		}
	}
	
	
	ll ans=1e9;
	rep(x,1000100,0){
		ans=min(ans,x+dist[x]);
		if (x) dist[x-1]=max(dist[x-1],dist[x]);
	}
	
	//rep(x,0,10) cout<<x<<" "<<dist[x]<<endl;
	cout<<ans<<endl;
}