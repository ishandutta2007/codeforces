#include <bits/stdc++.h>
#define int long long
#define ld long double
#define endl "\n"
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define ms(v,x) memset(v,x,sizeof(v))
#define ff first
#define ss second
#define rep(i,l,r) for(int i = (int)l;i<(int)r;i++)
#define td(v) v.begin(),v.end()
#define M   1000000007 // 1e9 + 7
#define MAXN 100100
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline int mod(int n, int m){ int ret = n%m; if(ret < 0) ret += m; return ret; }
int gcd(int a, int b){return (b == 0 ? a : gcd(b, a%b));}
int exp(int a,int b,int m){
	
    if(b==0) return 1;
    if(b==1) return mod(a,m);
    int k = mod(exp(a,b/2,m),m);
    if(b&1){
        return mod(a*mod(k*k,m),m);
    }
    else return mod(k*k,m);
}

vector<pii> adj[MAXN];
int res[MAXN];
int vis[MAXN];
set<int> S;
void dfs(int v,int p){
	
	
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i].ff!=p){
		int id = adj[v][i].ss;
		res[id] = *S.begin();
		S.erase(S.begin());
		}
	}
	for(int i=0;i<adj[v].size();i++){
		if(adj[v][i].ff!=p)dfs(adj[v][i].ff,v);
	}
	
}

int32_t main(){
	fastio;
	int n;
	cin>>n;
	int big=0;
	int mx =0 ;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		adj[a].pb(pii(b,i));
		adj[b].pb(pii(a,i));
	}
	for(int i=1;i<=n;i++){
		int cur = adj[i].size();
		if(cur>mx){
			mx = cur;
			big = i;
		}
	}
	for(int i=0;i<=n-2;i++)S.insert(i);
	dfs(big,-1);
	for(int i=0;i<n-1;i++){
		cout<<res[i]<<endl;
	}
}