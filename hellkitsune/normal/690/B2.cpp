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

const int N = 500 + 3;
int n;
char s[N][N];

inline bool read()
{
	if (scanf ("%d", &n) != 1)
		return false;
		
	if (n == 0)
		return false;
		
	forn (i, n)
		assert(scanf ("%s", s[n - 1 - i]) == 1);

	return true;
}

int sza;
pt a[N * N];

inline bool cw (const pt& a, const pt& b, const pt& c) 
{
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) < 0;
}

inline bool ccw (const pt& a, const pt& b, const pt& c) 
{
	return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) > 0;
}

int szup, szdown;
pt up[N * N], down[N * N];

inline void convex_hull () 
{
	sort (a, a + sza);
	pt p1 = a[0],  p2 = a[sza - 1];
	
	szup = szdown = 0;
	up[szup++] = p1;
	down[szdown++] = p1;
	
	for (int i = 1; i < sza; i++) 
	{
		if (i == sza - 1 || cw(p1, a[i], p2)) 
		{
			while (szup >= 2 && !cw(up[szup - 2], up[szup - 1], a[i]))
			    szup--;
			    
			up[szup++] = a[i];
		}
 
 		if (i == sza - 1 || ccw(p1, a[i], p2)) 
		{
			while (szdown >= 2 && !ccw(down[szdown - 2], down[szdown - 1], a[i]))
				szdown--;
				
			down[szdown++] = a[i];
		}
	}
	
	sza = 0;
	
	forn (i, szup)
		a[sza++] = up[i];
		
	for (int i = szdown - 2; i > 0; i--)
		a[sza++] = down[i];
}

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};

const int ddx[4] = {1, 0, 0, 1};
const int ddy[4] = {1, 1, 0, 0};

inline bool valid (int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < n;
}

inline void solve()
{
	sza = 0;
	forn (i, n)
		forn (j, n)
			if (s[i][j] == '1')
			{
				int id = -1;
						
				forn (k, 4)
				{
					bool ok = 1;
					forn (it, 3)
					{
						int nx = j + dx[(k * 2 + it) & 7], ny = i + dy[(k * 2 + it) & 7];
				
						if (!valid(nx, ny))
							continue;

						if (s[ny][nx] != '0')
						{
							ok = 0;
							break;
						}
					}
					
					if (ok)
						a[sza++] = mp(j + ddx[k], i + ddy[k]);
				}
			}
			
	convex_hull();
	
	printf ("%d\n", sza);
	forn (i, sza)
		printf ("%d %d\n", a[i].x, a[i].y);
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
	
	while(read())
		solve();

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}