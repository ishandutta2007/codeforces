#include <bits/stdc++.h>
#define maxn 500005
#define mp std::make_pair
int n,q,k,z[maxn],ans[maxn];
std::vector<std::pair<int,int> > inc[maxn<<2];
std::vector<std::pair<int,std::pair<int,int> > > start[maxn];
 
namespace dsu {
	int fa[maxn],size[maxn],a[maxn<<4],b[maxn<<4],c[maxn<<4],d[maxn<<4],sz=0;
	int getf(int x) { return fa[x] ? getf(fa[x]) : x; }
	void reset() { for (int i = 1; i <= n; ++ i) size[i] = 1; }
	void cancel() {
		fa[a[sz]] = b[sz];
		size[c[sz]] = d[sz];
		sz--;
	}
	void merge(int x,int y) {
		int f1 = getf(x), f2 = getf(y);
		if (f1 == f2) return;
		if (size[f1] < size[f2]) std::swap(f1,f2);
		a[++sz] = f2; b[sz] = fa[f2]; c[sz] = f1; d[sz] = size[f1];
		fa[f2] = f1; size[f1] += size[f2];
	} int cnt(int x) { return size[getf(x)]; }
}

void add_edge(int l,int r,int L,int R,int x,int y,int rt) {
//	if (L == 1 && R == q) printf("add %d %d [%d %d]\n",x,y,l,r);
	if (l>R||r<L) return;
	if (l<=L&&R<=r) {
		inc[rt].push_back(mp(x,y));
		return;
	} add_edge(l,r,L,(L+R)>>1,x,y,rt<<1);
	add_edge(l,r,((L+R)>>1)+1,R,x,y,rt<<1|1);
}

void dfs(int rt,int l,int r) {
	int rec = dsu::sz;
	for (auto p:inc[rt]) {
		dsu::merge(p.first,p.second);
	//	printf("inc %d %d at [%d %d]\n",p.first,p.second,l,r);
	}
	if (l == r) { if (z[l]) ans[l] = dsu::cnt(z[l]); }
	else {
		dfs(rt<<1,l,(l+r)>>1);
		dfs(rt<<1|1,((l+r)>>1)+1,r);
	} while (dsu::sz > rec) dsu::cancel();
}

void work(int i,int E) {
	if (i-k>=1) {
		for (auto p:start[i-k]) 
			add_edge(p.first,E-1,1,q,p.second.first,p.second.second,1);
		start[i-k].clear();
	} 
}

int main() {
	scanf("%d%d%d",&n,&q,&k);
	dsu::reset();
	int day = 1;
	for (int i = 1; i <= q; ++ i) {
		int opt;
		scanf("%d",&opt);
		work(day,i);
				
		if (opt == 3) day ++;
		if (opt == 2) { scanf("%d",&z[i]);  }
		if (opt == 1) {
			int x,y;
			scanf("%d%d",&x,&y);
			start[day].push_back(mp(i,mp(x,y)));
		}
	} for (int i = 1; i <= q; ++ i) 
		for (auto p:start[i]) 
			add_edge(p.first,q,1,q,p.second.first,p.second.second,1);
	dfs(1,1,q);
	for (int i = 1; i <= q; ++ i) if (z[i]) printf("%d\n",ans[i]);
	return 0;
}