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
int par[maxn];

int root(int x) {
    return x == par[x] ? x : par[x] = root(par[x]);
}

void unite(int u, int v) {
//    cerr << u << ' ' << v << '\n';
    u = root(u);
    v = root(v);
    if (u != v) par[u] = v;
}

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
        int n;
        string s;
        cin >> n >> s;
        forn(i, 2 * n) par[i] = i;
        vvi byBal(n + 2);
        byBal[0].pb(0);
        int bal = 0;
        forn(i, 2 * n) {
            if (s[i] == '(') {
                ++bal;
                byBal[bal].clear();
            } else {
                byBal[bal].clear();
                --bal;
            }
            int z = min(2, (int)byBal[bal].size());
            forn(y, z) {
                int j = byBal[bal].end()[-y - 1];
                unite(j, i);
            }
            byBal[bal].pb(i + 1);
        }

        int ans = 0;
        forn(i, 2 * n) if (root(i) == i) ++ans;
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}