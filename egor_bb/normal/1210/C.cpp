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

const int N = 1e5 + 100;
const int MOD = 1e9 + 7;

vector<int> g[N];
ll x[N], ans = 0;
vector<pair<ll, int>> upGcd[N];

ll add(ll a, ll b) {
	return (a + b) % MOD;
}

ll gcd(ll a, ll b) {
	if (!a) return b;
	if (!b) return a;
	return __gcd(a, b);
}

void dfsCompute(int v, int p) {
	
	if (p != -1) {
		for (pair<ll, int> pp: upGcd[p]) {
			ll gcdVal = pp.fst;
			int len = pp.snd;
			ll myGcd = gcd(x[v], gcdVal);
			if (!upGcd[v].empty() && upGcd[v].back().fst == myGcd) {
				continue;
			}
			upGcd[v].pb(mp(myGcd, len + 1));
		}
	}
	upGcd[v].pb(mp(x[v], 1));
	int lastLen = 0;
	fornr(i, sz(upGcd[v])) {
		int len = upGcd[v][i].snd - lastLen;
		ans = add(ans, upGcd[v][i].fst * 1ll * len);
		lastLen = upGcd[v][i].snd;
	}

	for (int to: g[v]) {
		if (to == p) continue;
		dfsCompute(to, v);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		cin >> x[i];	
	}
	forn(i, n - 1) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfsCompute(0, -1);
	cout << ans << '\n';
	return 0;
}