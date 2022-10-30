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

vector<int> a[2];
int t[N];
bitset<N> dp[2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, l, r;
	cin >> n >> l >> r;
	forn(i, n) {
		cin >> t[i];
	}	
	forn(i, n) {
		int b;
		cin >> b;
		a[b].pb(t[i]);
	}
	sort(all(a[0]));
	sort(all(a[1]));
	dp[0][0] = 1;
	for(int x : a[0]) {
		dp[0] |= (dp[0] << x);
	}
	int sum = 0;
	int now = 0;
	for(int x : a[1]) {
		sum += x;
		now++;
	}
	if (now == 0) {
		cout << 0 << '\n';
		return 0;
	}
	int best = 0;
	reverse(all(a[1]));
	for(int x : a[1]) {
		int start = r - sum;
		if (start >= l) {
			forab(j, l, start + 1) {
				if (dp[0][j] == 1) {
					best = max(best, now);
				}
				if (dp[1][j] == 1) {
					best = max(best, now + 1);
				}
			}
		}
		dp[1] = dp[0] | (dp[1] << x);
		dp[0] |= (dp[0] << x);
		sum -= x;
		now--;
	}
	forab(j, l, r + 1) {
		if (dp[1][j]) best = max(best, 1);
	}
	cout << best << '\n';
	return 0;
}