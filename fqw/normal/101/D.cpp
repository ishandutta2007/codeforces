#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long LL;

const int MAXN=100010;

int g[MAXN], g_lnk[MAXN*2], g_t[MAXN*2], g_nxt[MAXN*2];
int n;
LL sz[MAXN], tl[MAXN];
LL ans;

struct Item {
	LL c, d;
	friend bool operator <(const Item &a, const Item &b) {
		return b.c*a.d < b.d*a.c;
	}
} lst[MAXN];
int len;

void dfs(int x, int fa) {
	for(int i=g[x]; i>0; i=g_nxt[i])
		if(g_lnk[i]!=fa)
			dfs(g_lnk[i], x);
	len=0;
	sz[x]=1, tl[x]=0;
	for(int i=g[x]; i>0; i=g_nxt[i])
		if(g_lnk[i]!=fa) {
			int y=g_lnk[i];
			sz[x]+=sz[y];
			tl[x]+=tl[y]+g_t[i]*2;
			ans+=g_t[i]*sz[y];
			++len;
			lst[len].c=sz[y];
			lst[len].d=tl[y]+g_t[i]*2;
		}
	sort(lst+1, lst+len+1);
	LL sd=0;
	for(int i=1; i<=len; ++i) {
		ans+=lst[i].c*sd;
		sd+=lst[i].d;
	}
}

int main() {
	scanf("%d", &n);
	memset(g, 0, sizeof(g));
	for(int i=1, e=0; i<=n-1; ++i) {
		int a, b, t; scanf("%d%d%d", &a,&b,&t);
		g_lnk[++e]=b, g_t[e]=t, g_nxt[e]=g[a], g[a]=e;
		g_lnk[++e]=a, g_t[e]=t, g_nxt[e]=g[b], g[b]=e;
	}
	ans=0;
	dfs(1, 0);
	double ret=(double)ans/(double)(n-1);
	printf("%.7lf\n", ret);
	return 0;
}