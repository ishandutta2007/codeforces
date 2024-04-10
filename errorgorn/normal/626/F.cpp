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

const int MOD=1000000007;

int n,m;
int arr[205];
int memo[205][205][1005];

ll dp(ll i,ll j,ll k){
	if (k>m) return 0;
	if (i==-1){
		if (j==0) return 1;
		else return 0;
	}
	if (memo[i][j][k]!=-1) return memo[i][j][k];
	
	ll res=dp(i-1,j,k+j*arr[i])*(j+1)%MOD;
	res=(res+dp(i-1,j+1,k+(j+1)*arr[i]))%MOD;
	if (j) res=(res+dp(i-1,j-1,k+(j-1)*arr[i])*j)%MOD;
	
	return memo[i][j][k]=res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) cin>>arr[x];
	sort(arr,arr+n);
	
	rep(x,n,1) arr[x]-=arr[x-1];
	arr[0]=0;
	
	memset(memo,-1,sizeof(memo));
	cout<<dp(n-1,0,0)<<endl;
}