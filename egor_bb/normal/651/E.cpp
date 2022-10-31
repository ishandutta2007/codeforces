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

typedef long long LL;
typedef unsigned long long ULL;
typedef double dbl;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int N = 1e6 + 10;
const int INF = 2e9;
                  
vector < vector <int> > a;

int n,m;
                  
vector <int> g[N], g2[N]; 
vector <pii> x[N], y[N];
int color[N], b[N], used[N];

void dfs(int v, int c) {
//	cerr << v << " " << c << '\n';
	color[v] = c;
	forn(i, sz(g[v])) {
		int to = g[v][i];
		if (color[to] != c) {
			dfs(to, c);
		}
	}
}

void dfs2(int v) {
//	cerr << v << '\n';
	used[v] = 1;
	int mx = 0;
	forn(i, sz(g2[v])) {
		int to = g2[v][i];
		if (!used[to])
			dfs2(to);
	//	cerr << " v = " << v << " to = " << to << '\n';
		mx = max(mx, b[to]);
	}
	b[v] = mx + 1;
}
    
int main(){    
	ios_base::sync_with_stdio(0);
	cin.tie(0);                                                  
	#ifdef LOCAL    
   		freopen(".in", "r", stdin);
   		freopen(".out", "w", stdout); 
	#endif              
	cin >> n >> m;
	a.assign(n, vector <int> (m, 0));  
	forn (i, n)
		forn(j, m) {                  
			cin >> a[i][j]; 
			x[i].pb(mp(a[i][j], j)); 
			y[j].pb(mp(a[i][j], i));    
		}                    
	forn(i, n) {
		sort(all(x[i]));
		forab(j, 1, m) {
			if (x[i][j].fst == x[i][j - 1].fst) {
				g[i * m + x[i][j - 1].snd].pb(i * m + x[i][j].snd);
				g[i * m + x[i][j].snd].pb(i * m + x[i][j - 1].snd);
			}		
		}
	} 
	forn(i, m) {
		sort(all(y[i]));
		forab(j, 1, n) {
			if (y[i][j].fst == y[i][j - 1].fst) {
				g[m * y[i][j - 1].snd + i].pb(m * y[i][j].snd + i);
				g[m * y[i][j].snd + i].pb(m * y[i][j - 1].snd + i);
		//		cout << y[i][j].fst << " " << y[i][j].snd <<  " " << y[i][j - 1].fst << " " << y[i][j - 1].snd << '\n';
			}		
		}
	}
	int c = 1;
	forn(i, n * m) {
		if (!color[i]) {
			dfs(i, c);
			c++;
		}
	}
	forn(i, n) {
		forab(j, 1, m) {
			if (x[i][j].fst != x[i][j - 1].fst) {
				g2[color[i * m + x[i][j].snd]].pb(color[i * m + x[i][j - 1].snd]);	
	//			cerr << color[i * m + x[i][j].snd] << " " << color[i * m + x[i][j - 1].snd] << '\n';
			}
		}
	}
	forn(i, m) {
		forab(j, 1, n) {
			if (y[i][j].fst != y[i][j - 1].fst) {
				g2[color[m * y[i][j].snd + i]].pb(color[m * y[i][j - 1].snd + i]);
	//			cerr << color[m * y[i][j].snd + i] << " " << color[m * y[i][j - 1].snd + i] << '\n';
			}
		}
	}
	forn(i, c) {
		if (!used[i]) {
			dfs2(i);
		}
	}
	forn(i, n) {
		forn(j, m)
			cout << b[color[i * m + j]] << " ";
		cout << '\n';
	}

	return 0;
}