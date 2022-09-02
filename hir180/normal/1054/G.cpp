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
int t,n,m;
vector<int>connect[2505];
vector<int>query[2505];
int cnt[2505][2505],cnt2[2505][2505];
P mx[2505][2505],mx2[2505][2505];
struct uf{
	int par[2505],ran[2505];
	void init(){ for(int i=0;i<2505;i++) par[i] = i,ran[i] = 0; }
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
}Shiki;
vector<int>tree[2505];
bool Kanade(){
	for(int i=0;i<m;i++){
		bool in[2505] = {},used[2505] = {};
		for(int j=0;j<connect[i].size();j++) in[connect[i][j]] = 1;
		int a = connect[i][0];
		queue<int>que;
		que.push(a);
		int C = 0;
		while(!que.empty()){
			int q = que.front(); que.pop();
			if(used[q]) continue; used[q] = 1; C++;
			for(int i=0;i<tree[q].size();i++){
				int to = tree[q][i];
				if(!in[to] || used[to]) continue;
				que.push(to);
			}
		}
		if(C != connect[i].size()) return false;
	}
	return true;
}
bitset<2505>B[2505];
void Kaede(){
	scanf("%d%d",&n,&m);
	rep(a,m){
		connect[a].clear();
	}
	rep(a,n){
		query[a].clear();
		B[a].reset();
		tree[a].clear();
		rep(b,n) cnt[a][b] = cnt2[a][b] = 0, mx[a][b] = mx2[a][b] = mp(-1,-1);
	}
	for(int i=0;i<m;i++){
		char f[2505]; scanf("%s",&f);
		int beg = INF;
		for(int j=0;j<n;j++){
			if(f[j] == '1'){
				beg = min(beg,j);
				connect[i].pb(j);
			}
		}
		if(connect[i].size() <= 1) continue;
		for(int j=0;j<connect[i].size();j++){
			B[connect[i][j]][i] = 1;
		}
	}
	vector<P1>vec;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int len = (B[i]&B[j]).count();
			vec.pb(mp(-len,mp(i,j)));
		}
	}
	Shiki.init();
	SORT(vec);
	rep(i,vec.size()){
		int u = vec[i].sc.fi, v = vec[i].sc.sc;
		if(Shiki.same(u,v) == false){
			Shiki.unite(u,v);
			tree[u].pb(v);
			tree[v].pb(u);
		}
	}
	if(Kanade()){
		puts("YES");
		for(int i=0;i<n;i++){
			for(int j=0;j<tree[i].size();j++){
				if(i > tree[i][j]) continue;
				printf("%d %d\n",i+1,tree[i][j]+1);
			}
		}
	}
	else{
		puts("NO");
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		Kaede();
	}
}