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

map<pair<int, i64>, int> gr;

int get_gr(int x, i64 mask) {
    mask &= (1LL << (x + 1)) - 1;
    if (gr.count({x, mask})) return gr[{x, mask}];
    vi v;
    for1(i, x) {
        if ((mask >> i) & 1) continue;
        v.pb(get_gr(x - i, mask | (1LL << i)));
    }
    v.pb(-1);
    sort(all(v));
    v.pb(1e9);
    forn(i, v.size()) {
        if (v[i] + 1 < v[i + 1]) return gr[{x, mask}] = v[i] + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    int ans = 0;
    forn(i, n) {
        int x;
        cin >> x;
        ans ^= get_gr(x, 0);
    }
    cout << (ans ? "NO" : "YES") << '\n';
    cerr << gr.size() << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}