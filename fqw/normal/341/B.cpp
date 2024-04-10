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
#define fillchar(a, x) memset(a, (x), sizeof(a))

const int MAXN=100010;

int t[MAXN];
int a[MAXN];
int n;

void se(int x, int v) {
	for(; x<=n; x+=(x&-x)) setmax(t[x], v);
}
int get(int x) {
	int ans=0;
	for(; x>=1; x-=(x&-x)) setmax(ans, t[x]);
	return ans;
}

int main() {
	scanf("%d", &n); forint(i, 1, n) scanf("%d", a+i);
	int ans=0;
	fillchar(t, 0);
	forint(i, 1, n) {
		int tmp=get(a[i]-1)+1;
		setmax(ans, tmp);
		se(a[i], tmp);
	}
	printf("%d\n", ans);
	return 0;
}