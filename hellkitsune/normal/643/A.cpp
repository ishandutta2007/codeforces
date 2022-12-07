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

const int N = 5 * 1000 + 13;
int n;
int t[N];

inline bool read()
{
	if (scanf ("%d", &n) != 1)
		return false;
		
	forn (i, n)
	{
		assert(scanf ("%d", &t[i]) == 1);
		t[i]--;
	}

	return true;
}

int ans[N];
int cnt[N];

inline void solve()
{
	forn (i, n)
	{
		forn (j, n)
			cnt[j] = 0;
			
		int cur = -1;
		fore (j, i, n - 1)
		{
			cnt[ t[j] ]++;
			
			if (cur == -1 || cnt[ t[j] ] > cnt[ cur ] || (cnt[ t[j] ] == cnt[cur] && t[j] < cur))
				cur = t[j];
				
			ans[cur]++;
		}
	}
	
	forn (i, n)
		printf ("%d ", ans[i]);
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