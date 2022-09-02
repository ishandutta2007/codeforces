#include <bits/stdc++.h>
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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m,q;
vector<int>vec[200005];
int par[200005],ran[200005];
void init(){ for(int i=0;i<200005;i++) par[i] = i; }
int find(int x){ if(x == par[x]) return x; else return par[x] = find(par[x]); }
void unite(int x,int y){
	x = find(x); y = find(y); if(x==y) return;
	if(ran[x] < ran[y]) par[x] = y;
	else{
		par[y] = x;
		if(ran[x] == ran[y]) ran[x]++;
	}
}
bool same(int x,int y){ return find(x)==find(y); }
bool used[200005],used2[200005];
int main(){
	cin>>n>>m>>q;
	rep(i,q){
		int a,b; cin>>a>>b;
		vec[b].pb(a);
		used[a] = 1;
		used2[b] = 1;
	}
	init();
	for(int i=1;i<=m;i++){
		for(int j=1;j<vec[i].size();j++){
			unite(vec[i][j-1],vec[i][j]);
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++) if(!used[i]) ans++;
	for(int i=1;i<=m;i++) if(!used2[i]) ans++;
	for(int i=1;i<=n;i++){
	    if(!used[i]) continue;
		if(find(i) == i) ans++;
	}
	ans --;
	cout<<ans<<endl;
}