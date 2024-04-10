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

string s0, t;
const i64 P = 1000000000 + 7;

i64 deg(i64 x, i64 d) {
    if (d < 0) d += P - 1;
    i64 y = 1;
    while (d) {
        if (d & 1) (y *= x) %= P;
        d /= 2;
        (x *= x) %= P;
    }
    return y;
}


int n, q;
const int maxn = 110000;
i64 cnt[maxn][26];
i64 d2[maxn], id2[maxn];

string w;

i64 tcnt(int c, int l, int r) {
//    cerr << c << ' ' << l << ' ' << r << ' ' << cnt[l][c] << ' ' << cnt[r][c] << '\n';
    return (cnt[l][c] - cnt[r][c]) * id2[n - r] % P;
}

i64 tocc(string s, int i, int k) {
//    cerr << s << ' ' << i << ' ' << k << '\n';
    if (s.size() == 0) return d2[k - i];
    if (s.size() == 1) return tcnt(s[0] - 'a', i, k);
    if (i >= k) return 0;
    string ns[2] = {"", ""};
    forn(p, s.size()) ns[p % 2].pb(s[p]);
    i64 ans = 0;
    forn(z, 2) {
        if (ns[z ^ 1] != string(ns[z ^ 1].size(), t[i])) continue;
        (ans += tocc(ns[z], i + 1, k)) %= P;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> q;
    cin >> s0 >> t;

    d2[0] = 1;
    forn(i, n + 1) d2[i + 1] = d2[i] * 2 % P;
    forn(i, n + 2) id2[i] = deg(d2[i], -1);
    forn(c, 26) {
        cnt[n][c] = 0;
        ford(i, n) cnt[i][c] = (cnt[i + 1][c] + d2[n - i - 1] * (t[i] == (char)('a' + c) ? 1 : 0)) % P;
    }

    while (q--) {
        int k;
        cin >> k >> w;
        int per = s0.size() + 1;
        i64 ans = 0;
        forn(z, per) {
            bool ok = true;
            string nt;
            forn(j, w.size()) {
                if (j % per == z) nt += w[j];
                else ok &= w[j] == s0[(j - z + per) % per - 1];
            }
            if (!ok) continue;
            (ans += tocc(nt, 0, k)) %= P;
        }

        if (ans < 0) ans += P;
        cout << ans << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}