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
string grid[505];
int w[505][505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) cin>>grid[x];
		
		int ans=0;
		rep(x,n,0){
			rep(y,0,m){
				if (grid[x][y]=='.') w[x][y]=0;
				else{
					if (x==n-1 || y==0 || y==m-1) w[x][y]=1;
					else w[x][y]=min({w[x+1][y-1],w[x+1][y],w[x+1][y+1]})+1;
					ans+=w[x][y];
					
					//cout<<x<<" "<<y<<" "<<w[x][y]<<endl;
				}
			}
		}
		
		cout<<ans<<endl;
	}
	
}