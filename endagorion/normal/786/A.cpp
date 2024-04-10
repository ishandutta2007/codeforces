#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 10000;
int w[2][maxn], inc[2][maxn];

int main() {
#ifdef LOCAL_DEFINE
	freopen("input.txt", "rt", stdin);
#endif

	int n;
	cin >> n;
	vvi v(2);
	forn(i, 2) {
		vi &z = v[i];
		int k;
		cin >> k;
		z.resize(k);
		forn(j, k) cin >> z[j];
	}
	vector<pii> q;
	forn(j, 2) {
		w[j][0] = -1;
		q.pb(mp(j, 0));
	}

	forn(cur, q.size()) {
		pii p = q[cur];
		int pl = p.fi, x = p.se;
		for (int d: v[pl ^ 1]) {
			int xx = (x - d + n) % n;
			if (w[pl ^ 1][xx]) continue;
			if (w[pl][x] == -1) {
				w[pl ^ 1][xx] = 1;
				q.pb({pl ^ 1, xx});
			} else {
				++inc[pl ^ 1][xx];
//				cerr << (pl ^ 1) << ' ' << xx << ' ' << inc[pl ^ 1][xx] << '\n';
				if (inc[pl ^ 1][xx] == (int)v[pl ^ 1].size()) {	
					w[pl ^ 1][xx] = -1;
					q.pb({pl ^ 1, xx});
				}
			}
		}
	}
	forn(j, 2) {
		for1(i, n - 1) {
			if (w[j][i] == -1) cout << "Lose ";
			else if (w[j][i] == 1) cout << "Win ";
			else cout << "Loop ";
		}
		cout << '\n';
	}

#ifdef LOCAL_DEFINE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
}