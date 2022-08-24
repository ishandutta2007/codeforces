#include <iostream>
#include <bitset>
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

const int MAXN = 150;
typedef vector<bitset<MAXN> > Matrix;

Matrix transpose(const Matrix &m) {
    int n = m.size();
    Matrix res(n);
    forn(i, n) forn(j, n) if (m[i][j]) res[j].set(i);
    return res;
}

Matrix mul(Matrix a, Matrix b) {
    int n = a.size();
    b = transpose(b);
    Matrix c(n);
    forn(i, n) forn(j, n) c[i][j] = (a[i] & b[j]).any();
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M;
    cin >> N >> M;
    vector< pair<int, pii> > e(M);
    forn(i, M) cin >> e[i].se.fi >> e[i].se.se >> e[i].fi, --e[i].se.fi, --e[i].se.se;
    e.pb(mp((int)2e9, mp(N - 1, N - 1)));
    sort(all(e));
    Matrix m(N);
    m[N - 1].set(N - 1);
    Matrix res = m;
    forn(i, N) res[i].set(i);
    Matrix id = res;
    int pt = 0;
    for (auto w: e) {
//        cerr << w.fi << '\n';
        int tt = w.fi - pt;
        vector<Matrix> mc;
        Matrix mt = m;
        mc.pb(mt);
        while ((1LL << ((int)mc.size() - 1)) < tt) {
            mt = mul(mt, mt);
            mc.pb(mt);
        }
        Matrix z = res;
        forn(i, mc.size()) {
            if ((tt >> i) & 1) z = mul(z, mc[i]);
        }
        if (z[0][N - 1]) {
            int ans = pt;
            ford(i, mc.size()) {
                z = mul(res, mc[i]);
                if (!z[0][N - 1]) {
                    ans += (1 << i);
                    res = z;
                }
            }
            cout << ans + 1 << '\n';
            return 0;
        }
        res = z;
        m[w.se.fi].set(w.se.se);
        pt = w.fi;
    }
    cout << "Impossible\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}