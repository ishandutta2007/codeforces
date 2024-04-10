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

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

int dp[1000][1000];
vector<int> primes;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	dp[0][0] = 1;
	forn(i, 100) {
		forn(j, 100) {
			if (i - 1 >= 0 && j - 2 >= 0 && dp[i - 1][j - 2])
				dp[i][j] = 1;
			if (i - 2 >= 0 && j - 1 >= 0 && dp[i - 2][j - 1]) 
				dp[i][j] = 1;
		}
	}
	forab(j, 2, 1001) {
		int ok = 1;
		forab(i, 2, j) {
			if (j % i == 0) {
				ok = 0;
			}
		}
		if (ok)
			primes.pb(j);
	}
	int n;
	scanf("%d", &n);
	forn(k, n) {
		int a, b;
		scanf("%d%d", &a, &b);
		for (int i : primes) {
			if (i > a || i > b)
				break;
			if ((a % i) == 0 || (b % i) == 0) {
				int k1 = 0, k2 = 0;
				while(a % i == 0) {
					a /= i;
					k1++;
				}
				while(b % i == 0) {
					b /= i;
					k2++;
				}
				if (k1 < k2) {
					swap(k1, k2);
				}
				if (!dp[k1][k2]) {
					a = 1, b = 228;
					break;
				}
			}
		}
		if (a * 1ll * a == b || b * 1ll * b == a) {
			puts("Yes");
		} else {
			puts("No");
		}
	}
	return 0;
}