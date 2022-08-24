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
int fenw[2][maxn];

void add(int *f, int i, int x) {
    for (; i < maxn; i |= i + 1) f[i] += x;
}

int sum(int *f, int i) {
    int s = 0;
    for (; i >= 0; i &= i + 1, --i) s += f[i];
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    forn(i, n - 1) if (s[i] == s[i + 1]) add(fenw[s[i] - '0'], i, 1);
    while (q--) {
        int L, R;
        cin >> L >> R;
        --L;
        int ans = 0;
        forn(z, 2) uax(ans, sum(fenw[z], R - 2) - sum(fenw[z], L - 1));
        cout << ans + 1 << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}