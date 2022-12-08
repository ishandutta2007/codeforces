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

const int MAXN=3010;
const int INFI=1<<30;

int a[MAXN], b[MAXN], c[MAXN];
int f[MAXN], g[MAXN]; // f[i]: i > i+1
int n;

int main() {
	scanf("%d", &n);
	forint(i, 1, n) scanf("%d", &a[i]);
	forint(i, 1, n) scanf("%d", &b[i]);
	forint(i, 1, n) scanf("%d", &c[i]);
	f[0]=g[0]=-INFI;
	g[0]=0;
	forint(i, 1, n) {
		f[i]=g[i]=-INFI;
		setmax(f[i], f[i-1]+b[i]);
		setmax(f[i], g[i-1]+a[i]);
		setmax(g[i], f[i-1]+c[i]);
		setmax(g[i], g[i-1]+b[i]);
	}
	printf("%d\n", f[n]);

	return 0;
}