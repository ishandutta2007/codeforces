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

int n;
string grid[20];

int id[20005];
vector<int> bm[20];

vector<int> memo[8192][14];
ll ans[20005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,1<<14){
		id[x]=sz(bm[__builtin_popcount(x)]);
		bm[__builtin_popcount(x)].pub(x);
	}
	
	rep(x,1,1<<13) rep(y,0,14){
		int l=32-__builtin_clz(x);
		memo[x][y]=vector<int>(sz(bm[l]));
	}
	
	cin>>n;
	rep(x,0,n) cin>>grid[x];
	
	rep(x,0,n) memo[1][x][id[1<<x]]=1;
	
	rep(x,1,1<<(n-1)){
		int l=32-__builtin_clz(x);
		
		rep(i,0,sz(bm[l])){
			int bit=bm[l][i];
			
			rep(y,0,n) if ((bit&(1<<y))==0) rep(y2,0,n){
				int temp=x|(1<<l);
				if (grid[y][y2]=='0') temp^=1<<(l-1);
				
				if (l==n-1){
					temp^=(1<<l);
					ans[temp]+=memo[x][y2][i];
				}
				else memo[temp][y][id[bit|(1<<y)]]+=memo[x][y2][i];
			}
		}
	}
	
	rep(x,0,1<<(n-1)) cout<<ans[x]<<" "; cout<<endl;
}