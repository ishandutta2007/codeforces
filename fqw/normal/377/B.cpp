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

const int MAXN=100010;

PII a[MAXN];
pair<PII,int> b[MAXN];
int n, m, s;

int ans[MAXN];

bool check(int d) {
	VI lst;
	for(int i=m; i>=1; i-=d) lst.PB(a[i].fi);

	set<PII> h;
	VI cho;
	int j=n;
	forn(i, lst.size()) {
		while(j>=1 && b[j].fi.fi>=lst[i]) {
			h.insert(MP(b[j].fi.se, j));
			--j;
		}
		if(h.size()==0) return false;
		int j=h.begin()->se;
		h.erase(h.begin());
		cho.PB(j);
	}

	LL sum=0;
	forn(i, cho.size()) sum+=b[cho[i]].fi.se;
	if(sum>LL(s)) return false;

	for(int i=m, j=0; i>=1; i-=d, ++j) {
		forint(k, max(1,i-d+1), i) ans[a[k].se]=b[cho[j]].se;
	}
	return true;
}

int main() {
	scanf("%d%d%d", &n,&m,&s);
	forint(i, 1, m) scanf("%d", &a[i].fi), a[i].se=i;
	forint(i, 1, n) scanf("%d", &b[i].fi.fi), b[i].se=i;
	forint(i, 1, n) scanf("%d", &b[i].fi.se);
	sort(a+1, a+m+1);
	sort(b+1, b+n+1);
	int le=1, ri=m;
	while(le<ri) {
		int mid=(le+ri)/2;
		if(check(mid)) ri=mid;
			else le=mid+1;
	}
	if(check(le)) {
		printf("YES\n");
		forint(i, 1, m) printf("%d ", ans[i]);
		printf("\n");
	} else printf("NO\n");
	return 0;
}