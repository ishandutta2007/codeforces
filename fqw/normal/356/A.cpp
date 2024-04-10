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

const int MAXN=300010;

set<int> b;
int k[MAXN];
int n, m;

int main() {
	fillchar(k, 0);
	scanf("%d%d", &n,&m);
	b.clear();
	forint(i, 1, n) b.insert(i);
	while(m--) {
		int l, r, x;
		scanf("%d%d%d", &l,&r,&x);
		while(1) {
			set<int>::iterator it=b.lower_bound(l);
			if(it==b.end()) break;
			if(*it>r) break;
			if(*it!=x) k[*it]=x;
			b.erase(it);
		}
		b.insert(x);
	}
	forint(i, 1, n) printf("%d%c", k[i], i<n?' ':'\n');
	return 0;
}