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

int n,m;
string grid[1005];

int h[1005];
int v[1005];

bool dfs(int i,int j,int id){
	if (i<1 || n<i || j<1 || m<j) return false;
	if (grid[i][j]=='.') return false;
	
	if (h[i]!=-1 && h[i]!=id) return true;
	if (v[j]!=-1 && v[j]!=id) return true;
	
	h[i]=v[j]=id;
	grid[i][j]='.';
	
	return (dfs(i-1,j,id) || dfs(i+1,j,id) || dfs(i,j-1,id) || dfs(i,j+1,id));
}

void rage(){
	cout<<"-1"<<endl;
	exit(0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(h,-1,sizeof(h));
	memset(v,-1,sizeof(v));
	
	cin>>n>>m;
	
	rep(x,0,m+1) grid[0]+='.';
	rep(x,1,n+1) cin>>grid[x],grid[x]="."+grid[x];
	
	rep(x,1,n+1){
		int num=0;
		rep(y,1,m+1){
			num+=(grid[x][y-1]=='.' && grid[x][y]=='#');
		}
		
		if (num>1) rage();
	}
	
	rep(y,1,m+1){
		int num=0;
		rep(x,1,n+1){
			num+=(grid[x-1][y]=='.' && grid[x][y]=='#');
		}
		
		if (num>1) rage();
	}
	
	int counter=0;
	
	rep(x,1,n+1){
		rep(y,1,m+1){
			if (grid[x][y]=='#') if (dfs(x,y,counter++)) rage();
		}
	}
	
	//rep(x,0,n+1) cout<<grid[x]<<endl;
	
	int hn=0,vn=0;
	
	rep(x,1,n+1) if (h[x]==-1) hn++;
	rep(x,1,m+1) if (v[x]==-1) vn++;
	
	if ((hn==0) != (vn==0)) rage();
	
	cout<<counter<<endl;
	
}