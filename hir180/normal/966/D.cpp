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
int n,m;
vector<int>edge[300005];
int dist[300005];
bool used[300005];
int ans;
int par[300005],ran[300005];
void init(){ for(int i=0;i<300005;i++) par[i] = i; }
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
bool c[300005];
vector<int>way1(){
	for(int i=2;i<=n;i++){
		if(!c[i]) continue;
		for(int j=0;j<edge[i].size();j++){
			int to = edge[i][j];
			if(to != 1 && !c[to]){
				vector<int>ret;
				ret.pb(1);
				ret.pb(i);
				ret.pb(to);
				ret.pb(1);
				ret.pb(n);
				return ret;
			}
		}
	}
	assert(0);
}
bool in[300005];
int cntv[300005],cnte[300005];
vector<int>be[300005];
vector<int>way2(vector<int>vec){
	init();
	for(int i=0;i<vec.size();i++){
		in[vec[i]] = 1;
	}
	for(int i=0;i<vec.size();i++){
		int v = vec[i];
		for(int j=0;j<edge[v].size();j++){
			int u = edge[v][j];
			if(v == 1 || u == 1) continue;
			if(!in[v] || !in[u]) continue;
			unite(u,v);
		}
	}
	for(int i=0;i<vec.size();i++){
		int v = vec[i];
		for(int j=0;j<edge[v].size();j++){
			int u = edge[v][j];
			if(v == 1 || u == 1) continue;
			if(!in[v] || !in[u]) continue;
			cnte[find(u)]++;
		}
	}
	for(int i=0;i<vec.size();i++){
		int v = vec[i];
		if(v == 1 || !in[v]) continue;
		cntv[find(v)]++;
		be[find(v)].pb(vec[i]);
	}
	for(int i=1;i<=n;i++) SORT(edge[i]);
	int vv = -1;
	for(int i=0;i<vec.size();i++){
		int v = vec[i];
		if(cntv[v] >= 3 && 1LL*cnte[v] != 1LL*cntv[v]*(cntv[v]-1)){
			//assert(1LL*cnte[v] < 1LL*cntv[v]*(cntv[v]-1));
			for(int a=0;a<be[v].size();a++){
				for(int b=a+1;b<be[v].size();b++){
					int x = be[v][a],y = be[v][b];
					if(POSL(edge[x],y) != edge[x].size() && edge[x][POSL(edge[x],y)] == y) continue;
					vv = x; goto nxt;
				}
			}
		}
	}
	nxt:;
	if(vv<=0){
	    return vector<int>(1,-1);
	}
	vector<int>inn;
	vector<int>outt;
	for(int i=0;i<vec.size();i++){
		int v = vec[i];
		if(v == 1 || find(vv) != find(v) || v == vv) continue;
		if(POSL(edge[v],vv) != edge[v].size() && edge[v][POSL(edge[v],vv)] == vv){
			inn.pb(v); //cout<<v<<"i"<<endl;
		}
		else{
			outt.pb(v); //cout<<v<<"o"<<endl;
		}
	}
	for(int i=0;i<inn.size();i++){
		for(int j=0;j<outt.size();j++){
			int a = inn[i],b = outt[j];
			if(POSL(edge[a],b) != edge[a].size() && edge[a][POSL(edge[a],b)] == b){
				vector<int>ret;
				ret.pb(1);
				ret.pb(vv);
				ret.pb(a);
				ret.pb(b);
				ret.pb(vv);
				ret.pb(n);
				return ret;
			}
		}
	}
	{
	    return vector<int>(1,-1);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	init();
	for(int i=0;i<m;i++){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
		unite(a,b);
		if(a==1) c[b] = 1;
		if(b==1) c[a] = 1;
	}
	for(int i=0;i<300005;i++) dist[i] = INF;
	ans = INF;
	queue<int>que;
	que.push(1);
	dist[1] = 0;
	while(!que.empty()){
		int q = que.front(); que.pop();
		if(used[q]) continue;
		used[q] = true;
		for(int i=0;i<edge[q].size();i++)
		{
			int to = edge[q][i];
			if(!used[to]){
				dist[to] = min(dist[to],dist[q]+1);
				que.push(to);
			}
		}
	}
	ans = min(ans,dist[n]);
	if(ans <= 3){
		vector<int>V;
		int cur = n;
		while(1){
			V.pb(cur);
			if(cur == 1){
				break;
			}
			for(int i=0;i<edge[cur].size();i++){
				int to = edge[cur][i];
				if(dist[to]+1 == dist[cur]){
					cur = to; break;;
				}
			}
		}
		reverse(V.begin(),V.end());
		printf("%d\n",ans);
		rep(i,V.size()) printf("%d ",V[i]);
		puts("");
		return 0;
	}
	bool good = false;
	vector<int>L;
	L.pb(1);
	for(int i=2;i<=n;i++){
		if(same(1,i)){
			L.pb(i);
		}
		if(same(1,i) && !c[i]){
			good = true;
		}
	}
	if(good){
		vector<int>V = way1();
		printf("%d\n",V.size()-1);
		rep(i,V.size()) printf("%d ",V[i]);
		puts("");
		return 0;
	}
	vector<int>V = way2(L);
	if(V.size() == 1)
	{
		puts("-1");
	}
	else{
		printf("%d\n",V.size()-1);
		rep(i,V.size()) printf("%d ",V[i]);
		puts("");
		return 0;
	}
}