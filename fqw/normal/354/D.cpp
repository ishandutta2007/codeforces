// 12:07
// 12:21 -> WA41
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
const int P=800;

int f[P+10], g[P+10];
VI xs[MAXN];
int n;

int main() {
	int tm;
	scanf("%d%d", &n,&tm);
	int ans=0;
	forint(i, 1, n) xs[i].clear();
	while(tm--) {
		int x, y; scanf("%d%d", &x,&y);
		if(x>n-P) xs[y].PB(x);
			else ans+=3;
	}
	fillchar(f, 50);
	f[0]=0;
	forint(y, 1, n) {
		memmove(g, f, sizeof(g));
		fillchar(f, 50);
		sort(xs[y].begin(), xs[y].end());
		int i=0;
		int min_g=1<<30;
		forintdown(d, P, 0) {
			int x=n-d+1;
			while(i<(int)xs[y].size() && xs[y][i]<x)
				++i;
			setmin(f[max(0,d-1)], g[d]+i*3);
			setmin(min_g, g[d]);
		}
		i=0;
		forintdown(d, P, 0) {
			int x=n-d;
			while(i<(int)xs[y].size() && xs[y][i]<x)
				++i;
			int h=n-x+1;
			int num=h*(h+1)/2+2;
			setmin(f[d], min_g+i*3+num);
		}
	}
	int tmp=1<<30;
	forint(d, 0, P) setmin(tmp, f[d]);
	ans+=tmp;
	printf("%d\n", ans);

	return 0;
}