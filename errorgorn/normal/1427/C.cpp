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

int n,q;
ii pos[100005];
int tt[100005];
int ans[100005];
int memo[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	pos[0]=ii(1,1);
	
	int t,a,b;
	rep(x,1,q+1){
		memo[x]=-1e9;
	
		cin>>t>>a>>b;
		pos[x]=ii(a,b);
		tt[x]=t;
		
		rep(y,max(0,x-1005),x){
			if (abs(a-pos[y].fi)+abs(b-pos[y].se)<=t-tt[y]) memo[x]=max(memo[x],memo[y]+1);
		}
		
		if (0<=x-1006) memo[x]=max(memo[x],ans[x-1006]+1);
		ans[x]=max(memo[x],ans[x-1]);
	}
	
	cout<<ans[q]<<endl;
}