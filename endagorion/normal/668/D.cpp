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
#include <unordered_map>

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

const int maxn = 1000001;

int a[maxn], t[maxn], x[maxn];
int f[maxn];

int fenw_sum(int i) {
    int s = 0;
    for (; i >= 0; i &= i + 1, --i) s += f[i];
    return s;
}

void fenw_add(int i, int x) {
    for (; i < maxn; i |= i + 1) f[i] += x;
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
    vector<pii> ps;
    forn(i, n) {
        cin >> a[i] >> t[i] >> x[i];
        ps.pb(mp(x[i], t[i]));
    }
    sort(all(ps));

    forn(i, n) {
        int r = lower_bound(all(ps), mp(x[i], t[i])) - ps.begin(), q = lower_bound(all(ps), mp(x[i], -1)) -ps.begin() - 1;
//        cerr << p << '\n';
        if (a[i] == 3) cout << fenw_sum(r) - fenw_sum(q) << '\n';
        else fenw_add(r, (a[i] == 1 ? 1 : -1));
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}