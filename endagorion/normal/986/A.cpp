#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
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
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 110000, maxk = 110;
vi e[maxn];
int t[maxn];
int d[maxk][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, k, s;
    cin >> n >> m >> k >> s;
    forn(i, n) cin >> t[i], --t[i];
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }

    forn(i, k) {
        forn(j, n) d[i][j] = 1e9;
        vi q;
        forn(j, n) if (t[j] == i) q.pb(j), d[i][j] = 0;
        forn(cur, q.size()) {
            int v = q[cur];
            for (int u: e[v]) {
                if (d[i][u] > 1e8) {
                    d[i][u] = d[i][v] + 1;
                    q.pb(u);
                }
            }
        }
    }

    forn(i, n) {
        vi vals(k);
        forn(j, k) vals[j] = d[j][i];
        sort(all(vals));
        nth_element(vals.begin(), vals.begin() + s - 1, vals.end());
        cout << accumulate(vals.begin(), vals.begin() + s, 0) << ' ';
    }
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}