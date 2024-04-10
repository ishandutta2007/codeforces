#include <bits/stdc++.h>
#define mod 998244353
#define N 100050
using namespace std;
typedef long long LL;

struct Edge{int a,b,v;}e[N];
bool cmp(Edge p1, Edge p2) {return p1.v < p2.v;}

int n,m,k,x[N],mark[N],fa[N],cnt;

int gf(int x) {
	return fa[x] == x ? x : fa[x] = gf(fa[x]);
}

inline int rd() {int r;scanf("%d",&r);return r;}
int main() {
	n = rd(), m = rd(), k = rd();
	for (int i=1;i<=k;i++) x[i] = rd(), mark[x[i]] = 1;
	for (int i=1;i<=m;i++)
		e[i].a = rd(), e[i].b = rd(), e[i].v = rd();
	sort(e+1, e+m+1, cmp);
	for (int i=1;i<=n;i++) fa[i] = i;
	for (int i=1;i<=m;i++) {
		int a = e[i].a, b = e[i].b, v = e[i].v;
		if (gf(a) == gf(b)) continue;
		int cur = mark[gf(a)] || mark[gf(b)];
		if (mark[gf(a)] && mark[ gf(b) ]) cnt++;
		if (cnt == k-1) {
			for (int i=1;i<=k;i++) printf("%d%c",v,i==k?'\n':' ');
			return 0;
		}
		fa[ gf(a) ] = gf(b);
		mark[ gf(b) ] = cur;
	}
	return 0;
}