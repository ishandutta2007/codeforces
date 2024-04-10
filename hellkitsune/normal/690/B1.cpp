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

const int N = 50 + 3;
int n;
char s[N][N];

inline bool read()
{
	if (scanf ("%d", &n) != 1)
		return false;
		
	forn (i, n)
		assert(scanf ("%s", s[i]) == 1);

	return true;
}

inline void solve()
{
	int x1 = INF, y1 = INF;
	int x2 = -1, y2 = -1;
	forn (i, n)
		forn (j, n)
			if (s[i][j] == '4')
			{
				x1 = min(x1, i);
				y1 = min(y1, j);
				x2 = max(x2, i);
				y2 = max(y2, j);
			}
			
	fore(x, max(0, x1 - 1), min(n - 1, x2 + 1))
		fore(y, max(0, y1 - 1), min(n - 1, y2 + 1))
		{
			if (x >= x1 && x <= x2 && y >= y1 && y <= y2)
			{
				if (s[x][y] != '4')
				{
					puts("No");
					return;
				}
				
				continue;
			}
			
			if ((x < x1 || x > x2) && (y < y1 || y > y2))
			{
				if (s[x][y] != '1')
				{
					puts("No");
					return;
				}
				
				continue;
			}
			
			if (s[x][y] != '2')
			{
				puts("No");
				return;
			}
		}
		
	forn (x, n)
		forn (y, n)
			if (!(x >= x1 - 1 && x <= x2 + 1 && y >= y1 - 1 && y <= y2 + 1) && s[x][y] != '0')
			{
				puts("No");
				return;
			}
			
	puts("Yes");
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