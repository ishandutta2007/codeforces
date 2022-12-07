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
int n, q;

inline bool read()
{
	if (scanf ("%d%d", &n, &q) != 2)
		return false;

	return true;
}

int sz1, sz2;
int _p1[N], _p2[N], *p1=_p1, *p2=_p2;
int it1, it2;

inline void mySwap()
{
	swap(sz1, sz2);
	swap(p1, p2);
	swap(it1, it2);
}

inline void solve()
{
	forn (i, n)
	{
		if (i & 1)
			p2[sz2++] = i;
		else
			p1[sz1++] = i;
	}
	
	forn (i, q)
	{
		int t;
		assert(scanf ("%d", &t) == 1);
		
		if (t == 1)
		{
			int sh;
			assert(scanf ("%d", &sh) == 1);
			
			sh = -sh;
			
			if (sh < 0)
				sh = n + sh;
				
			if (sh == n)
				sh = 0;
				
			it1 = (it1 + (sh + 1) / 2) % sz1;
			it2 = (it2 + sh / 2) % sz2;
			
			if (abs(sh) & 1)
				mySwap();
		}
		else
		{
			mySwap();
		}
	}
	
	forn (i, n)
	{
		if (!(i & 1))
		{
			printf ("%d ", p1[it1] + 1);
			it1 = (it1 + 1) % sz1;
		}
		else
		{
			printf ("%d ", p2[it2] + 1);
			it2 = (it2 + 1) % sz2;
		}
	}
	
	puts("");
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