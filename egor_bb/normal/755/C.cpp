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

int used[N];
vector <int> g[N];

void dfs(int v) {
	used[v] = 1;
	for(int to : g[v]) {
		if (used[to])
			continue;
		dfs(to);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	forn(i, n) {
		int v;
		cin >> v;
		v--;
		g[v].pb(i);
		g[i].pb(v);
	}
	int cnt = 0;
	forn(i, n) {
		if (used[i])
			continue;
		cnt++;
		dfs(i);
	}	
	cout << cnt << '\n';
	return 0;
}