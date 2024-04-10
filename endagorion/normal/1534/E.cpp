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

const int maxn = 501;
int dist[maxn], prv[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
//    freopen("input.txt", "rt", stdin);
#endif

    int n, k;
    cin >> n >> k;

    forn(i, n + 1) dist[i] = 1e9;
    dist[0] = 0;
    vi q = {0};
    forn(cur, q.size()) {
        int v = q[cur];
        forn(c, k + 1) {
            if (c > v) continue;
            if (v - c + k > n) continue;
            int nv = k + v - 2 * c;
            if (dist[nv] < 1e8) continue;
            dist[nv] = dist[v] + 1;
            prv[nv] = v;
            q.pb(nv);
        }
    }

    if (dist[n] > 1e8) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    int v = n;
    vi a(n, 1);
    while (v > 0) {
        int pv = prv[v];
        int c = (pv + k - v) / 2;
        int nc = k - c;
        vi lst;
        cout << "? ";
        forn(i, n) {
            if (a[i] == 0 && c > 0) --c, a[i] ^= 1, cout << i + 1 << ' ';
            else if (a[i] == 1 && nc > 0) --nc, a[i] ^= 1, cout << i + 1 << ' ';
        }
        cout << endl;
        int res;
        cin >> res;
        ans ^= res;
        v = pv;
    }
    cout << "! " << ans << endl;

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}