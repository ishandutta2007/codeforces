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
int gcd(int a, int b) {
	return b==0 ? a : gcd(b,a%b);
}

const int MAXN=100010;
int a[MAXN], n;

int main() {
	scanf("%d", &n); forint(i, 1, n) scanf("%d", a+i);
	int d=a[1]; forint(i, 2, n) d=gcd(d, a[i]);
	int m=0; forint(i, 1, n) m=max(m, a[i]/d);
	printf("%s\n", (m-n)%2!=0?"Alice":"Bob");

	return 0;
}