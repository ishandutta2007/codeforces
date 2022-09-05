#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<cstring>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
#define pb push_back
#define st first
#define nd second
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;



int main(int argc, char *argv[])
{
	debug = argc > 1;
	ll x1,y1,x2,y2;
	scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
	int n;
	scanf("%d", &n);
	int res = 0;
	while(n--) {
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		ll p1 = a*x1+b*y1+c;
		ll p2 = a*x2+b*y2+c;
		if(debug) printf("%lld %lld\n", p1, p2);
		p1 /= abs(p1); p2 /= abs(p2);
		if(debug) printf("%lld %lld\n", p1, p2);
		if(p1 * p2 == -1LL) res++;
	}
	printf("%d\n", res);
	return 0;
}