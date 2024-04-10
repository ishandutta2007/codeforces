// Super Idol
//    
//  
//    
//  105C
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

const int MOD=1000000007;

int n;
vector<int> v;
int memo[505][40005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,1,40005){
		int xx=x;
		vector<int> digit;
		while (xx) digit.pub(xx%10),xx/=10;
		
		vector<int> digit2=digit;
		reverse(all(digit2));
		
		if (digit==digit2) v.pub(x);
	}
	
	memo[0][0]=1;
	rep(x,0,sz(v)) rep(y,0,40005){
		memo[x+1][y]=(memo[x+1][y]+memo[x][y]);
		if (y+v[x]<40005){
			memo[x][y+v[x]]=(memo[x][y+v[x]]+memo[x][y])%MOD;
		}
	}
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		cout<<memo[sz(v)][n]<<endl;
	}
}