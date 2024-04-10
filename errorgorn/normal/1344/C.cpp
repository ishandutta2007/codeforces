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

vector<int> al[200005];
vector<int> alr[200005];

void rage(){
	cout<<"-1"<<endl;
	exit(0);
}

bool visited[200005];
bool onstack[200005];

void dfs(int i){
	if (visited[i]) return;
	visited[i]=true;
	onstack[i]=true;
	
	for(auto &it:al[i]){
		if (onstack[it]) rage();
		dfs(it);
	}
	
	onstack[i]=false;
}

bool vis[200005][2];
void dfs(int i,int dir){
	if (vis[i][dir]) return;
	vis[i][dir]=true;
	
	for (auto &it:(dir?alr[i]:al[i])){
		dfs(it,dir);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	int a,b;
	while (m--){
		cin>>a>>b;
		al[a].push_back(b);
		alr[b].push_back(a);
	}
	
	rep(x,1,n+1) dfs(x);
	
	int cnt=0;
	string ans="";
	
	rep(x,1,n+1){
		if (vis[x][0] || vis[x][1]) ans+="E";
		else ans+="A",cnt++;
			
		dfs(x,0);
		dfs(x,1);
	}
	
	cout<<cnt<<endl;
	cout<<ans<<endl;
	
}