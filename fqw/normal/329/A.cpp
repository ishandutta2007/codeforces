#include <iostream>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
#define PB push_back
#define MP make_pair
#define forint(i, a, b) for(int i=(int)(a); i<=(int)(b); ++i)
#define forintdown(i, a, b) for(int i=(int)(a); i>=(int)(b); --i)
#define forn(i, n) for(int i=0; i<(int)(n); ++i)
#define forndown(i, n) for(int i=(int)(n)-1; i>=0; --i)
#define fillchar(a, x) memset(a, x, sizeof(a))
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> T gcd(T a, T b) { return b==0 ? a : gcd(b,a%b); }

const int MAXN=110;
char a[MAXN][MAXN]; int p[MAXN];
int n;
int main() {
	scanf("%d", &n);
	forint(i, 1, n) scanf("%s", a[i]+1);
	bool flag=true;
	forint(i, 1, n) {
		p[i]=-1;
		forint(j, 1, n) if(a[i][j]=='.') p[i]=j;
		if(p[i]<0) flag=false;
	}
	if(flag) {
		forint(i, 1, n) printf("%d %d\n", i, p[i]);
	} else {
		flag=true;
		forint(i, 1, n) {
			p[i]=-1;
			forint(j, 1, n) if(a[j][i]=='.') p[i]=j;
			if(p[i]<0) flag=false;
		}
		if(flag) {
			forint(i, 1, n) printf("%d %d\n", p[i], i);
		} else printf("-1\n");
	}

	return 0;
}