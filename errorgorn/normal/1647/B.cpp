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
#define int long long
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

const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int n,m;
string grid[105];
bool vis[105][105];

int a,b,c,d;
int cnt;

void dfs(int i,int j){
	vis[i][j]=true;
	
	a=min(a,i),b=max(b,i);
	c=min(c,j),d=max(d,j);
	cnt++;
	
	rep(z,0,4){
		int aa=i+dx[z],bb=j+dy[z];
		
		if (aa<0 || n<=aa || bb<0 || m<=bb || vis[aa][bb] || grid[aa][bb]=='0') continue;
		dfs(aa,bb);
	}
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>m;
		rep(x,0,n) cin>>grid[x];
		memset(vis,false,sizeof(vis));
		
		bool ok=true;
		
		rep(x,0,n) rep(y,0,m) if (grid[x][y]=='1' && !vis[x][y]){
			a=c=1e9,b=d=-1e9;
			cnt=0;
			
			dfs(x,y);
			
			if (cnt!=(b-a+1)*(d-c+1)) ok=false;
		}
		
		if (ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}