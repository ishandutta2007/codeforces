#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) forint(i, 0, (n)-1)
#define forndown(i, n) forintdown(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPI;
#define MP make_pair
#define PB push_back
#define fi first
#define se second

const int MAXNP=22;
const int MAXN=(1<<20)+10;

LL c1[MAXNP], c2[MAXNP];
int a[MAXN];
int n, np;

VI cal(int lev, int l, int r) {
	if(lev==0) {
		VI v; v.PB(a[l]);
		return v;
	}
	int m=(l+r)/2;
	VI x=cal(lev-1, l, m);
	VI y=cal(lev-1, m+1, r);
	VI z;
	size_t i=0, j=0;
	while(i<x.size() && j<y.size()) {
		int tx=0, ty=0;
		int cur=min(x[i], y[j]);
		while(i<x.size() && x[i]==cur) ++i, ++tx;
		while(j<y.size() && y[j]==cur) ++j, ++ty;
		c1[lev]+=LL(ty)*LL(x.size()-i);
		c2[lev]+=LL(tx)*LL(y.size()-j);
		forn(k, tx+ty) z.PB(cur);
	}
	while(i<x.size()) z.PB(x[i++]);
	while(j<y.size()) z.PB(y[j++]);
	return z;
}

int main() {
	scanf("%d", &np); n=1<<np;
	forint(i, 1, n) scanf("%d", a+i);
	fillchar(c1, 0);
	fillchar(c2, 0);
	cal(np, 1, n);
	int q; scanf("%d", &q);
	while(q--) {
		int k; scanf("%d", &k);
		forint(i, 0, k) swap(c1[i], c2[i]);
		LL ans=0;
		forint(i, 0, np) ans+=c1[i];
		printf("%I64d\n", ans);
	}
	return 0;
}