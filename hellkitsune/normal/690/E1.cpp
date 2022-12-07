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

const int N = 600 + 13;
int h, w;
int a[N][N];

inline bool read()
{
	if (scanf ("%d%d", &h, &w) != 2)
		return false;
		
	forn (i, h)
		forn (j, w)
			assert(scanf ("%d", &a[i][j]) == 1);

	return true;
}

inline int getDist (int i, int j)
{
	int ans = 0;
	forn (k, w)
		ans += sqr(a[i][k] - a[j][k]);
		
	return ans;
}

inline void solve()
{
	ld all = 0;
	forn (i, h - 1)
		all += getDist(i, i + 1);
		
	all /= ld(h);
	
	ld mid = getDist(h / 2 - 1, h / 2);
	
	//cerr << all << ' ' << mid << endl;
	
	ld prec = abs(mid - all) / all;
	
	//cerr << prec << endl;
	
	if (prec > 2)
		puts("YES");
	else
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
	
	int testCnt;
	assert(scanf ("%d", &testCnt) == 1);

	forn (test, testCnt)
	{
		assert(read());
		solve();
	}

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}