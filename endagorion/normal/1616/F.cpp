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

typedef bitset<514> bs;

bs odd, even;

bs add(const bs &a, const bs &b) {
    bs r = a ^ b;
    bs both = ((r & even) >> 1) & r;
    r ^= both | both << 1;
    bs ab = a & b;
    r ^= (ab & odd) << 1;
    r ^= (ab & even) >> 1;
    return r;
}

int coord(const bs &b, int i) {
    return 2 * b[2 * i + 1] + b[2 * i];
}

bs mul(const bs &b, int x) {
    if (!x) return bs();
    if (x == 1) return b;
    bs bodd = b & odd, beven = b & even;
    return (bodd << 1) | (beven >> 1);
}

const int maxn = 64;
int eid[maxn][maxn];

vector<bs> r;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        odd.reset();
        even.reset();
        forn(i, m + 1) {
            odd[2 * i] = 1;
            even[2 * i + 1] = 1;
        }
        r.clear();
        forn(i, n) forn(j, n) eid[i][j] = -1;
        forn(i, m) {
            int u, v, x;
            cin >> u >> v >> x;
            --u; --v;
            eid[u][v] = eid[v][u] = i;
            if (x > 0) {
                --x;
                bs b;
                b[2 * i] = 1;
                forn(z, 2) b[2 * m + z] = (x >> z) & 1;
                r.pb(b);
            }
        }
        forn(i, n) forn(j, i) forn(k, j) {
            if (eid[i][j] == -1 || eid[i][k] == -1 || eid[j][k] == -1) continue;
            int e1 = eid[i][j], e2 = eid[i][k], e3 = eid[j][k];
            bs b;
            b[2 * e1] = b[2 * e2] = b[2 * e3] = 1;
            r.pb(b);
        }

        int ri = 0;
        int R = r.size();
        forn(i, m) {
            int bj = -1;
            fore(j, ri, R - 1) {
                if (coord(r[j], i)) {
                    bj = j; break;
                }
            }
            if (bj == -1) continue;
            swap(r[ri], r[bj]);
            r[ri] = mul(r[ri], coord(r[ri], i));
            fore(j, ri + 1, R - 1) r[j] = add(r[j], mul(r[ri], 2 * coord(r[j], i) % 3));
            ++ri;
        }

        bool ok = true;
        fore(j, ri, R - 1) ok &= r[j].none();
/*        forn(j, R) {
            cerr << j << ": ";
            forn(i, m + 1) {
                int x = coord(r[j], i);
                if (x) cerr << i << ": " << x << ", ";
            }
            cerr << '\n';
        }*/
        if (!ok) {
            cout << -1 << '\n';
            continue;
        }
        forn(j, ri) {
            int k = r[j]._Find_first() / 2;
            forn(jj, j) r[jj] = add(r[jj], mul(r[j], 2 * coord(r[jj], k) % 3));
        }


        vi ans(m);
        forn(j, ri) {
            int k = r[j]._Find_first() / 2;
            ans[k] = coord(r[j], m);
        }
        forn(i, m) cout << ans[i] + 1 << ' ';
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}