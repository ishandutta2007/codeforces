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

const int MAXN=100010;

int g[MAXN], g_lnk[MAXN*2], g_nxt[MAXN*2];
int n, k, p;

LL a[MAXN], s[MAXN], t[MAXN];

void dfs(int dep, int x, int fa) {
	a[dep]++;
	for(int e=g[x]; e; e=g_nxt[e])
		if(g_lnk[e]!=fa)
			dfs(dep+1, g_lnk[e], x);
}

int main() {
	scanf("%d%d%d",&n,&k,&p);
	fillchar(g, 0);
	forint(i, 1, n-1) {
		int a, b; scanf("%d%d", &a,&b);
		int e=i*2-1;
		g_lnk[++e]=b, g_nxt[e]=g[a], g[a]=e;
		g_lnk[++e]=a, g_nxt[e]=g[b], g[b]=e;
	}

	fillchar(a, 0);
	dfs(0, 1, 0);
	a[0]=0;
	s[0]=0; forint(i, 1, n) s[i]=a[i]+s[i-1];
	t[0]=0; forint(i, 1, n) t[i]=t[i-1]+LL(n-i)*a[i];
	LL ans=0;
	for(int i=n, j=n; j>=1; --j) {
		while(i>0) {
			LL sum=s[j]-s[i-1];
			if(sum>k) break;
			LL st=t[j]-t[i-1];
			st-=(n-j)*sum;
			if(st>p) break;
			--i;
		}
		LL sum=s[j]-s[i];
		LL st=t[j]-t[i]-(n-j)*sum;
		LL addi=min(a[i], LL(k)-sum);
		if(i<j) addi=min(addi, LL(p-st)/LL(j-i));
		ans=max(ans, sum+addi);
	}
	printf("%I64d\n", (ans));

	return 0;
}