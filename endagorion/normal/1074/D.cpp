#include <iostream>
#include <unordered_map>
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

unordered_map<int, int> parent, val, rk;

int get_parent(int i) {
    if (!parent.count(i)) parent[i] = i, val[i] = 0;
    return parent[i];
}

int get_root(int v) {
    int p = get_parent(v);
    if (p == v) return v;
    int r = (parent[v] = get_root(p));
    val[v] ^= val[p];    
    return r;
}

void unite(int v, int u, int x) {
    int rv = get_root(v), ru = get_root(u);
    if (rv == ru) return;
    x ^= val[v] ^ val[u];
//    if (rk[rv] > rk[ru]) swap(rv, ru);
    parent[rv] = ru;
    val[rv] ^= x;
//    rk[ru] = max(rk[ru], rk[rv] + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int q;
    cin >> q;
    int last = 0;
    while (q--) {
        int t, l, r, x;
        cin >> t >> l >> r;
        if (t == 1) cin >> x;
        l ^= last;
        r ^= last;
        x ^= last;
        if (l > r) swap(l, r);
//        --l;
/*        cerr << t << ' ' << l << ' ' << r << ' ';
        if (t == 1) cerr << x << ' ';
        cerr << '\n';*/
        ++r;
        if (t == 1) unite(l, r, x);
        else {
            int rl = get_root(l), rr = get_root(r);
            int ans = (rl == rr ? val[l] ^ val[r] : -1);
            cout << ans << '\n';
            last = abs(ans);
        }
    }    

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}