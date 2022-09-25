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
int arr[205];
vector<int> al[205];

int memo[205][205];
int sz[205];

int temp[205];

void dfs(int i,int p){
	memo[i][0]=arr[i];
	sz[i]++;
	
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i);
		
		memset(temp,0,sizeof(temp));
		rep(y,0,sz[it]) temp[y+1]=memo[it][y];
		rep(x,0,sz[i]) rep(y,0,sz[it]) if (x+y>=k){
			temp[min(x,y+1)]=max(temp[min(x,y+1)],memo[i][x]+memo[it][y]);
		}
		sz[i]+=sz[it];
		rep(x,0,sz[i]) memo[i][x]=max(memo[i][x],temp[x]);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	rep(x,1,n+1) cin>>arr[x];
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	dfs(1,-1);
	
	int ans=0;
	rep(x,0,205) ans=max(ans,memo[1][x]);
	
	cout<<ans<<endl;
}