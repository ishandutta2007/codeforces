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

const int N = 505;

int dp[N][N], old[N][N];
int c[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	dp[0][0] = 1;
	forn(i, n) {
		cin >> c[i];
		fornr(j, k + 1)
			fornr(q, k + 1) {
				if (j >= c[i])
					dp[j][q] |= dp[j - c[i]][q];
				if (q >= c[i])
					dp[j][q] |= dp[j][q - c[i]];
			}
	}
	vector <int> a;
	forn(i, k + 1)
		if (dp[i][k - i])
			a.pb(i), a.pb(k - i);
	sort(all(a));
	a.resize(unique(all(a)) - a.begin());
	cout << sz(a) << '\n';
	forn(i, sz(a))
		cout << a[i] << " ";
	cout << '\n';
	return 0;
}