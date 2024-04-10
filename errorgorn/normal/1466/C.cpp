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

string s;
int memo[2][2][2];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>s;
		
		memset(memo,0,sizeof(memo));
		
		s="$$"+s;
		
		int a=0,b=1;
		rep(iter,2,sz(s)){
			memset(memo[b],63,sizeof(memo[b]));
			
			rep(x,0,2){
				rep(y,0,2){
					rep(z,0,2){
						if (s[iter]==s[iter-1] && z==0 && y==0) continue;
						if (s[iter]==s[iter-2] && z==0 && x==0) continue;
						memo[b][y][z]=min(memo[b][y][z],memo[a][x][y]+z);
					}
				}
			}
			
			// rep(x,0,2){
				// rep(y,0,2) cout<<memo[b][x][y]<<" ";
			// }
			// cout<<endl;
			
			swap(a,b);
		}
		
		int ans=1e9;
		cout<<min({memo[a][0][0],memo[a][0][1],memo[a][1][0],memo[a][1][1]})<<endl;
	}
}