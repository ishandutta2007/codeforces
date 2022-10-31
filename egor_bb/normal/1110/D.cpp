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


const int N = 1e6 + 10;
const int INF = 1e9 + 7;

int cnt[N], dp[N][5][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, n) {
		int x;
		cin >> x;
		cnt[x] += 1;
	}
	forn(last, 5)
		forn(prev, 3)
			dp[0][last][prev] = -INF;
	dp[0][0][0] = 0;

	for (int cur = 1; cur <= m; cur++) {
		forn(last, 5)
			forn(prev, 3)
				dp[cur][last][prev] = -INF;
				
		for (int last = 0; last <= 4; last++) {
			for (int prev = 0; prev <= 2; prev++) {
				for (int triples = 0; triples <= min(cnt[cur], min(last, prev)); triples++) {
					for (int p = 0; p <= last - triples; p++) {
						for (int l = 0; l <= min(4, cnt[cur] - triples); l++) {
							dp[cur][l][p] = max(dp[cur][l][p], dp[cur - 1][last][prev] + triples + (cnt[cur] - triples - l) / 3);
						}
					}
				}
			}
		}
	//	cout << cur << " " << dp[cur][0][0] << '\n';
	//	cout << dp[cur][2][2] << '\n';
	}
	int ans = 0;
	forn(last, 5)
		forn(prev, 3)
			ans = max(ans, dp[m][last][prev]);
			
	cout << ans << '\n';
	return 0;
}