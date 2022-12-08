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

const int MAXN=1010;

struct Problem {
	int a[MAXN][MAXN];
	int up[MAXN][MAXN], dn[MAXN][MAXN];
	int n, m;

	void init(int _n, int _m) {
		n=_n, m=_m;
	}
	void flip(int i, int j) {
		a[i][j]^=1;
		pre_col(j);
	}
	void set(int i, int j, int v) {
		a[i][j]=v;
	}
	void pre_col(int j) {
		up[0][j]=0;
		forint(i, 1, n) {
			up[i][j]=up[i-1][j];
			if(a[i][j]==0) up[i][j]=i;
		}
		dn[n+1][j]=n+1;
		forintdown(i, n, 1) {
			dn[i][j]=dn[i+1][j];
			if(a[i][j]==0) dn[i][j]=i;
		}
	}
	void pre() {
		forint(j, 1, m) pre_col(j);
	}
	int query(int i, int j) {
		int ans=0;
		forn(tt, 2) {
			int u=up[i][j], d=dn[i][j];
			for(int cj=j; cj>=1 && cj<=m; ) {
				u=max(u, up[i][cj]);
				d=min(d, dn[i][cj]);
				if(u>=i || d<=i) break;
				ans=max(ans, (d-u-1)*(abs(cj-j)+1));
				if(tt==0) ++cj; else --cj;
			}
		}
		return ans;
	}
} p1, p2;

int main() {
	int n, m; scanf("%d%d", &n,&m);
	int q; scanf("%d", &q);
	p1.init(n, m);
	p2.init(m, n);
	forint(i, 1, n) forint(j, 1, m) {
		int v; scanf("%d", &v);
		p1.set(i, j, v);
		p2.set(j, i, v);
	}
	p1.pre();
	p2.pre();
	while(q--) {
		int t, x, y; scanf("%d%d%d", &t,&x,&y);
		if(t==1) {
			p1.flip(x, y);
			p2.flip(y, x);
		} else {
			int a1=p1.query(x, y);
			int a2=p2.query(y, x);
			int ans=max(a1, a2);
			printf("%d\n", ans);
		}
	}
	
	return 0;
}