#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define _ (size_t)
#define all(a) a.begin(), a.end()
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
typedef pair<double,double> PDD;
typedef pair<int,int> PII;
typedef vector<string> VS;
typedef vector<int> VI;
typedef vector<PII> VPI;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }

// ------------------------ template ends here ------------------------ //

const int N=30000;

int *f[33333];
int v[33333], s[63333], t[63333];
int n, d;

void init() {
	fillchar(v, 0);
	scanf("%d%d", &n,&d);
	forint(i, 1, n) {
		int x; scanf("%d", &x);
		++v[x];
	}
}

void make() {
	forint(i, d, N)
		s[i]=t[i]=d;
	forint(i, d, N) {
		if (i>d) {
			setmin(s[i], s[i-1]);
			setmax(t[i], t[i-1]);
		}
		setmax(t[i+t[i]+1], t[i]+1);
		if(s[i]>1) setmin(s[i+s[i]-1], s[i]-1);
		//printf("%d %d\n", s[i],t[i]);
	}
	int len=0;
	forint(i, d, N) len+=t[i]-s[i]+1;
	int *x=(int *)malloc(sizeof(int)*len);
	forn(i, len) x[i]=-(1<<29);
	forint(i, d, N) {
		f[i]=x-s[i];
		x=x+(t[i]-s[i]+1);
	}
}

int main() {
	init();
	make();

	f[d][d]=0;
	int ans=0;
	forint(i, d, N) forint(l, s[i], t[i]) {
			int val=f[i][l]+v[i];
			setmax(ans, val);
			if(i+l<=N) f[i+l][l]=max(f[i+l][l], val);
			if(i+l+1<=N) f[i+l+1][l+1]=max(f[i+l+1][l+1], val);
			if(i+l-1<=N && l-1>=1) f[i+l-1][l-1]=max(f[i+l-1][l-1], val);
	}
	printf("%d\n", ans);
	return 0;
}