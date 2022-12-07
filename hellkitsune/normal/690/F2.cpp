#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i < int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

int n, k;

const int N = 100 * 100 + 5;
vector <int> g[N];

int any;
vector <int> hf[N];

inline bool read()
{
	if (!(cin >> n >> k))
		return false;		
	forn(i, N)
		g[i].clear(), hf[i].clear();
	any = -1;		
	forn(i, k) {
		int offs = n * i;
		int m;
		assert(scanf("%d", &m) == 1);
		if (m == n - 2)
			any = i;		
		forn(i, m) {
			int u, v;
			assert(scanf("%d %d", &u, &v) == 2);
			--u, --v;
			g[u + offs].pb(v + offs);
			g[v + offs].pb(u + offs);			 
		}
	}

	return true;
}

int used[N], cused;
int szh = 0;
map <vector <int>, int> h;
vector <int> resv;

int prot;

bool is_prot(int v) {
	return v == prot;
}

pt dfs(int v, int dist = 0, int p = -1) {
	used[v] = cused;
	pt res = mp(dist, v);
	for (auto to: g[v]) {
		if (is_prot(to))
			continue;
		if (to == p)
			continue;
		res = max(res, dfs(to, dist + 1, v));
	}
	return res;
}

vector <int> path;

bool find_path(int v, int to, int p = -1) {
	if (v == to) {
		path.pb(to);
		return true;
	}
	
	for (auto t: g[v]) {
		if (is_prot(v))
			continue;
		if (t == p)
			continue;
		if (find_path(t, to, v)) {
			path.pb(v);
			return true;
		}
	}
	
	return false;
}

vector <int> diamvs(int start) {
	pt endp = dfs(start);
	int st = endp.y;
	endp = dfs(st);
	path.clear();
	assert(find_path(st, endp.y));
	vector <int> res;
	res.pb(path[sz(path) / 2]);
	if (sz(path) % 2 == 0)
		res.pb(path[sz(path) / 2 - 1]);

	return res;		
}

int get_vertexh(vector <int> &v) {
	sort(all(v));
	if (!h.count(v))
		h[v] = szh++;
	return h[v];
}

int get_treeh(vector <int> &v) {
	v.pb(-1);
	return get_vertexh(v);	
}

int calc_h(int v, int p = -1) {
	vector <int> cs;
	for (auto to: g[v]) {
		if (is_prot(to))
			continue;
		if (to == p)
			continue;
		cs.pb(calc_h(to, v));
	}
	
	return get_vertexh(cs);
}

vector <int> calc_foresth(int i) {
		vector <int> res;
		int offs = i * n;

		cused++;
		fore(i, offs, offs + n) {
//			cerr << i - offs << endl;
			if (used[i] == cused || is_prot(i))
				continue;
			auto vs = diamvs(i);
	//		cerr << i << " " << sz(vs) << endl;
			vector <int> hh;
			for (auto v: vs) {
				hh.pb(calc_h(v));
			//	cerr << tt << " dv=" << v - offs << endl;
			}
			res.pb(get_treeh(hh));
		}
		sort(all(res));
		return res;
}

vector <int> mf[N];

inline void solve()
{
	if (any == -1) {
		puts("NO");
		return;
	}

	prot = -1;
	forn(i, k) {
			hf[i] = calc_foresth(i);
		/*	for (auto x: hf[i])
				cerr << x << " ";
			cerr << endl;							*/
	}
	//return;
	
	int my = -1;
	//cerr << any << endl;
	fore(i, n * any, n * any + n) {
		if (sz(g[i]) == 0) {
			//cerr << i << endl;
			assert(n == 2 || my == -1);
			my = i;
		}
	}
	
	sort(hf, hf + k);
	
	fore(i, n * any, n * any + n) {
		if (i == my)
			continue;
			
		g[my].pb(i);
		g[i].pb(my);
		
		fore(j, n * any, n * any + n) {
			prot = j;
			mf[j - n * any] = calc_foresth(any);
			auto v = vector <int> ();
			auto u = vector <int> (1, get_vertexh(v));
			mf[j - n * any].pb(get_treeh(u));
			sort(all(mf[j - n * any]));
		}
		
		sort(mf, mf + k);
		
		bool good = true;
			
//		cerr << "======\n";			
		forn(i, k) {
			
/*			for (auto x: mf[i])
				cerr << x << " ";
			cerr << endl;				*/

			if (mf[i] != hf[i]) {
				good = false;
				break;			
			}
		}
			
		if (good) {
			puts("YES");
			fore(j, n * any, n * any + n)
				for (auto to: g[j]) {
					if (j < to)
						printf("%d %d\n", (j - n * any) + 1, (to - n * any) + 1);
				}
			return;				
		}
		
		g[i].pop_back();
		g[my].pop_back();
	}
	

	
	puts("NO");
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));
	
	int z;
	assert(cin >> z);

	forn(_, z) {
		assert(read());
		solve();
	}

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}