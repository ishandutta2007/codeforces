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

int n,q;
vector<int> al[200005];

const int B1=300;
int memo[200005][B1+5];
int ss[200005];

int temp[B1+5];

void dfs(int i,int p){
	for (auto &it:al[i]){
		if (it==p) continue;
		
		dfs(it,i);
		
		memset(temp,0,sizeof(temp));
		
		rep(x,0,ss[i]+1) rep(y,0,min(B1-x+1,ss[it]+2)){
			if (y==0) temp[x+y]=max(temp[x+y],memo[i][x]+1);
			else temp[x+y]=max(temp[x+y],memo[i][x]+memo[it][y-1]);
		}
		rep(x,0,B1+1) memo[i][x]=max(memo[i][x],temp[x]);
		
		ss[i]=min(ss[i]+ss[it]+1,B1);
	}
}

vector<ii> edges;
int memo2[200005];
void dfs2(int i,int p){
	for (auto &it:al[i]){
		if (it==p) continue;
		dfs2(it,i);
		edges.pub(ii(i,it));
	}
}

vector<ii> qu[670];
ll ans[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	ll a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	dfs(1,-1);
	
	cin>>q;
	rep(x,0,q){
		cin>>a>>b;
		
		if (b>=670){
			rep(y,0,B1+1) ans[x]=max(ans[x],memo[a][y]-y*b);
		}
		else{
			qu[b].pub(ii(a,x));
		}
	}
	
	dfs2(1,-1);
	
	rep(x,0,670) if (!qu[x].empty()){
		memset(memo2,0,sizeof(memo2));
		for (auto &it:edges) memo2[it.fi]+=max(1,memo2[it.se]-x);
		for (auto &it:qu[x]) ans[it.se]=memo2[it.fi];
	}
	
	rep(x,0,q) cout<<ans[x]<<endl;
}