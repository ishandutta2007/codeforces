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

const int MAXN=100010;

int n, l, r, ql, qr;
int w[MAXN], s[MAXN];

int main() {
	scanf("%d%d%d%d%d", &n,&l,&r,&ql,&qr);
	s[0]=0;
	forint(i, 1, n) scanf("%d", &w[i]), s[i]=s[i-1]+w[i];
	LL ans=1LL<<55;
	forint(i, 0, n) {
		int cl=i, cr=n-i;
		LL wl=s[i], wr=s[n]-wl;
		LL tmp=l*wl+r*wr;
		if(cl-cr-1>0) tmp+=(cl-cr-1)*(LL)ql;
		if(cr-cl-1>0) tmp+=(cr-cl-1)*(LL)qr;
		ans=min(ans, tmp);
	}
	cout<<ans<<endl;
	return 0;
}