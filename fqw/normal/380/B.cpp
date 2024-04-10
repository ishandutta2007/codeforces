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

const int MAXN=7070;
vector<pair<PII,int> > a[MAXN];

int cont(int x) {
	int ans=x;
	for(int i=1; i<=x; i<<=1) ++ans;
	return ans;
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	while(m--) {
		int op; scanf("%d", &op);
		if(op==1) {
			int t, l, r, x;
			scanf("%d%d%d%d", &t,&l,&r,&x);
			a[t].PB(MP(MP(l,r), x));
		} else {
			int t, v; scanf("%d%d", &t,&v);
			int l=v, r=v;
			set<int> ans;
			while(t<MAXN) {
				forn(i, a[t].size()) {
					if(r<a[t][i].fi.fi) continue;
					if(l>a[t][i].fi.se) continue;
					ans.insert(a[t][i].se);
				}
				l=cont(l-1)+1;
				r=cont(r);
				++t;
			}
			printf("%d\n", ans.size());
		}
	}
	return 0;
}