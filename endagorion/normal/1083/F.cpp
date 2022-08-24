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

const int maxn = 210000, BUBEN = 300;
short a[2][maxn];

short getx(int i) {
    return a[0][i] ^ a[1][i];
}

vector< vector<short> > difs, shifts;
vector<vvi> cnts;

int bad = 0, ans = 0;

int n, k, q;

void change_bad(int p, int d) {
    int i = difs[p].size() - 1;
    if (difs[p][i] != shifts[p][i / BUBEN]) bad += d;
}

void change_dif(int p, int i, short x) {
    if (difs[p][i] == shifts[p][i / BUBEN]) --ans;
    if (!cnts[p].empty()) --cnts[p][i / BUBEN][difs[p][i]];
    difs[p][i] ^= x;
    if (!cnts[p].empty()) ++cnts[p][i / BUBEN][difs[p][i]];
    if (difs[p][i] == shifts[p][i / BUBEN]) ++ans;
}

void change_shift(int p, int i, short x) {
    assert(!cnts[p].empty());
    ans -= cnts[p][i][shifts[p][i]];
    shifts[p][i] ^= x;
    ans += cnts[p][i][shifts[p][i]];
}

void change(int p, int i, short x) {
    change_bad(p, -1);
    for (; i < difs[p].size() && i % BUBEN; ++i) change_dif(p, i, x);
    if (i != difs[p].size()) {
        i /= BUBEN;
        for (; i < shifts[p].size(); ++i) change_shift(p, i, x);
    }
    change_bad(p, 1);
}

int get_ans() {
//    cerr << bad << ' ' << ans << '\n';
    if (bad) return -1;
    return n - ans;
}

int dumb() {
    vi px(k);
    int ans = n + 1;
    forn(i, n + 1) {
        px[i % k] ^= getx(i) ^ getx(i + 1);
        if (!px[i % k]) --ans;
    }
    if (*max_element(all(px))) return -1;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> k >> q;
    forn(i, 2) forn(j, n) cin >> a[i][j + 1];
    difs.assign(k, vector<short>(1));
    shifts.resize(k);
    cnts.resize(k);
    ans = n;
    forn(i, n + 1) {
        int p = i % k;
        short v = getx(i) ^ getx(i + 1);
        short z = difs[p].back();
        difs[p].pb(z ^ v);
        if (difs[p].back()) --ans;
    }

    int ts = 0;
    forn(i, k) {
        int len = difs[i].size();
        int sz = (len + BUBEN - 1) / BUBEN;
        shifts[i].resize(sz);
        if (len >= BUBEN) cnts[i].assign(sz, vi(1 << 14)), ts += (sz << 14);
        if (!cnts[i].empty()) forn(j, len) ++cnts[i][j / BUBEN][difs[i][j]];
        if (difs[i].back()) ++bad;
    }

    cerr << ts << '\n';
//    cerr << get_ans() << ' ' << dumb() << '\n';
    cout << get_ans() << '\n';
    forn(i, q) {
//        cerr << i << '\n';
        char c;
        int j;
        short x;
        cin >> c >> j >> x;
        int cc = c - 'a';
        short xx = x;
        x ^= a[cc][j];
        a[cc][j] = xx;
        change(j % k, j / k + 1, x);
        change((j - 1) % k, (j - 1) / k + 1, x);
//        cerr << get_ans() << ' ' << dumb() << '\n';
        cout << get_ans() << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}