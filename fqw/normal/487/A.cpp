#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;

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

int check(int hy, int ay, int dy, int hm, int am, int dm) {
	int py=max(0, am-dy);
	int pm=max(0, ay-dm);
	if(pm==0) return 999999;
	while(hm>0) {
		hy-=py;
		hm-=pm;
	}
	if(hy>0) return 0;
	return 1-hy;
}

int main() {
	int hy, ay, dy; cin>>hy>>ay>>dy;
	int hm, am, dm; cin>>hm>>am>>dm;
	int h, a, d; cin>>h>>a>>d;
	int ans=1<<30;
	forint(ia, 0, 222) forint(id, 0, 222) {
		int ih=check(hy, ay+ia, dy+id, hm, am, dm);
		int tmp=ia*a+id*d+ih*h;
		ans=min(ans, tmp);
	}
	cout<<ans<<endl;
	
	return 0;
}