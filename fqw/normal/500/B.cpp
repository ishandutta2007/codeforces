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
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> void setmax(T &a, T b) { if(b>a) a=b; }
template<class T> void setmin(T &a, T b) { if(b<a) a=b; }
template<class T> T gcd(T a, T b) { return b==0?a:gcd(b,a%b); }


// ------------------------ template ends here ------------------------ //
const int MAXN=330;

bool ok[MAXN][MAXN];
int a[MAXN], p[MAXN];
int n;

int main() {
	scanf("%d", &n); forint(i, 1, n) scanf("%d", &a[i]);
	forint(i, 1, n) {
		char s[MAXN]; scanf("%s", s+1);
		forint(j, 1, n) ok[i][j]=(s[j]=='1');
		ok[i][i]=true;
	}
	forint(k, 1, n) forint(i, 1, n) forint(j, 1, n)
		ok[i][j]|=(ok[i][k]&&ok[k][j]);
	fillchar(p, 0);
	forint(k, 1, n) if(p[k]==0) {
		VI b;
		forint(i, 1, n) if(ok[k][i]) b.PB(a[i]);
		sort(all(b), std::greater<int>());
		forint(i, 1, n) if(ok[k][i]) {
			p[i]=b.back();
			b.pop_back();
		}
	}
	forint(i, 1, n) printf("%d ", p[i]); printf("\n");
	
	return 0;
}