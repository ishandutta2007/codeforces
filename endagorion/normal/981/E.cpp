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

const i64 P = 1000000000000000000LL + 177;
const int maxn = 10001;

i64 w[maxn];
bool can[maxn];
vi e[maxn];

void add(i64 &x, i64 y) {
    x += y;
    while (x >= P) x -= P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q;
    cin >> n >> q;
    forn(i, q) {
        int l, r, x;
        cin >> l >> r >> x;
        --l;
        e[l].pb(x);
        e[r].pb(-x);
    }

    w[0] = 1;
    
    forn(i, n) {
        for (int x: e[i]) {
            if (x > 0) ford(i, n - x + 1) add(w[i + x], w[i]);
            else forn(i, n + x + 1) add(w[i - x], P - w[i]);
        }
        forn(j, n + 1) {
            if (w[j]) can[j] = 1;
        }
    }

    vi ans;
    for1(i, n) if (can[i]) ans.pb(i);
    cout << ans.size() << '\n';
    for (int x: ans) cout << x << ' ';
    cout << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}