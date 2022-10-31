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

const int N = 1e4 + 10;
const ll INF = 1e18;

int in[N], out[N];
ll dp[N], old[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, c;
	cin >> n >> c;
	forn(i, n)
		cin >> out[i];
	forn(i, n)
		cin >> in[i];
	forn(i, n + 1)
		old[i] = INF;
	old[0] = 0;
	forn(i, n) {
		forn(j, i + 2) {
			dp[j] = INF;
			if (j < i + 1)
				dp[j] = old[j] + in[i];
			if (j)
				dp[j] = min(dp[j], old[j - 1] + out[i] + c * 1ll * (i - j + 1));
		}
		swap(old, dp);
	}
	ll ans = INF;
	forn(i, n + 1)
		ans = min(ans, old[i]);
	cout << ans << '\n';
	return 0;
}