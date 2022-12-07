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

const int N = 1000 + 13;
int n, k;
int a, b, c, d;

inline bool read()
{
	if (scanf ("%d%d", &n, &k) != 2)
		return false;
		
	assert(scanf ("%d%d%d%d", &a, &b, &c, &d) == 4);
	a--, b--, c--, d--;

	return true;
}

int used[N];
int p[N];

inline void solve()
{
	if (n == 4 || k < n + 1)
	{
		puts("-1");
		return;
	}
	
	used[a] = 1;
	used[b] = 1;
	used[c] = 1;
	used[d] = 1;
	
	p[0] = a;
	p[1] = c;
	forn (i, n)
		if (!used[i])
		{
			p[2] = i;
			used[i] = 1;
			break;
		}
		
	p[3] = d;
	int szp = 4;
	forn (i, n)
		if (!used[i])
			p[szp++] = i;
			
	p[szp++] = b;

	assert(szp == n);
	
	forn (i, n)
		printf ("%d ", p[i] + 1);
	puts("");
	printf ("%d %d %d %d ", p[1] + 1, p[0] + 1, p[2] + 1, p[n - 1] + 1);
	for (int i = n - 2; i >= 3; i--)
		printf ("%d ", p[i] + 1);
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