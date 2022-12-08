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

map<int, VI*> tx, ty, te;
PII a[MAXN];
int n;

const int MH=1000000+7;
int h[MH], hx[MH], hy[MH], hnxt[MH], hn;

bool find(int x, int y) {
	int k=(int)((LL(x)*200000LL+y)%MH);
	for(int i=h[k]; i; i=hnxt[i])
		if(hx[i]==x && hy[i]==y)
			return true;
	return false;
}

void add(int x, int y) {
	int k=(int)((LL(x)*200000LL+y)%MH);
	int i=++hn;
	hx[i]=x, hy[i]=y; hnxt[i]=h[k]; h[k]=i;
}

int main() {
	scanf("%d", &n);
	forint(i, 1, n) scanf("%d%d", &a[i].fi,&a[i].se);
	sort(a+1, a+n+1);

	tx.clear();
	ty.clear();
	te.clear();
	hn=0; fillchar(h, 0);
	int ans=0;
	forint(i, 1, n) {
		int x=a[i].fi, y=a[i].se;
		VI *cx=tx[x]; if(cx==NULL) cx=tx[x]=new VI();
		VI *cy=ty[y]; if(cy==NULL) cy=ty[y]=new VI();
		if(cx->size()<cy->size()) {
			forn(i, cx->size()) {
				int y0=(*cx)[i];
				int x0=x-(y-y0);
				if(find(x0, y) && find(x0, y0))
					++ans;
			}
		} else {
			forn(i, cy->size()) {
				int x0=(*cy)[i];
				int y0=y-(x-x0);
				if(find(x, y0) && find(x0, y0))
					++ans;
			}
		}
		cx->PB(y);
		cy->PB(x);
		add(x, y);
	}
	printf("%d\n", ans);
	return 0;
}