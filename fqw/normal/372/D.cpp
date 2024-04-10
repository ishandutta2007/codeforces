// code:	19:40 - 19:50	-> WA
#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;

const int MAXN=100010;
const int MAXLog=20;
#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)

int g[MAXN], g_lnk[MAXN*2], g_nxt[MAXN*2];
int n, limit;

int ind[MAXN], lst[MAXN], tt;
int dep[MAXN];
int up[MAXN][MAXLog];

void dfs(int x, int f) {
	ind[x]=++tt; lst[tt]=x;
	up[x][0]=f;
	dep[x]=dep[f]+1;
	for(int i=0; up[x][i]>0; ++i)
		up[x][i+1]=up[up[x][i]][i];
	for(int i=g[x]; i>0; i=g_nxt[i]) {
		int y=g_lnk[i]; if(y==f) continue;
		dfs(y, x);
	}
}

int lca(int a, int b) {
	for(int i=MAXLog-1; i>=0; --i) {
		if(dep[up[a][i]]>=dep[b]) a=up[a][i];
		if(dep[up[b][i]]>=dep[a]) b=up[b][i];
	}
	for(int i=MAXLog-1; i>=0; --i)
		if(up[a][i]!=up[b][i])
			a=up[a][i], b=up[b][i];
	if(a!=b) a=up[a][0];
	return a;
}

set<int> s;

int get(int x) {
	set<int>::iterator it=s.lower_bound(ind[x]);
	int ri=(it==s.end() ? *s.begin() : *it);
	int le=(it==s.begin() ? *s.rbegin() : *--it);
	int y=lst[le], z=lst[ri];
	//printf("get x=%d y=%d z=%d\n",x,y,z);
	return dep[x]-dep[lca(x,y)]-dep[lca(x,z)]+dep[lca(y,z)];
}

int main() {
	scanf("%d%d", &n,&limit);
	int e=0;
	forint(i, 1, n-1) {
		int a, b; scanf("%d%d", &a,&b);
		g_lnk[++e]=b, g_nxt[e]=g[a], g[a]=e;
		g_lnk[++e]=a, g_nxt[e]=g[b], g[b]=e;
	}
	memset(up, 0, sizeof(up));
	dep[0]=0;
	tt=0;
	dfs(1, 0);

	int ans=1;
	int le=1;
	int size=1;
	s.insert(ind[1]);
	forint(ri, 2, n) {
		size+=get(ri); s.insert(ind[ri]);
		while(size>limit) {
			//printf("le=%d ri=%d sz=%d\n",le,ri,size);
			s.erase(ind[le]);
			size-=get(le);
			++le;
		}
		ans=max(ans, ri-le+1);
	}
	printf("%d\n", ans);
	
	return 0;
}