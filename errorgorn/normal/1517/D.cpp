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

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m,k;
int arr[505][505];
int brr[505][505];

int memo[505][505][15];
int ans[505][505];

int dp(int i,int j,int k){
	if (k==0) return 0;
	if (memo[i][j][k]!=-1) return memo[i][j][k];
	
	int res=1e9;
	if (i!=0) res=min(res,dp(i-1,j,k-1)+brr[i-1][j]);
	if (i!=n-1) res=min(res,dp(i+1,j,k-1)+brr[i][j]);
	
	if (j!=0) res=min(res,dp(i,j-1,k-1)+arr[i][j-1]);
	if (j!=m-1) res=min(res,dp(i,j+1,k-1)+arr[i][j]);
	
	return memo[i][j][k]=res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>k;
	
	rep(x,0,n) rep(y,0,m-1) cin>>arr[x][y];
	rep(x,0,n-1) rep(y,0,m) cin>>brr[x][y];
	
	memset(memo,-1,sizeof(memo));
	
	rep(x,0,n) rep(y,0,m){
		if (k%2==1){
			ans[x][y]=-1;
			continue;
		}
		
		ans[x][y]=dp(x,y,k/2)*2;
	}
	
	rep(x,0,n){
		rep(y,0,m) cout<<ans[x][y]<<" ";
		cout<<endl;
	}
}