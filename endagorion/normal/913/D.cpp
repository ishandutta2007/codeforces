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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, T;
    cin >> n >> T;
    vector<vpi> a(n + 1);
    int bs = -1, bk = -1;
    forn(i, n) {
        int x, t;
        cin >> x >> t;
        a[x].pb({t, i});
    }
    set<pii> q;
    i64 sum = 0;
    for (int k = n; k >= 1; --k) {
        for (auto w: a[k]) q.insert(w), sum += w.fi;
        while (sum > T || (int)q.size() > k) {
            auto w = *q.rbegin();
            sum -= w.fi;
            q.erase(w);
        }
        if (uax(bs, (int)q.size())) bk = k;
    }
    cout << bs << '\n' << bs << '\n';
    q.clear();
    sum = 0;
    for (int i = bk; i <= n; ++i) for (auto w: a[i]) q.insert(w), sum += w.fi;
    while (sum > T || (int)q.size() > bk) {
        auto w = *q.rbegin();
        sum -= w.fi;
        q.erase(w);
    }
    for (auto w: q) cout << w.se + 1 << ' ';
    cout << '\n';


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}