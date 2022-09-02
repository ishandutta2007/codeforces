#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
int len[200005];;
int *a[100005];
vector<int>e[250005],f[250005];
int c[250005],p[250005],k;
bool u[250005];
void dfs(int v){
	if(u[v]) return;
	u[v] = 1;
	for(int i=0;i<e[v].size();i++){
		if(!u[e[v][i]]) dfs(e[v][i]);
	}
	c[k++] = v;
}
void sfd(int v){
	if(u[v]) return;
	u[v] = 1; p[v] = k;
	for(int i=0;i<f[v].size();i++){
		if(!u[f[v][i]]) sfd(f[v][i]);
	}
}
void add_edge(int x,int y){
	e[x].pb(y); f[y].pb(x);
}

int main(){
	cin>>n>>m;
	repn(i,n){
		int t; scanf("%d",&t); len[i] = t;
		a[i] = new int[t+3];
		rep(j,t){
			scanf("%d",&a[i][j]);
		}
	}
	bool bad = 0;
	//true... big
	repn(i,n-1){
		int x = min(len[i],len[i+1]);
		rep(j,x){
			if(a[i][j] != a[i+1][j]){
				if(a[i][j] > a[i+1][j]){
					add_edge(a[i][j]+120000,a[i][j]);
					add_edge(a[i+1][j],a[i+1][j]+120000);
				}
				else{
					add_edge(a[i][j]+120000,a[i+1][j]+120000);
					add_edge(a[i+1][j],a[i][j]);
				}
				goto nxt;
			}
		}
		if(len[i] > len[i+1]) bad = 1;
		nxt:;
	}
	for(int i=0;i<250000;i++){
		if(!u[i]){
			dfs(i);
		}
	}
	memset(u,0,sizeof(u)); k=0;
	for(int i=249999;i>=0;i--){
		if(!u[c[i]]){
			sfd(c[i]); k++;
		}
	}
	vector<int>ans;
	for(int i=1;i<=m;i++){
		if(p[i] == p[i+120000]){
			bad = 1;
		}
		else if(p[i] > p[i+120000]){
			ans.pb(i);
		}
	}
	if(bad) puts("No");
	else{
		puts("Yes");
		cout<<ans.size()<<endl;
		rep(i,ans.size()) printf("%d ",ans[i]);
		puts("");
	}
}