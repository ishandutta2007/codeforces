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

const int N = 3e5 + 100;

int x[N], y[N];
pii srt[N];
ll def[N];
ll ans[N], sumX[N], sumY[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, n) {
		cin >> x[i] >> y[i];
		srt[i] = mp(x[i] - y[i], i);
	}
	sort(srt, srt + n);
	forn(i, m) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		int delta = min(x[v] + y[u], x[u] + y[v]);
		ans[v] -= delta;
		ans[u] -= delta;
	}
	forn(i, n) {
		int ind = srt[i].snd;
		sumX[i + 1] = sumX[i] + x[ind];
	}
	fornr(i, n) {
		int ind = srt[i].snd;
		sumY[i] = sumY[i + 1] + y[ind];
	}
	forn(i, n) {
		int ind = srt[i].snd;
		ans[ind] += y[ind] * 1ll * i;
		ans[ind] += x[ind] * 1ll * (n - i - 1);
		ans[ind] += sumX[i];
		ans[ind] += sumY[i + 1];
	}
	forn(i, n) cout << ans[i] << " ";
	cout << '\n';
	return 0;
}