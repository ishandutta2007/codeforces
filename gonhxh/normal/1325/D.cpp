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
	int u,v;
	cin>>u>>v;
	int a=u,b=0,c=0;
	int V = v;
	v-=u;
	if(v<0 || (v&1LL)){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=63;i++){
		if(v&(1LL<<i)){
			if(u&(1LL<<(i-1))){
				b+=(1LL<<(i-1));
				c+=(1LL<<(i-1));
			}else{
				a+=(1LL<<(i-1));
				b+=(1LL<<(i-1));
			}
		}
	}
	
	if((a+b+c)!=V || ((a^b)^c)!=u){
		cout<<-1<<endl;
		return 0;
	}
	
	vector<int> vec;
	if(a>0)vec.pb(a);
	if(b>0)vec.pb(b);
	if(c>0)vec.pb(c);
	cout<<vec.size()<<endl;
for(int i=0;i<vec.size();i++){
	cout<<vec[i]<<" ";
}
cout<<endl;
	
}