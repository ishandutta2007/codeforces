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

const int maxn = 210000;
int p[maxn], inv[maxn];
int side[maxn], vis[maxn];

vector<pii> op;

void swp(int i, int j) {
//    cerr << "swp " << i << ' ' << j << '\n';
    assert(i != j);
    side[i] ^= 1;
    side[j] ^= 1;
    op.pb({p[i], p[j]});
    swap(p[i], p[j]);
    swap(inv[p[i]], inv[p[j]]);
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
    forn(i, n) {
        int x;
        cin >> x;
        --x;
        p[x] = i;
        inv[i] = x;
    }

    int m = -1;
    forn(i, n) {
        if (vis[i]) continue;
        for (int j = i; !vis[j]; j = p[j]) vis[j] = 1;
        if (p[i] == i) continue;
        if (m != -1) swp(m, i), m = -1;
        else m = i;
    }

    cerr << m << '\n';

    if (m != -1) {
        forn(i, n) vis[i] = 0;
        int len = 0;
        for (int j = m; !vis[j]; j = p[j]) vis[j] = 1, ++len;
        if (len < n) {
            int mm = -1;
            forn(i, n) {
                if (side[i] || vis[i]) continue;
                mm = i;
                break;
            }
            assert(mm != -1);
            swp(m, mm);
        } else {
//            cerr << "here\n";
            int x = m, y = inv[x], z = inv[y];
            swp(x, y);
            swp(x, z);
        }
    }

//    forn(i, n) cerr << p[i] << ' ' << side[i] << '\n';

    forn(j, n) {
        if (side[inv[j]]) {
            while (1) {
                int i = inv[j];
                assert(i != j);
                if (side[inv[i]]) break;
                swp(i, inv[i]);
            }
        }
    }

//    forn(i, n) cerr << inv[i] << ' ' << side[inv[i]] << '\n';

    forn(j, n) {
        if (side[j]) {
            while (j != inv[j]) {
                swp(j, p[j]);
            }
//            cerr << j << ":\n";
//            forn(i, n) cerr << p[i] << ' ' << side[i] << '\n';
        }
    }

    assert(op.size() <= n + 1);
//    forn(i, n) cerr << p[i] << ' ' << side[i] << '\n';
    forn(i, n) assert(p[i] == i && !side[i]);

    cout << op.size() << '\n';
    for (auto [x, y]: op) {
        if (x > y) swap(x, y);
        cout << x + 1 << ' ' << y + 1 << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}