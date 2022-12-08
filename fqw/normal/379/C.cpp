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

const int MAXN=3*100000+1000;

int a[MAXN], b[MAXN];
PII lst[MAXN]; int n;
map<int,int> nxt;

int get_nxt(int x) {
	if(nxt.find(x)==nxt.end())
		return x;
	return nxt[x]=get_nxt(nxt[x]);
}

int main() {
	scanf("%d", &n);
	forint(i, 1, n) scanf("%d", &a[i]), lst[i]=MP(a[i], i);
	sort(lst+1, lst+n+1);
	nxt.clear();
	forint(i, 1, n) {
		int x=get_nxt(lst[i].fi);
		nxt[x]=x+1;
		b[lst[i].se]=x;
	}
	forint(i, 1, n) printf("%d%c", b[i], i<n?' ':'\n');
	return 0;
}