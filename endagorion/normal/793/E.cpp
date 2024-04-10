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

const int maxn = 5100;
typedef bitset<maxn> bs;
int p[maxn], sz[maxn], pid[maxn];

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

    vi vs(4);
    for (int &x: vs) cin >> x, --x;
    swap(vs[1], vs[2]);

    for1(i, n - 1) cin >> p[i], --p[i];

    int L = 0;
    for (int i = n - 1; i > 0; --i) {
        if (!sz[i]) {
            sz[i] = 1;
            ++L;
        }
        sz[p[i]] += sz[i];
    }

    bool yes = false;
    if (L % 2 == 0) forn(z1, 2) {
        forn(z2, 2) {
            forn(i, n) pid[i] = 0;
            pid[0] = -1;
            forn(z, 4) for (int v = vs[z]; v > 0; v = p[v]) pid[v] = z;

            vector<bs> bv(2);
            forn(v, n) {
                if (p[v] != 0) continue;
                if (!(pid[v] & 1)) continue;
                int z = pid[v] / 2;
                bv[z ^ 1][sz[v]] = 1;
            }

            forn(v, n) {
                if (pid[v] || !pid[p[v]]) continue;
                if (p[v] == 0) {
                    forn(z, 2) bv[z] = bv[z] | (bv[z] << sz[v]);
                } else {
                    int z = pid[p[v]] / 2;
                    bv[z] = bv[z] | (bv[z] << sz[v]);
                }
            }

            yes |= bv[0][L / 2 - 1] && bv[1][L / 2 - 1];

            swap(vs[2], vs[3]);
        }
        swap(vs[0], vs[1]);
    }

    cout << (yes ? "YES" : "NO") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}