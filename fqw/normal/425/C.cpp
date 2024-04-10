#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <vector>
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
typedef vector<int> VI;
typedef pair<double,double> PDD;

const int MAXN=100010;
const int MAXV=100010;
const int MAXT=333;

int a[MAXN], n;
int b[MAXN], m;
int s, e;

VI ind[MAXV];
int p[MAXN][MAXT];

int main() {
	scanf("%d%d%d%d", &n,&m,&s,&e);
	forn(i, MAXV) ind[i].clear();
	forint(i, 1, n) scanf("%d", a+i), ind[a[i]].PB(i);
	forint(i, 1, m) scanf("%d", b+i);

	int mt=s/e;
	int ans=0;
	forint(t, 1, mt) p[0][t]=n+1;
	p[0][0]=0;

	forint(j, 1, m) {
		forint(t, 0, mt) p[j][t]=p[j-1][t];
		forint(t, 0, mt-1) {
			//if(p[j-1][t]>n) break;
			VI::iterator it=lower_bound(ind[b[j]].begin(), ind[b[j]].end(), p[j-1][t]+1);
			if(it!=ind[b[j]].end()) p[j][t+1]=min(p[j][t+1], *it);
		}
		forint(t, 1, mt) {
			int i=p[j][t]; if(i>n) break;
			int rest=s-(i+j);
			int cnt=rest/e;
			ans=max(ans, min(cnt, t));
		}
	}
	printf("%d\n", ans);
	return 0;
}