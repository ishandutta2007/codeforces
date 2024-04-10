//
//

#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;
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

int n,m,k,MOD;

ll nCk[105][105];
ll memo[105][105][55];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>k>>MOD;
	swap(m,k);
	
	if (m>=55){
	    cout<<0<<endl;
	    return 0;
	}
	
	nCk[0][0]=1;
	rep(x,1,105){
		nCk[x][0]=1;
		rep(y,1,x+1) nCk[x][y]=(nCk[x-1][y-1]+nCk[x-1][y])%MOD;
	}
	
	memo[1][0][1]=1;
	rep(x,1,105) memo[1][x][1]=memo[1][x-1][1]*x%MOD;
	rep(x,2,105) memo[x][1][0]=1;
	
	rep(z,2,k+1){
		rep(x1,1,104) rep(x2,1,104-x1) rep(y1,0,(x1+1)/2+1) rep(y2,0,(x2+1)/2+1){
			memo[z][x1+x2+1][y1+y2]=(memo[z][x1+x2+1][y1+y2]+
								memo[z-1][x1][y1]*memo[z-1][x2][y2]%MOD
									*nCk[x1+x2][x1])%MOD;
		}
		rep(x,1,104) rep(y,0,55) memo[z][x+1][y]=(memo[z][x+1][y]+2*memo[z-1][x][y])%MOD;
	}
	
	cout<<memo[k][n][m]<<endl;
}