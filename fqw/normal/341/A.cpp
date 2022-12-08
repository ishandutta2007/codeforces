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
#define fillchar(a, x) memset(a, (x), sizeof(a))

const int MAXN=100010;

int a[MAXN];
int n;

LL gcd(LL a, LL b) {
	return b==0 ? a : gcd(b,a%b);
}

int main() {
	scanf("%d", &n); forint(i, 1, n) scanf("%d", a+i);
	LL ans=0, anst=n;
	sort(a+1, a+n+1);
	forint(i, 1, n) {
		LL tmp=2*((i-1)-(n-(i-1)-1))+1;
		//printf("tmp=%lld\n",tmp);
		tmp*=a[i];
		ans+=tmp;
	}
	LL t=gcd(ans, anst);
	ans/=t, anst/=t;
	cout<<ans<<" "<<anst<<endl;
	return 0;
}