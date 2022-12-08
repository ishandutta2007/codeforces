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

int main() {
	int n; static char s[100000+10];
	scanf("%d%s", &n,s);
	int cnt[26]={0};
	forn(i, n) cnt[s[i]-'A']++;
	int maxv=0, maxc=0;
	forn(i, 26) {
		if(cnt[i]>maxv) maxv=cnt[i], maxc=0;
		if(cnt[i]==maxv) ++maxc;
	}
	LL ans=1;
	forn(i, n) ans=(ans*maxc)%LL(1e9+7);
	printf("%d\n", (int)ans);
	return 0;
}