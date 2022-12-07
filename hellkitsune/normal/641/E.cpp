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
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
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

const int N = 1000 * 1000 + 13;
int n;
pair<int, pt> a[N];

inline bool read()
{
	if (scanf ("%d", &n) != 1)
		return false;
		
	forn (i, n)
		assert(scanf ("%d%d%d", &a[i].ft, &a[i].sc.ft, &a[i].sc.sc) == 3);
	
	return true;
}

int e[N], sze;
vector<int> vals[N];
vector<int> t[N];

inline int getSum (int id, int r)
{
	int ans = 0;
	for (; r >= 0; r = (r & (r + 1)) - 1)
		ans += t[id][r];

	return ans;
}

inline void update (int id, int i, int val)
{
	for (; i < sz(t[id]); i = (i | (i + 1)))
		t[id][i] += val;
}

inline void solve()
{
	sze = 0;
	forn (i, n)
		e[sze++] = a[i].sc.sc;
		
	sort(e, e + sze);
	sze = int(unique(e, e + sze) - e);
	
	forn (i, n)
	{
		a[i].sc.sc = int(lower_bound(e, e + sze, a[i].sc.sc) - e);
		
		vals[ a[i].sc.sc ].pb(a[i].sc.ft);
	}
		
	forn (i, sze)
	{
		sort(all(vals[i]));
		vals[i].erase(unique(all(vals[i])), vals[i].end());
		
		t[i].resize(sz(vals[i]));
		forn (j, sz(t[i]))
			t[i][j] = 0;
	}
	
	forn (i, n)
	{
		int id = a[i].sc.sc;
	
		if (a[i].ft == 1)
		{
			int pos = int(lower_bound(all(vals[id]), a[i].sc.ft) - vals[id].begin());
			update(id, pos, +1);
		}
		else
		if (a[i].ft == 2)
		{
			int pos = int(lower_bound(all(vals[id]), a[i].sc.ft) - vals[id].begin());
			update(id, pos, -1);		
		}
		else
		if (a[i].ft == 3)
		{
			int pos = int(lower_bound(all(vals[id]), a[i].sc.ft) - vals[id].begin());
			printf ("%d\n", getSum(id, pos));			
		}
		else
			throw;
	}
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

	assert(read());
	solve();

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}