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

const int dx[]={0,0,-1,-1,-1,1,1,1};
const int dy[]={-1,1,-1,0,1,-1,0,1};

int n,m;
string grid[1000005];
vector<int> w[1000005];
queue<ii> q;

vector<int> w2[1000005];

bool can(int i){
	rep(x,0,n) rep(y,0,m){
		w2[x][y]=-1;
		
		if (w[x][y]>=i){
			q.push(ii(x,y));
			w2[x][y]=w[x][y];
		}
	}
	
	while (!q.empty()){
		int x=q.front().fi,y=q.front().se;
		q.pop();
		
		if (w2[x][y]==0) continue;
		
		rep(z,0,8){
			int X=x+dx[z],Y=y+dy[z];
			
			if (X<0 || n<=X || Y<0 || m<=Y) continue;
			
			if (w2[X][Y]==-1){
				w2[X][Y]=w2[x][y]-1;
				q.push(ii(X,Y));
			}
		}
	}
	
	rep(x,0,n){
		rep(y,0,m){
			if ((w[x][y]==-1)!=(w2[x][y]==-1)) return false;
		}
	}
	
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	rep(x,0,n){
		cin>>grid[x];
		rep(y,0,m) w[x].push_back(-1);
		rep(y,0,m) w2[x].push_back(-1);
	}
	
	rep(x,0,n) rep(y,0,m) if (grid[x][y]=='X'){
		rep(z,0,8){
			int X=x+dx[z],Y=y+dy[z];
			
			if (X<0 || n<=X || Y<0 || m<=Y || grid[X][Y]=='.'){
				w[x][y]=0;
				q.push(ii(x,y));
				break;
			}
		}
	}
	
	while (!q.empty()){
		int x=q.front().fi,y=q.front().se;
		q.pop();
		
		
		rep(z,0,8){
			int X=x+dx[z],Y=y+dy[z];
			
			if (X<0 || n<=X || Y<0 || m<=Y) continue;
			
			if (w[X][Y]==-1 && grid[X][Y]=='X'){
				w[X][Y]=w[x][y]+1;
				q.push(ii(X,Y));
			}
		}
	}
	
	int lo=0,hi=2000,mi;
	
	while (hi-lo>1){
		mi=hi+lo>>1;
		
		if (can(mi)) lo=mi;
		else hi=mi;
	}
	
	cout<<lo<<endl;
	rep(x,0,n){
		rep(y,0,m) cout<<(w[x][y]>=lo?'X':'.');
		cout<<endl;
	}
	
}