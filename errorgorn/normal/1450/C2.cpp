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

int n;
string grid[305];
bool vis[305][305];

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

vector<ii> v[3];

void dfs(int i,int j){
	vis[i][j]=true;
	v[(i+j+(grid[i][j]=='O'))%3].push_back(ii(i,j));
	
	rep(z,0,4){
		int i2=i+dx[z],j2=j+dy[z];
		
		if (i2<0 || n<=i2 || j2<0 || n<=j2) continue;
		if (grid[i2][j2]=='.' || vis[i2][j2]) continue;
		dfs(i2,j2);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,0,n) cin>>grid[x];
		rep(x,0,n) rep(y,0,n) vis[x][y]=false;
		
		rep(x,0,n) rep(y,0,n) if (grid[x][y]!='.' && !vis[x][y]){
			rep(z,0,3) v[z].clear();
			dfs(x,y);
			
			if (sz(v[1])<sz(v[0])) swap(v[0],v[1]);
			if (sz(v[2])<sz(v[0])) swap(v[0],v[2]);
			
			for (auto &it:v[0]){
				if (grid[it.fi][it.se]=='X') grid[it.fi][it.se]='O';
				else grid[it.fi][it.se]='X';
				//grid[it.fi][it.se]='Z';
			}
		}
		
		rep(x,0,n) cout<<grid[x]<<endl;
	}
}