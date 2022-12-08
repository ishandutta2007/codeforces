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

const int MAXN=150000 + 100;
const int MAXM=300 + 10;

LL f[MAXN], g[MAXN];

int q[MAXN], ss, tt;
int n;

void go(int a, int b, int w) {
	ss=1, tt=0;
	int j=1;
	forint(i, 1, n) {
		while(j<=n && j<=i+w) {
			while(ss<=tt && f[j]>f[q[tt]]) --tt;
			q[++tt]=j;
			++j;
		}
		while(ss<=tt && q[ss]<i-w) ++ss;
		g[i]=f[q[ss]]+(LL)b-(LL)abs(a-i);
	}
}

int a[MAXM], b[MAXM], t[MAXM];
int m, d;

int main() {
	scanf("%d%d%d", &n,&m,&d);
	forint(i, 1, m) scanf("%d%d%d", &a[i], &b[i], &t[i]);
	fillchar(f, 0);
	forint(i, 1, m) {
		LL w=0;
		if(i>1) w=(LL)d*(LL)(t[i]-t[i-1]);
		if(w>n) w=n;
		go(a[i], b[i], (int)w);
		memmove(f, g, sizeof(f));
		//printf("i=%d\n", i); forint(j, 1, n) printf("  f[%d]=%lld\n",j,f[j]);
	}
	LL ans=f[1];
	forint(i, 1, n) ans=max(ans, f[i]);
	cout<<ans<<endl;
	return 0;
}