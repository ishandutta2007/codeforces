// 16:14
#include <cassert>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
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
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //
const int MAXN=4010;
const int MAXV=4010;
pair<int, PII> a[MAXN];
int n, p;

struct DPResult {
	int f[MAXV];
	DPResult() { fillchar(f, 0); }
	void push(PII x) {
		forndown(i, MAXV-x.fi)
			setmax(f[i+x.fi], f[i]+x.se);
	}
	friend int merge(const DPResult &a, const DPResult &b, int v) {
		int ans=0;
		forint(i, 0, v) setmax(ans, a.f[i]+b.f[v-i]);
		return ans;
	}
} dl[MAXN], dr[MAXN];
int st[MAXN], en[MAXN];

int main() {
	scanf("%d%d", &n,&p);
	forint(i, 1, n) scanf("%d%d%d", &a[i].se.fi,&a[i].se.se,&a[i].fi);
	sort(a+1, a+n+1);
	
	for(int i=1, cp=p, j; i<=n; i=j+1, cp+=p) {
		if(a[i].fi>cp) {
			j=i-1; continue;
		}
		for(j=i; j<n && a[j+1].fi<=cp; ++j);
		forint(k, i, j) st[k]=i, en[k]=j;
	}
	forint(i, 1, n) {
		if(st[i]!=i) dl[i]=dl[i-1];
		dl[i].push(a[i].se);
	}
	forintdown(i, n, 1) {
		if(en[i]!=i) dr[i]=dr[i+1];
		dr[i].push(a[i].se);
	}

	int q; scanf("%d", &q);
	while(q--) {
		int r, b; scanf("%d%d", &r,&b);
		int l=r-p+1;
		int i=1; while(i<=n && a[i].fi<l) ++i;
		int j=n; while(j>=1 && a[j].fi>r) --j;
		if(i>j) {
			printf("0\n"); continue;
		}
		if(st[i]==st[j]) {
			if(st[i]==i) {
				printf("%d\n", dl[j].f[b]);
				continue;
			}
			if(en[j]==j) {
				printf("%d\n", dr[i].f[b]);
				continue;
			}
			assert(false);
		}
		assert(st[j]==en[i]+1);
		int ans=merge(dr[i], dl[j], b);
		printf("%d\n", ans);
	}

	return 0;
}