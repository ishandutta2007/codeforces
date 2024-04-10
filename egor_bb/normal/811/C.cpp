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

const int N = 5005;

int a[N], l[N], r[N], dp[N], bad[N], got[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n)
		cin >> a[i];
	forn(i, N)
		l[i] = N, r[i] = -1;
	forn(i, n) {
		l[a[i]] = min(i, l[a[i]]);
		r[a[i]] = max(i, r[a[i]]);
	}
	forn(i, n) {
		dp[i + 1] = dp[i];
		forn(j, N)
			bad[j] = 0, got[j] = 0;
		int cnt = 0, x = 0;
		fornr(j, i + 1) {
			if (l[a[j]] >= j && r[a[j]] <= i && bad[a[j]])
				bad[a[j]] = 0, cnt--;
			if (((l[a[j]] < j) || (r[a[j]] > i)) && (!bad[a[j]]))
				bad[a[j]] = 1, cnt++;
			if (!got[a[j]])
				got[a[j]] = 1, x ^= a[j];
			if (cnt == 0) {
				dp[i + 1] = max(dp[i + 1], x + dp[j]);
			}
		}
	}	
	cout << dp[n] << '\n';
	return 0;
}