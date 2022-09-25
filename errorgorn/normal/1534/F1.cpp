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

int n,m;
string grid[400005];
int arr[400005];

vector<int> col[400005];

vector<int> al[400005];

int code(int x,int y){
	return x*m+y;
}

int _TIME=1;
int IDX=1;

int in[400005];
int low[400005];
bool onstk[400005];
vector<int> stk;

int comp[400005];
int indeg[400005];

void dfs(int i){
	in[i]=low[i]=_TIME++;
	onstk[i]=true;
	stk.pub(i);
	
	for (auto &it:al[i]){
		if (in[it]==0){
			dfs(it);
			low[i]=min(low[i],low[it]);
		}
		else if (onstk[it]){
			low[i]=min(low[i],in[it]);
		}
	}
	
	if (in[i]==low[i]){
		int curr;
		do{
			curr=stk.back(),stk.pob();
			comp[curr]=IDX;
			onstk[curr]=false;
		} while (curr!=i);
		IDX++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) cin>>grid[x];
	rep(x,0,m) cin>>arr[x];
	
	rep(x,0,n) rep(y,0,m) if (grid[x][y]=='#'){
		col[y].pub(x);
	}
	
	rep(x,1,n) rep(y,0,m){ //shld be sufficient to connect to par
		if (grid[x-1][y]=='#' && grid[x][y]=='#'){
			al[code(x,y)].pub(code(x-1,y));
		}
	}
	
	rep(y,0,m){
		rep(x,0,sz(col[y])){
			if (x!=sz(col[y])-1) al[code(col[y][x],y)].pub(code(col[y][x+1],y));
			
			if (y){
				auto it=lb(all(col[y-1]),col[y][x]);
				if (it!=col[y-1].end())
					al[code(col[y][x],y)].pub(code(*it,y-1));
			}
			if (y!=m-1){
				auto it=lb(all(col[y+1]),col[y][x]);
				if (it!=col[y+1].end())
					al[code(col[y][x],y)].pub(code(*it,y+1));
			}
		}
	}
	
	rep(x,0,n) rep(y,0,m) if (grid[x][y]=='#' && in[code(x,y)]==0){
		dfs(code(x,y));
	}
	
	rep(x,0,n) rep(y,0,m){
		int c=code(x,y);
		for (auto &it:al[c]) if (comp[c]!=comp[it]) indeg[comp[it]]++;
	}
	
	int ans=0;
	rep(x,1,IDX){
		if (indeg[x]==0) ans++;
	}
	
	cout<<ans<<endl;
}