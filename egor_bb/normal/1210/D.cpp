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

stack<int> great[N];
int d[N];

ll ansV(int v) {
	return (d[v] - sz(great[v])) * 1ll * sz(great[v]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	forn(i, m) {
		int v, u;
		cin >> v >> u;
		v--, u--;
		d[v]++;
		d[u]++;
		if (v > u) swap(v, u);
		great[v].push(u);
	}
	ll ans = 0;
	forn(i, n) {
		ans += ansV(i);
	}
	cout << ans << '\n';
	int q;
	cin >> q;
	forn(i, q) {
		int v;
		cin >> v;
		v--;
		ans -= ansV(v);
		while(!great[v].empty()) {
			int to = great[v].top();
			great[v].pop();
			ans -= ansV(to);
			great[to].push(v);
			ans += ansV(to);
		}
		cout << ans << '\n';
	}
	return 0;
}