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

int n,m;
int arr[105][105];
bool taken[105][105];
int ans[105];
int mat[105][105];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) rep(y,0,m) cin>>arr[x][y];
		rep(x,0,n) rep(y,0,m) taken[x][y]=false;
		
		rep(z,0,m){
			int xx=-1,yy=-1;
			
			rep(x,0,n) rep(y,0,m) if (!taken[x][y]){
				if (xx==-1 || arr[xx][yy]>arr[x][y]) xx=x,yy=y;
			}
			
			rep(x,0,n){
				if (x==xx) ans[x]=yy;
				else{
					int best=-1;
					rep(y,0,m) if (!taken[x][y]){
						if (best==-1 || arr[x][best]<arr[x][y]) best=y;
					}
					ans[x]=best;
				}
				
				taken[x][ans[x]]=true;
			}
			
			rep(x,0,n) mat[z][x]=arr[x][ans[x]];
		}
		
		rep(x,0,n){
			rep(y,0,m) cout<<mat[y][x]<<" "; 
			cout<<endl;
		}
	}
}