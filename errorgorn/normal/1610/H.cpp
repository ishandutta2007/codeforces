// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
int p[300005];
vector<ii> al[300005];

int in[300005];
int out[300005];
int pp[300005];
int TIME=0;

void dfs(int i){
	in[i]=++TIME;
	for (auto [it,id]:al[i]){
		pp[it]=~id;
		dfs(it);
	}
	out[i]=TIME;
}

const int BUF=300005;
ii edges[300005];
vector<int> al2[600010];
int memo[600010];

int par[300005];
int val[300005];

int dfs2(int id){
	if (memo[id+BUF]!=-1) return memo[id+BUF];
	
	int u,v;
	if (id>=0) tie(u,v)=ii(p[id],id+2);
	else tie(u,v)=ii((~id)+2,p[~id]);
	
	int res=0;
	for (auto it:al2[id+BUF]) res=max(res,dfs2(it)+1);
	
	if (par[v]==1e9){
		for (auto [it,id]:al[v]){
			if (it==u) continue;
			val[v]+=dfs2(id);
		}
		res=max(res,val[v]);
		par[v]=~id;
	}
	else{
		res=max(res,val[v]+dfs2(par[v])-dfs2(~id));
	}
	
	return memo[id+BUF]=res;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	
	int a,b;
	rep(x,0,n-1){
		cin>>p[x];
		al[p[x]].pub({x+2,x});
	}
	
	dfs(1);
	
	rep(x,0,m){
		cin>>a>>b;
		
		if (in[a]>in[b]) swap(a,b);
		
		if (out[b]<=out[a]){
			int lo=0,hi=sz(al[a]),mi;
			
			while (hi-lo>1){
				mi=hi+lo>>1;
				
				if (in[al[a][mi].fi]<=in[b]) lo=mi;
				else hi=mi;
			}
			
			a=al[a][lo].se;
			b=pp[b];
		}
		else{
			a=pp[a];
			b=pp[b];
		}
		
		//cout<<a<<" "<<b<<endl;
		
		if (a==~b){
			cout<<"-1"<<endl;
			return 0;
		}
		
		edges[x]={a,b};
		al2[a+BUF].pub(~b);
		al2[b+BUF].pub(~a);
	}
	
	rep(x,0,n-1) al[x+2].pub({p[x],~x});
	
	int ans=0;
	memset(memo,-1,sizeof(memo));
	rep(x,0,300005) par[x]=1e9;
	rep(x,0,m) ans=max(ans,1+dfs2(~edges[x].fi)+dfs2(~edges[x].se));
	
	cout<<ans<<endl;
}