#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
using namespace std;
#define FOR(i,a,n) for(int i = (a); i <= (n); ++i)
#define FORD(i,a,n) for(int i = (a); i >= (n); --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,(n))
#define pb push_back
#define st first
#define nd second
#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e6 + 5;

ll b[nax];
ll dp[nax];
int n;

int main(int argc, char * argv[]) {
	debug = argc > 1;
	
	{
		ll a[nax];
		scanf("%d", &n);
		RI(i, n) scanf("%lld", &a[i]);
		int m = 0;
		RI(i, n) {
			// if(debug) printf("%lld %lld\n", a[i], b[m]);
			if(m-3 >= 1 && a[i] > b[m] && b[m] > b[m-1] && b[m-1] > b[m-2] && b[m-2] > b[m-3]) {
				b[m-1] = b[m];
				b[m] = a[i];
			}
			else if(m-3 >= 1 && a[i] < b[m] && b[m] < b[m-1] && b[m-1] < b[m-2] && b[m-2] < b[m-3]) {
				b[m-1] = b[m];
				b[m] = a[i];
			}
			else b[++m] = a[i];
		}
		if(debug) {
			printf("%d\n", m);
			RI(i, m) printf("%lld ", b[i]);
			puts(""); puts("");
		}
		n = m;
	}
	RI(i, n) RI(d, 6) if(i >= d) {
		ll small = inf, big = -inf;
		FOR(j, i-d+1, i) {
			mini(small, b[j]);
			maxi(big, b[j]);
		}
		maxi(dp[i], dp[i-d] + big - small);
	}
	printf("%lld\n", dp[n]);
	return 0;
}