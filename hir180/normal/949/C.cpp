#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n,m,h,a[100005];
vector<int>e[100005],f[100005];
int c[100005],p[100005],k;
bool u[100005];
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
vector<int>id[100005];

int main(){
	scanf("%d%d%d",&n,&m,&h);
	repn(i,n) scanf("%d",&a[i]);
	for(int i=0;i<m;i++){
		int x,y; scanf("%d%d",&x,&y);
		if( (a[x]+1)%h == a[y] ){
			e[x].push_back(y);
			f[y].push_back(x);
		}
		if( (a[y]+1)%h == a[x] ){
			f[x].push_back(y);
			e[y].push_back(x);
		}
	}
	for(int i=1;i<=n;i++){
		if(!u[i]){
			dfs(i);
		}
	}
	memset(u,0,sizeof(u)); k=0;
	for(int i=n-1;i>=0;i--){
		if(!u[c[i]]){
			sfd(c[i]); k++;
		}
	}
	memset(u,0,sizeof(u));
	for(int i=1;i<=n;i++){
		id[p[i]].pb(i);
		for(int j=0;j<e[i].size();j++){
			if(p[i] != p[e[i][j]]){
				u[p[i]] = 1;
			}
		}
	}
	int ans = INF;
	rep(i,k){
		if(u[i]) continue;
		if(ans > id[i].size()) ans = id[i].size();
	}
	cout << ans << endl;
	rep(i,k){
		if(u[i]) continue;
		if(ans == id[i].size()){
			rep(j,id[i].size()) cout << id[i][j] << '\n';return 0;
		}
	}
}