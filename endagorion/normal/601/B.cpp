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

const int maxn = 110000;
int a[maxn], b[maxn];
int l[maxn], r[maxn];

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
    forn(i, n) cin >> a[i];
    forn(i, n - 1) b[i] = abs(a[i + 1] - a[i]);
    vector<pii> p(n - 1);
    forn(i, n - 1) p[i] = mp(b[i], i);
    sort(rall(p));
    set<int> s;
    for (pii w: p) {
        int x = w.se;
        s.insert(x);
        auto it = s.find(x);
        if (it == s.begin()) l[x] = -1;
        else {
            --it;
            l[x] = *it;
            ++it;
        }
        if (it == s.end()) r[x] = n;
        else {
            ++it;
            if (it == s.end()) r[x] = n;
            else r[x] = *it;
            --it;
        }
    }
    forn(i, q) {
        int L, R;
        cin >> L >> R;
        --L; --R;
        i64 ans = 0;
        for (int j = L; j < R; ++j) {
            int ls = max(l[j] + 1, L);
            int rs = min(r[j], R);
//            cerr << j << ' ' << ls << ' ' << rs << '\n';
            ans += 1LL * b[j] * (j - ls + 1) * (rs - j);
        }
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}