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

int n,m,q;
string grid[1005];
ll w[1005][1005];

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

queue<ii> qu;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>q;
	rep(x,0,m+2) grid[0]+='$';
	rep(x,1,n+1){
		cin>>grid[x];
		grid[x]="$"+grid[x]+"$";
	}
	rep(x,0,m+2) grid[n+1]+='$';
	
	memset(w,-1,sizeof(w));
	rep(x,1,n+1){
		rep(y,1,m+1){
			rep(z,0,4){
				//cout<<x<<" "<<y<<" "<<x+dx[z]<<" "<<y+dy[z]<<endl;
				//cout<<grid[x][y]<<" "<<grid[x+dx[z]][y+dy[z]]<<endl;
				if (grid[x][y]==grid[x+dx[z]][y+dy[z]]){
					w[x][y]=0;
					qu.push(ii(x,y));
					break;
				}
			}
		}
	}
	
	int X,Y;
	while (!qu.empty()){
		X=qu.front().fi,Y=qu.front().se;
		qu.pop();
		
		rep(z,0,4) if (1<=X+dx[z] && X+dx[z]<=n && 1<=Y+dy[z] && Y+dy[z]<=m){
			if (w[X+dx[z]][Y+dy[z]]==-1){
				w[X+dx[z]][Y+dy[z]]=w[X][Y]+1;
				qu.push(ii(X+dx[z],Y+dy[z]));
			}
		}
	}
	
	ll a,b,c;
	while (q--){
		cin>>a>>b>>c;
		
		if (w[a][b]==-1) cout<<grid[a][b]<<endl;
		else{
			if (c<w[a][b]) cout<<grid[a][b]<<endl;
			else cout<<(char)(grid[a][b]^((c-w[a][b])&1))<<endl;
		}
	}
	
}