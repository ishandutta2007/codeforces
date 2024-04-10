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

const int maxn = 22;
i64 st[maxn], len[maxn], t[maxn];
i64 dp[1 << maxn];
int prvi[1 << maxn];
i64 prvS[1 << maxn];

int pi[maxn], ps[maxn];

void restore(int mask, int qi) {
    while (mask) {
        int i = prvi[mask];
        pi[i] = qi;
        ps[i] = prvS[mask];
        mask ^= 1 << i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, p;
    cin >> n >> p;
    forn(i, n) cin >> st[i] >> len[i] >> t[i];
    forn(mask, 1 << n) dp[mask] = 1e18;
    dp[0] = 1;
    vi stord(n), tord(n);
    forn(i, n) stord[i] = tord[i] = i;
    sort(all(stord), [&](int i, int j){return st[i] < st[j];});
    sort(all(tord), [&](int i, int j){return t[i] < t[j];});

    forn(mask, 1 << n) {
        int ptr = 0;
        i64 S = dp[mask];
//        cerr << mask << ' ' << S << '\n';
        for (int i: tord) {
            if ((mask >> i) & 1) continue;
            while (ptr < n) {
                int j = stord[ptr];
                if (S >= st[j]) uax(S, st[j] + len[j]);
                if (((mask >> j) & 1) && S + t[i] >= st[j]) uax(S, st[j] + len[j]);
                if (S + t[i] < st[j]) break;
                ++ptr;
            }
//            cerr << mask << ' ' << i << ' ' << S << '\n';
            if (S + t[i] < st[i] && uin(dp[mask | (1 << i)], S + t[i])) {
                prvi[mask | (1 << i)] = i;
                prvS[mask | (1 << i)] = S;
            }
        }
    }

    bool output = false;
    if (p == 1) {
        output = dp[(1 << n) - 1] < 1e17;
        if (output) restore((1 << n) - 1, 1);
    } else {
        forn(m1, 1 << n) {
            int m2 = m1 ^ ((1 << n) - 1);
            if (dp[m1] < 1e17 && dp[m2] < 1e17) {
                output = true;
                restore(m1, 1);
                restore(m2, 2);
                break;
            }
        }
    }

    if (output) {
        cout << "YES\n";
        forn(i, n) cout << pi[i] << ' ' << ps[i] << '\n';
    } else cout << "NO\n";

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}