#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

#define forint(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define forintdown(i, a, b) for(int i=int(a); i>=int(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<PII> VPI;
typedef pair<double,double> PDD;

const int MAXN=100010;

int g[MAXN], g_lnk[MAXN*2], g_nxt[MAXN*2];
int n;
int va[MAXN], vb[MAXN];

int ans[MAXN], ansl;
void dfs(int x, int fa, int pa, int pb) {
	if((va[x]^pa)!=vb[x]) {
		ans[++ansl]=x;
		pa^=1;
	}
	for(int e=g[x]; e; e=g_nxt[e]) {
		int y=g_lnk[e]; if(y==fa) continue;
		dfs(y, x, pb, pa);
	}
}

int main() {
	scanf("%d", &n);
	fillchar(g, 0); int e=0;
	forint(i, 1, n-1) {
		int a, b; scanf("%d%d",&a,&b);
		g_lnk[++e]=b, g_nxt[e]=g[a], g[a]=e;
		g_lnk[++e]=a, g_nxt[e]=g[b], g[b]=e;
	}
	forint(i, 1, n) scanf("%d", &va[i]);
	forint(i, 1, n) scanf("%d", &vb[i]);

	ansl=0;
	dfs(1, 0, 0, 0);
	printf("%d\n", ansl); forint(i, 1, ansl) printf("%d\n", ans[i]);

	return 0;
}