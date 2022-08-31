#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
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

int n,p[200005];
vector<int>edge[200005];
int up[20][200005],dep[200005];
int q;
P ar[400005];
int pos[200005],id;
P mn[20][400005];
int sz[400005];
void prepare(){
	rep(i,id) mn[0][i] = ar[i];
	rep(j,18){
		rep(i,id){
			if(i+(1<<j) >= id) mn[j+1][i] = mn[j][i];
			else mn[j+1][i] = min(mn[j][i],mn[j][i+(1<<j)]);
		}
	}
	repn(i,400005){
		rep(j,20){
			if((1<<j) <= i && i <= (2<<j)){
				sz[i] = j; break;
			}
		}
	}
}
int lca(int a,int b){
	int len = max(pos[a],pos[b]) - min(pos[a],pos[b]) + 1;
	P p = min(mn[sz[len]][min(pos[a],pos[b])], mn[sz[len]][max(pos[a],pos[b])-(1<<sz[len])+1]);
    return p.sc;
}
int dist(int a,int b){
	return dep[a]+dep[b]-2*dep[lca(a,b)];
}
bool on(int x,int y,int z){
	return dist(x,y) == dist(x,z)+dist(z,y); 
}

P mrg(P a,P b){
	if(a.fi == -1 || b.fi == -1) return mp(-1,-1);
	if(a.fi == 0) return b;
	if(b.fi == 0) return a;
	
	vector<int>V; V.resize(4,0);
	V[0] = a.fi; V[1] = a.sc; V[2] = b.fi; V[3] = b.sc;
	P1 mx = mp(-1,mp(0,0));
	rep(x,4) for(int y=x+1;y<4;y++){
		mx = max(mx,mp(dist(V[x],V[y]),mp(V[x],V[y])));
	}
	rep(x,4){ if(V[x] != mx.sc.fi && V[x] != mx.sc.sc && !on(mx.sc.fi,mx.sc.sc,V[x])) return mp(-1,-1);}
	return mx.sc;
}

struct seg{
	P seg[(1<<19)];
	void init(){
		rep(i,(1<<19)) seg[i] = mp(-1,-1);
	}
	void update(int pos,int v){
		pos += (1<<18)-1;
		seg[pos] = mp(v,v);
		while(pos){
			pos = (pos-1)/2;
			seg[pos] = mrg(seg[pos*2+1],seg[pos*2+2]);
		}
	}
	int query(int k,int l,int r,P zan){
		if(mrg(zan,seg[k]).fi != -1) return r-l+1;
		
		if(l == r) return 0;
		
		if(mrg(zan,seg[k*2+1]).fi != -1){
			zan = mrg(zan,seg[k*2+1]);
			return (r-l+1)/2 + query(k*2+2,(l+r)/2+1,r,zan);
		}
		else return query(k*2+1,l,(l+r)/2,zan);
	}
}kaede;

void dfs(int v,int u,int d){
	pos[v] = id;
	ar[id++] = mp(d,v);
	up[0][v] = u; dep[v] = d;
	rep(i,edge[v].size()){
		dfs(edge[v][i],v,d+1);
		ar[id++] = mp(d,v);
	}
}

int main(){
	scanf("%d",&n);
	repn(i,n) scanf("%d",&p[i]);
	rep(i,n-1){
		int d; scanf("%d",&d);
		edge[d].pb(i+2);
	}
	dfs(1,-1,0);
	rep(j,19) repn(i,n){
		if(up[j][i] == -1) up[j+1][i] = -1;
		else up[j+1][i] = up[j][up[j][i]];
	}
	prepare();
	kaede.init();
	repn(i,n){
		kaede.update(p[i],i);
	}
	
	scanf("%d",&q);
	rep(i,q){
		int t; scanf("%d",&t);
		if(t == 2){
			printf("%d\n",kaede.query(0,0,(1<<18)-1,mp(0,0)));
		}
		else{
			int a,b; scanf("%d%d",&a,&b);
			kaede.update(p[a],b);
			kaede.update(p[b],a);
			swap(p[a],p[b]);
		}
	}
}