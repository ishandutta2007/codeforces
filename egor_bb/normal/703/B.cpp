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

const int N = 1e5 + 100;

LL a[N], prv[N], nxt[N], is_capital[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	LL sum = 0;
	forn(i, n)
		nxt[i] = i + 1, prv[i] = i - 1;
	prv[0] = n - 1;
	nxt[n - 1] = 0;
	forn(i, n)
		cin >> a[i], sum += a[i];
	LL ans = 0;
	forn(i, n)
		ans += a[i] * a[nxt[i]];
	forn(i, k) {
		int c; cin >> c;
		c--;
		is_capital[c] = 1;
		sum -= a[c];
		if (!is_capital[prv[c]]) ans -= a[c] * (a[prv[c]]);
		if (!is_capital[nxt[c]]) ans -= a[c] * (a[nxt[c]]);
		ans += sum * a[c];
	}
	cout << ans << '\n';
	return 0;
}