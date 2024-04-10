#include <algorithm>
#include <numeric>
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
const int MAXN=510;
const int MAXM=1010;

int w[MAXN], b[MAXM];
int n, m;
int st[MAXN], len;

int main() {
	scanf("%d%d", &n,&m);
	forint(i, 1, n) scanf("%d", &w[i]);
	forint(i, 1, m) scanf("%d", &b[i]);
	bool vis[MAXN];
	fillchar(vis, false);
	len=0;
	forint(i, 1, m) {
		if(vis[b[i]]) continue;
		vis[b[i]]=true;
		st[++len]=b[i];
	}
	LL ans=0;
	forint(i, 1, m) {
		int j=int(std::find(st+1, st+len+1, b[i])-st);
		forint(k, 1, j-1) ans+=w[st[k]];
		forintdown(k, j, 2) st[k]=st[k-1];
		st[1]=b[i];
	}
	cout<<ans<<endl;
	return 0;
}