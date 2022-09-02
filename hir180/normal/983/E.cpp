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
int n,m,q,dep[200005],up[200005],go[200005][20],num[200005],nxt,num2[200005];
vector<int>edge[200005];
vector<int>val[(1<<19)];
int *seg[(1<<19)];
int sz[(1<<19)];
int lca[200005][20];
void dfs(int v,int u){
	num[v] = nxt++;
	dep[v] = 0;
	if(u != -1) dep[v] = dep[u]+1;
	lca[v][0] = u;
	for(int i=0;i<edge[v].size();i++){
		if(edge[v][i]==u) continue;
		dfs(edge[v][i],v);
	}
	num2[v] = nxt-1;
}

int calc_lca(int s,int t){
	if(dep[s]>dep[t]) swap(s,t);
	rep(i,19){
		if((((dep[t]-dep[s])>>i)&1)){
			t = lca[t][i];
		}
	}
	if(s==t) return s;
	for(int i=19;i>=0;i--){
		if(lca[s][i]!=lca[t][i]){
			s = lca[s][i];
			t = lca[t][i];
		}
	}
	return lca[s][0];
}
int aa[200005],bb[200005];
int uu[200005],vv[200005];
void make(int x,int y){
	x += (1<<18)-1;
	while(1){
		val[x].pb(y);
		if(x == 0) return;
		x = (x-1)/2;
	}
}
void make_seg(){
	for(int i=0;i<(1<<19);i++){
		if(val[i].empty()) continue;
		int f = 1;
		while(f<val[i].size()) f*=2;
		seg[i] = new int[2*f];
		sz[i] = 2*f;
		for(int ii=0;ii<2*f;ii++) seg[i][ii] = 0;
	}
}
void update(int a,int v,int x){
	a += (int)(sz[x]/2)-1;
	while(1){
		seg[x][a] = max(seg[x][a],v);
		if(a == 0) return ;
		a = (a-1)/2;
	}
}
void init(int x,int y,int v){
	x += (1<<18)-1;
	while(1){
		int a = POSL(val[x],y);
		//seg[x]update(a,v)
		update(a,v,x);
		if(x == 0) return;
		x = (x-1)/2;
	}
}
int query2(int a,int b,int k,int l,int r,int cur){
	if(r<a || b<l || a>b) return 0;
	if(a<=l && r<=b){
		return seg[cur][k];
	}
	return max(query2(a,b,k*2+1,l,(l+r)/2,cur),query2(a,b,k*2+2,(l+r)/2+1,r,cur));
}
int query(int a,int b,int c,int d,int k,int l,int r){
	if(r<a || b<l || a>b || c>d) return 0;
	if(a<=l && r<=b){
		int f = POSL(val[k],c);
		int g = POSU(val[k],d);
		return query2(f,g-1,0,0,(int)(sz[k]/2)-1,k);
	}
	return max(query(a,b,c,d,k*2+1,l,(l+r)/2),query(a,b,c,d,k*2+2,(l+r)/2+1,r));
}
int query(int a,int b,int c,int d){
	return query(a,b,c,d,0,0,(1<<18)-1);
}
int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int a; scanf("%d",&a);
		edge[i].pb(a);
		edge[a].pb(i);
	}
	dfs(1,-1);
	for(int i=0;i<19;i++){
		for(int j=1;j<=n;j++){
			if(lca[j][i] == -1) lca[j][i+1] = -1;
			else lca[j][i+1] = lca[lca[j][i]][i];
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&aa[i],&bb[i]);
		int a = aa[i],b = bb[i];
		int c = num[a],d = num[b];
		if(c>d) swap(c,d);
		make(c,d);
	//	make(d,c);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&uu[i],&vv[i]);
	}
	for(int i=0;i<(1<<19);i++){
		SORT(val[i]);
		ERASE(val[i]);
	}
	make_seg();
	for(int i=1;i<=m;i++){
		int a = aa[i],b = bb[i];
		int c = num[a],d = num[b];
		int e = calc_lca(a,b);
		int f = dep[e];
		//(c,d)(d,c)INF-f
		if(c>d) swap(c,d);
		init(c,d,INF-f);
	//	if(d != c) init(d,c,INF-f);
	}
	for(int i=1;i<=n;i++){
		int k = 0;
		k = max(k,query(num[i],num2[i],num2[i]+1,n-1));
		k = max(k,query(0,num[i]-1,num[i],num2[i]));
		if(k < 5e8) go[i][0] = -1;
		else{
			int d = INF-k;
			int e = dep[i];
			assert(d<e);
			e -= d;
			int cur = i;
			for(int i=19;i>=0;i--){
				if(((e>>i)&1)){
					cur = lca[cur][i];
				}
			}
			assert(dep[cur] == d);
			go[i][0] = cur;
		}
	}
	for(int i=0;i<19;i++){
		for(int j=1;j<=n;j++){
			if(go[j][i] == -1) go[j][i+1] = -1;
			else go[j][i+1] = go[go[j][i]][i];
		}
	}
	for(int i=1;i<=q;i++){
		int a = uu[i],b = vv[i];
		if(dep[a] > dep[b]) swap(a,b);
		int e = calc_lca(a,b);
		if(e == a){
		    int ans = 0;
			for(int i=19;i>=0;i--){
				if(go[b][i] == -1 || dep[go[b][i]] <= dep[e]) continue;
				b = go[b][i];
				ans += (1<<i);
			}
			if(go[b][0] == -1 || dep[go[b][0]] > dep[e]){
				puts("-1");
			}
			else{
				printf("%d\n",ans+1);
			}
			continue;
		}
		int ans = 0,x,y;
		for(int i=19;i>=0;i--){
			if(go[a][i] == -1 || dep[go[a][i]] <= dep[e]) continue;
			a = go[a][i];
			ans += (1<<i);
		}
		if(go[a][0] == -1 || dep[go[a][0]] > dep[e]){
			puts("-1"); continue;
		}
		for(int i=19;i>=0;i--){
			if(go[b][i] == -1 || dep[go[b][i]] <= dep[e]) continue;
			b = go[b][i];
			ans += (1<<i);
		}
		if(go[b][0] == -1 || dep[go[b][0]] > dep[e]){
			puts("-1"); continue;
		}
		x = a,y = b;
		int kk = query(num[x],num2[x],num[y],num2[y]);
		if(kk<5e8){
			kk = max(kk,query(num[y],num2[y],num[x],num2[x]));
		}
		if(kk < 5e8){
			printf("%d\n",ans+2);
		}
		else{
			printf("%d\n",ans+1);
		}
	}
}