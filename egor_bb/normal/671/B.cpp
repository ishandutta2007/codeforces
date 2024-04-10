#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 5e5 + 100;
const LL INF = 1e18;

int a[N], n;
LL sum = 0;

LL calcUp(int x) {
	if (x * 1ll * n > sum)
		return INF;
	LL add = 0;
	forn(i, n) {
		if (a[i] < x)
			add += x - a[i];
	}
	return add;
}

LL calcDown(int x) {
	if (x * 1ll * n < sum)
		return INF;
	LL add = 0;
	forn(i, n) {
		if (a[i] > x)
			add += a[i] - x;
	}
	return add;
}

int main() {
	int k;
	scanf("%d%d", &n, &k);
	forn(i, n)
		scanf("%d", &a[i]), sum += a[i];
	sort(a, a + n);	
	int lUp = 0, rUp = 1e9 + 10;
	while (lUp < rUp - 1) {
		int m = (lUp + rUp) / 2;
		if (calcUp(m) <= k)
			lUp = m;
		else
			rUp = m;
	}		
	int lDown = 0, rDown = 1e9;
	while(lDown < rDown - 1) {
		int m = (lDown + rDown) / 2;
		if (calcDown(m) <= k)
			rDown = m;
		else
			lDown = m;
	}
	printf("%d\n", rDown - lUp);
		
	return 0;
}