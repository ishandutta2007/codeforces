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
const int MAXV=1000000;

int a[MAXN], k;
int n;

int main() {
	scanf("%d%d", &n,&k);
	forint(i, 1, n) scanf("%d", &a[i]);
	a[0]=0;
	sort(a+1, a+n+1);
	forintdown(ans, a[1], 1) {
		bool flag=true;
		for(int j=ans; j<=a[n]; j+=ans) {
			int *p=upper_bound(a, a+n+1, j+ans-1)-1;
			//printf("i=%d j=%d find=%d\n",ans,j,*p);
			if(*p-k>j) {flag=false; break;}
		}
		if(flag) {
			printf("%d\n", ans);
			break;
		}
	}

	return 0;
}