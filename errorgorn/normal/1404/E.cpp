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
string grid[205];

int get(int i,int j){
	return i*200+j;
}

vector<int> al[40005];
bool l[40005];
int r[40005];
bool vis[40005];

bool dfs(int i){
	if (vis[i]) return false;
	vis[i]=true;
	
	for (auto &it:al[i]){
		if (r[it]==-1 || dfs(r[it])){
			r[it]=i;
			return true;
		}
	}
	
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) cin>>grid[x];
	
	int ans=0;
	rep(x,0,n){
		rep(y,0,m){
			if (x!=n-1 && grid[x][y]=='#' && grid[x+1][y]=='#') ans--;
			if (y!=m-1 && grid[x][y]=='#' && grid[x][y+1]=='#') ans--;
			if (grid[x][y]=='#') ans++;
		}
	}
	
	rep(x,0,n-1){
		rep(y,0,m){
			if (grid[x][y]=='#' && grid[x+1][y]=='#'){
				if (y!=0 && grid[x][y-1]=='#') al[get(x,y)].push_back(get(x,y));
				if (y!=0 && grid[x+1][y-1]=='#') al[get(x,y)].push_back(get(x+1,y));
				if (y!=m-1 && grid[x][y+1]=='#') al[get(x,y)].push_back(get(x,y+1));
				if (y!=m-1 && grid[x+1][y+1]=='#') al[get(x,y)].push_back(get(x+1,y+1));
			}
		}
	}
	
	rep(x,0,40005){
		for (auto &it:al[x]){
			if (r[it]==-1){
				r[it]=x;
				l[x]=true;
				break;
			}
		}
	}
	
	memset(r,-1,sizeof(r));
	rep(x,0,40005) if (!l[x]){
		memset(vis,false,sizeof(vis));
		
		ans+=dfs(x);
	}
	
	cout<<ans<<endl;
}