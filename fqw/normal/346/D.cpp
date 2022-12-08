#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int,int> PII;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
template<class T> bool setmin(T &a, T b) {
	if(b<a) {a=b; return true;} else return false;
}
template<class T> bool setmax(T &a, T b) {
	if(b>a) {a=b; return true;} else return false;
}
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))
int gcd(int a, int b) {
	return b==0 ? a : gcd(b,a%b);
}

const int MAXN=1000010;
int g[MAXN], g_lnk[MAXN], g_nxt[MAXN];
int n, m, s, t;

int deg[MAXN];
int f[MAXN], maxval;
VI lst, lst2;

void solve() {
	fillchar(f, 50); maxval=f[0];

	lst.clear(); lst.PB(t); f[t]=0;
	for(int curans=0; ; ++curans) {
		if(lst.size()==0) {
			printf("-1\n");
			return;
		}
		forn(i, lst.size()) {
			int y=lst[i];
			for(int e=g[y]; e; e=g_nxt[e]) {
				int x=g_lnk[e];
				if(f[x]==maxval && --deg[x]==0) {
					f[x]=curans;
					lst.PB(x);
				}
			}
		}
		lst2.clear();
		forn(i, lst.size()) {
			if(lst[i]==s) {
				printf("%d\n", curans);
				return;
			}
			int y=lst[i];
			for(int e=g[y]; e; e=g_nxt[e]) {
				int x=g_lnk[e];
				if(f[x]==maxval) {
					f[x]=curans+1;
					lst2.PB(x);
				}
			}
		}
		lst=lst2;
	}
}

int main() {
	scanf("%d%d", &n,&m);
	int e=0; fillchar(g, 0);
	fillchar(deg, 0);
	forint(i, 1, m) {
		int a, b; scanf("%d%d", &a,&b);
		++deg[a];
		//g_lnk[++e]=b, g_nxt[e]=g[a], g[a]=e;
		g_lnk[++e]=a, g_nxt[e]=g[b], g[b]=e;
	}
	scanf("%d%d", &s,&t);
	solve();

	return 0;
}