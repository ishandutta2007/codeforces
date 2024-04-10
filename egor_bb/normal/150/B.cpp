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

const int MOD = 1e9 + 7;
const int N = 2e3 + 100;

int mul(int a, int b) {
	return int((a * 1ll * b) % MOD);
}

int pwr(int a, int d) {
	if (!d)
		return 1;
	int t = pwr(a, d / 2);
	t = mul(t, t);
	if (d & 1)
		return mul(t, a);
	else 
		return t;
}

vector <int> g[N];
int used[N];

void dfs(int v, int c) {
	used[v] = c;
	for(int to : g[v]) {
		if (!used[to])
			dfs(to, c);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	forn(i, n) {
		for (int j = i - (k - 1) / 2; j <= i; j++) {
			if (j < 0 || j + k > n)
				continue;
			int d = i - j;
			int p = j + k - d - 1;
			g[p].pb(i);
			g[i].pb(p);
		}
	}
	int c = 0;
	forn(i, n) {
		if(!used[i]) {
			c++;
			dfs(i, c);
		}
	}
	cout << pwr(m, c) << '\n';
	return 0;
}