#include <iostream>
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

const int maxn = 101;
const int maxq = 11001;
int a[maxn][maxn];
int t[maxq], r[maxq], c[maxq], z[maxq];

int n, m, q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m >> q;
    forn(i, q) {
        cin >> t[i];
        if (t[i] == 1) cin >> r[i];
        if (t[i] == 2) cin >> c[i];
        if (t[i] == 3) cin >> r[i] >> c[i] >> z[i];
    }
    ford(i, q) {
        --r[i]; --c[i];
        if (t[i] == 1) {
            ford(j, m - 1) swap(a[r[i]][j], a[r[i]][j + 1]);
        }
        if (t[i] == 2) {
            ford(j, n - 1) swap(a[j][c[i]], a[j + 1][c[i]]);
        }
        if (t[i] == 3) a[r[i]][c[i]] = z[i];
    }
    forn(i, n) {
        forn(j, m) cout << a[i][j] << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}