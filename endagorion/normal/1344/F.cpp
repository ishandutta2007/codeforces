#include <bits/stdc++.h>

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

int n, k;
const int maxn = 1000;
typedef bitset<2 * maxn + 1> bs;
int m[maxn][2];

int tr[3][2] = {{2, 1}, {1, 3}, {3, 2}};

void mul(int i, int ti) {
    int b[2] = {0, 0};
    forn(x, 2) forn(y, 2) forn(z, 2) if ((tr[ti][x] >> y) & (m[i][y] >> z) & 1) b[x] ^= 1 << z;
    forn(z, 2) m[i][z] = b[z];
}

string colors = "WRYB";

vector<bs> rs;

void add(bs b) {
    for (auto &r: rs) {
        if (b.none()) break;
        int bi = b._Find_first(), ri = r._Find_first();
        if (bi < ri) swap(b, r), swap(bi, ri);
        if (bi == ri) b ^= r;
    }
    if (b.any()) rs.pb(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> k;
    forn(i, n) {
        m[i][0] = 1;
        m[i][1] = 2;
    }

    forn(i, k) {
        string s;
        int sz;
        cin >> s >> sz;
        vi inds(sz);
        forn(i, sz) {
            cin >> inds[i];
            --inds[i];
        }
        if (s == "mix") {
            char t;
            cin >> t;
            int res = find(all(colors), t) - colors.begin();
            forn(z, 2) {
                bs b;
                b[2 * maxn] = (res >> z) & 1;
                for (int i: inds) {
                    forn(y, 2) {
                        b[2 * i + y] = (m[i][z] >> y) & 1;
                    }
                }
                add(b);
            }
        } else {
            int ti;
            if (s == "RY") ti = 0;
            else if (s == "RB") ti = 1;
            else ti = 2;
            for (int i: inds) mul(i, ti);
        }
    }
    vi ans(n);
    bool ok = true;
    ford(i, rs.size()) {
        int ri = rs[i]._Find_first();
        forn(j, i) if (rs[j][ri]) rs[j] ^= rs[i];
    }
    for (auto &r: rs) {
        int i = r._Find_first();
        if (i == 2 * maxn) ok = false;
        else ans[i / 2] |= r[2 * maxn] << (i & 1);
    }
    if (!ok) cout << "NO\n";
    else {
        cout << "YES\n";
        forn(i, n) cout << ".RYB"[ans[i]];
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}