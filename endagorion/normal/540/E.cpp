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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int MAXN = 200000;

int fenw[MAXN];

void fenw_add(int x, int y) {
    for (; x < MAXN; x |= x + 1) fenw[x] += y;
}

int fenw_sum(int x) {
    int sum = 0;
    for (; x >= 0; x &= x + 1, --x) sum += fenw[x];
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    vector<pii> a(N);
    vi v;
    forn(i, N) {
        cin >> a[i].fi >> a[i].se;
        v.pb(a[i].fi);
        v.pb(a[i].se);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int K = v.size();
    map<int, int> en;
    forn(i, K) en[v[i]] = i;
    vi st = v;
    forn(i, N) {
        int x = en[a[i].fi], y = en[a[i].se];
        swap(st[x], st[y]);
    }
    i64 ans = 0;
    forn(i, K) {
        int x = en[st[i]];
        if (x != i) ans += abs(v[i] - v[x]) - abs(i - x);
    }
    ford(i, K) {
        int x = en[st[i]];
        ans += fenw_sum(x);
        fenw_add(x, 1);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}