/*













*/

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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int n,m;
string grid[55];
queue<ii> q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) cin>>grid[x];
		
		rep(x,0,n) rep(y,0,m) if (grid[x][y]=='B'){
			rep(z,0,4){
				int i=x+dx[z],j=y+dy[z];
				
				if (i<0 || n<=i || j<0 || m<=j) continue;
				
				if (grid[i][j]=='G'){
					cout<<"No"<<endl;
					goto _end;
				}
				else if (grid[i][j]!='B'){
					grid[i][j]='#';
				}
			}
		}
		
		if (grid[n-1][m-1]!='#'){
			grid[n-1][m-1]='$';
			q.push(ii(n-1,m-1));
		}
		
		while (!q.empty()){
			int x=q.front().fi,y=q.front().se;
			q.pop();
			
			rep(z,0,4){
				int i=x+dx[z],j=y+dy[z];
				
				if (i<0 || n<=i || j<0 || m<=j) continue;
				
				if (grid[i][j]!='#' && grid[i][j]!='$'){
					grid[i][j]='$';
					q.push(ii(i,j));
				}
			}
		}
		
		rep(x,0,n) rep(y,0,m){
			if (grid[x][y]=='G'){
				cout<<"No"<<endl;
				goto _end;
			}
		}
		
		cout<<"Yes"<<endl;
		
		_end:;
	}
}