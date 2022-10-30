#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FNAME ""

const int MAX_N = 105;

char s[MAX_N][MAX_N];
int used[MAX_N * MAX_N];
set<int> rows, cols;
vector<pii> v[MAX_N * MAX_N];
int curSize = 0;
int n, m;

void dfs(int x, int y) {
 	used[x * m + y] = 1;
 	rows.insert(x);
 	cols.insert(y);
 	curSize++;
 	for (auto &np : v[x * m + y]) {
 	 	if (!used[np.fs * m + np.sc])
 	 		dfs(np.fs, np.sc); 
 	}
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	scanf("%d%d\n", &n, &m);
	forn (i, n) {
	    gets(s[i]);
	}
	forn (i, n)
		forn (j, m)
			if (s[i][j] == '#') {
			 	forn (g, n)
			 		if (i != g && s[g][j] == '#')
			 			v[i * m + j].pb(mp(g, j));
			 	forn (g, m)
			 		if (j != g && s[i][g] == '#')
			 			v[i * m + j].pb(mp(i, g));
			}
	forn (i, n)
		forn (j, m)
			if (s[i][j] == '#' && !used[i * m + j]) {
			 	rows.clear();
			 	cols.clear();
			 	curSize = 0;
			 	dfs(i, j);
				if (sz(rows) * sz(cols) != curSize) {
				 	puts("No");
				 	return 0;
				}
			}
	puts("Yes");
	return 0;
}