// 14:37 - 14:44
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
const int MAXN=310;

int n, l[MAXN], c[MAXN];
int p[12], pn;
int f[MAXN][1<<11];

int main() {
	scanf("%d", &n);
	forint(i, 1, n) scanf("%d", &l[i]);
	forint(i, 1, n) scanf("%d", &c[i]);
	int maxval=1<<30, ans=maxval;
	forint(i, 1, n) {
		pn=0;
		int x=l[i];
		for(int k=2; k*k<=x; ++k)
			if(x%k==0) {
				p[++pn]=k;
				while(x%k==0) x/=k;
			}
		if(x>1) p[++pn]=x;
		fillchar(f, 120);
		f[i][(1<<pn)-1]=c[i];
		forint(j, i+1, n) {
			int cur=0;
			forint(k, 1, pn) if(l[j]%p[k]==0) cur|=1<<(k-1);
			forn(st, 1<<pn) {
				setmin(f[j][st&cur], f[j-1][st]+c[j]);
				setmin(f[j][st], f[j-1][st]);
			}
		}
		ans=min(ans, f[n][0]);
	}
	if(ans==maxval) ans=-1;
	cout<<ans<<endl;

	return 0;
}