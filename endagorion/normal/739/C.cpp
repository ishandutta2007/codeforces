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

const int maxn = 310000;
i64 d[maxn], a[maxn];

int sgn(i64 d) {
    if (d >= 0) return d > 0;
    return -1;
}

set<int> s;
multiset<int> len;

void sins(int p) {
    if (s.count(p)) return;
    int y = *s.upper_bound(p);
    int x = *--s.lower_bound(p);
    len.erase(len.find(y - x));
    s.insert(p);
    len.insert(y - p);
    len.insert(p - x);
}

void ser(int p) {
    if (!s.count(p)) return;
    int y = *s.upper_bound(p);
    int x = *--s.lower_bound(p);
    len.erase(len.find(y - p));
    len.erase(len.find(p - x));
    s.erase(p);
    len.insert(y - x);
}

bool good(pii p) {
    return p == mp(1, 1) || p == mp(1, -1) || p == mp(-1, -1);
}

int n;

void per(int l) {
    if (l < 0 || l >= n) return;
    if (!good(mp(sgn(d[l]), sgn(d[l + 1])))) ser(l);
}

void pins(int l) {
    if (l < 0 || l >= n) return;
    if (!good(mp(sgn(d[l]), sgn(d[l + 1])))) sins(l);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n;
    forn(i, n) cin >> a[i];
    d[0] = 0;
    int n0 = 0;
    forn(i, n - 1) d[i + 1] = a[i + 1] - a[i], n0 += (d[i + 1] != 0);
    d[n] = 0;
    s.insert(-1);
    s.insert(n);
    len.insert(n + 1);
    forn(i, n) {
        pii p = mp(sgn(d[i]), sgn(d[i + 1]));
        if (!good(p)) sins(i);
    }

    int m;
    cin >> m;
    forn(i, m) {
        int l, r, x;
        cin >> l >> r >> x;
        --l;
        per(l - 1); per(l); per(r - 1); per(r);
        if (l) {
            n0 -= d[l] != 0;
            d[l] += x;
            n0 += d[l] != 0;
        }
        if (r < n) {
            n0 -= d[r] != 0;
            d[r] -= x;
            n0 += d[r] != 0;
        }
        pins(l); pins(l - 1); pins(r); pins(r - 1);
        int ans = *len.rbegin() + 1;
        if (!n0) ans = 1;
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}