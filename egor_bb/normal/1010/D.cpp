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

const int N = 1e6 + 100;

vector<int> g[N];
vector<int> can[N];
string type[N];
int value[N];
int changer[N];


void mrg(int v, int v1, int v2) {
	int s1 = sz(can[v1]);
	int s2 = sz(can[v2]);
	if (s1 > s2) {
		can[v].swap(can[v1]);
		for(int x: can[v2]) can[v].pb(x);
	} else {
		can[v].swap(can[v2]);
		for(int x: can[v1]) can[v].pb(x);
	}
}


void dfs(int v) {
	if (type[v] == "IN") {
		can[v].pb(v);
		return;
	}
	if (type[v] == "NOT") {
		int u = g[v][0];
		dfs(u);
		can[v].swap(can[u]);
		value[v] = 1 - value[u];
		return;
	}
	int v1 = g[v][0], v2 = g[v][1];
	dfs(v1);
	dfs(v2);
	if (type[v] == "AND") {
		if (value[v1] == 0 && value[v2] == 0) {
			value[v] = 0;
			return;
		}
		if (value[v1] == 1 && value[v2] == 1) {
			value[v] = 1;
			mrg(v, v1, v2);
			return;
		}
		value[v] = 0;
		if (value[v1] == 0) can[v].swap(can[v1]);
		else can[v].swap(can[v2]);
	} else if (type[v] == "OR") {
		if (value[v1] == 1 && value[v2] == 1) {
			value[v] = 1;
			return;
		}
		if (value[v1] == 0 && value[v2] == 0) {
			value[v] = 0;
			mrg(v, v1, v2);
			return;
		}
		value[v] = 1;
		if (value[v1] == 1) can[v].swap(can[v1]);
		else can[v].swap(can[v2]);
	} else {
		assert(type[v] == "XOR");
		value[v] = value[v1] ^ value[v2];
		mrg(v, v1, v2);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		cin >> type[i];
		if (type[i] == "IN") {
			cin >> value[i];
		} else if (type[i] == "NOT") {
			int v; cin >> v;
			g[i].pb(v - 1);
		} else {
			int v, u; cin >> v >> u;
			g[i].pb(v - 1);
			g[i].pb(u - 1);
		}
	}
	dfs(0);
	for(int x : can[0]) {
		changer[x] = 1;
	}
	forn(i, n) {
		if (type[i] == "IN") {
			if (changer[i]) cout << 1 - value[0];
			else cout << value[0];
		}
	}
	cout << '\n';
	return 0;
}