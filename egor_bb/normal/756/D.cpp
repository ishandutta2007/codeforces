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

const int N = 5e3 + 100;
const int MOD = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= MOD)
		a -= MOD;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0)
		a += MOD;
	return a;
}

int mul(int a, int b) {
	return int((a * 1ll * b) % MOD);
}

int dp[N][N], last[N], c[N][N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n;
	cin >> s;	
	forn(i, n) {
		last[i] = -1;
		forn(j, i) {
			if (s[i] == s[j])
				last[i] = j;
		}
	}
	forn(i, n + 1) {
		c[i][0] = 1;
		forab(j, 1, i + 1) {
			c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
		}
	}	
	dp[0][0] = 1;
	forn(i, n) {
		int pos = last[i];
		forn(len, n + 1) {
			dp[i + 1][len] = dp[i][len];
			if (len == 0)
				continue;
			if (pos == -1) {
				dp[i + 1][len] = add(dp[i + 1][len], dp[i][len - 1]);
			} else {
				dp[i + 1][len] = add(dp[i + 1][len], sub(dp[i][len - 1], dp[pos + 1][len - 1]));
			}
		}
	}
	int ans = 0;
	forab(i, 1, n + 1) {
//		cout << dp[n][i] << " " << c[n - 1][i - 1] << '\n';
		ans = add(ans, mul(dp[n][i], c[n - 1][i - 1]));
	}
	cout << ans << '\n';
	return 0;
}