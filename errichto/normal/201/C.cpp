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
#define mp make_pair
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
const ll INF = (ll) inf * inf;

int t[nax];

int main(int argc, char *argv[])
{
	debug = argc > 1;
	
	int n;
	scanf("%d", &n);
	--n;
	ll C = 0, p = 0, D = 0, r = 0;
	while(n--) {
		ll a;
		scanf("%lld", &a);
		if(a % 2LL == 0LL) {
			ll C2 = C + a;
			ll p2 = C + a - 1;
			
			maxi(p2, p + a - 1);
			
			ll D2 = max(p + a, D + a);
			
			C = C2;
			p = p2;
			D = max(D2,p2);
		}
		else {
			ll C2 = C + a - 1;
			if(a == 1LL) C2 = 0;
			ll p2 = C + a;
			
			maxi(p2, p + a);
			
			ll D2 = max(p + a - 1, D + a - 1);
			if(a == 1LL) D2 = 0;
			
			C = C2;
			p = p2;
			D = max(D2,p2);
		}
		maxi(r, C);
		maxi(r, D);
		maxi(r, p);
		if(debug) printf("%lld %lld %lld\n", C, D, p);;
	}
	printf("%lld\n", r);
			
	return 0;
}