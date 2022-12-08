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

int a[1010];
int n;

bool intersect(int al, int ar, int bl, int br) {
	if(al>ar) swap(al, ar);
	if(bl>br) swap(bl, br);
	if(ar<=bl) return false;
	if(br<=al) return false;
	if(al<=bl && br<=ar) return false;
	if(bl<=al && ar<=br) return false;
	return true;
}

int main() {
	scanf("%d", &n);
	forint(i, 1, n) scanf("%d", &a[i]);
	if(n<=2) {
		printf("no\n"); return 0;
	}
	forint(i, 3, n) forint(j, 2, i-1)
		if(intersect(a[i-1],a[i], a[j-1],a[j])) {
			printf("yes\n");
			return 0;
		}
	printf("no\n");
	return 0;
}