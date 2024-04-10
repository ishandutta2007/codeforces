#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
#include <ctime>
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

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int m[1000][1000];

void invert(int a, int b, int c, int d, vector<pii> &res, bool inv) {
    assert(m[a][b] && m[a][c] && m[b][c] && m[a][d] && m[b][d] && !m[c][d]);
    m[a][b] = m[b][a] = 0;
    m[c][d] = m[d][c] = 1;
    res.pb(inv ? mp(c, d) : mp(a, b));
}

void dfs(int l, int r, vector<pii> &res, bool inv) {
    if (r - l <= 1) return;
    vi a;
    for (int i = r; i > l; --i) {
        if (m[l][i]) a.pb(i);
    }
    for (int i = 0; i + 1 < a.size(); ++i) {
        invert(l, a[i], 0, a[i + 1], res, inv);
        dfs(a[i + 1], a[i], res, inv);
    }
    dfs(a.back(), r, res, inv);
}

vector<pii> solve(vector<pii> tr, bool inv) {
    int N = tr.size() + 3;
    forn(i, N) forn(j, N) m[i][j] = 0;
    forn(i, N) m[i][(i + 1) % N] = m[(i + 1) % N][i] = 1;
    forn(i, tr.size()) {
        --tr[i].fi, --tr[i].se;
        m[tr[i].fi][tr[i].se] = m[tr[i].se][tr[i].fi] = 1;
    }
    vector<pii> res;
    dfs(1, N - 1, res, inv);
    return res;
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
    vector<pii> tr1(N - 3), tr2(N - 3);
    forn(i, N - 3) cin >> tr1[i].fi >> tr1[i].se;
    forn(i, N - 3) cin >> tr2[i].fi >> tr2[i].se;
    vector<pii> res1 = solve(tr1, false);
    vector<pii> res2 = solve(tr2, true);
    reverse(all(res2));
    res1.insert(res1.end(), all(res2));
    cout << res1.size() << '\n';
    for (pii p: res1) {
        cout << p.fi + 1 << ' ' << p.se + 1 << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}