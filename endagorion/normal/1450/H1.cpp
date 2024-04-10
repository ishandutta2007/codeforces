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

const i64 P = 998244353;
const int maxn = 210000;
i64 fact[maxn], tcaf[maxn];

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

i64 cnk(int n, int k) {
    return fact[n] * tcaf[k] % P * tcaf[n - k] % P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    fact[0] = 1;
    for1(i, maxn - 1) fact[i] = i * fact[i - 1] % P;
    forn(i, maxn) tcaf[i] = deg(fact[i], -1);

    int n, m;
    string s;
    cin >> n >> m >> s;
    int delta = 0, cnt = 0;
    forn(i, n) {
        if (s[i] == 'w') delta += (delta % 2 ? -1 : 1);
        else if (s[i] == 'b') delta += (delta % 2 ? 1 : -1);
        else {
            ++cnt;
            --delta;
        }
    }

    bool any = false;
    i64 total = 0, good = 0;
    forn(i, cnt + 1) {
        int x = delta + 2 * i;
        if (x % 4 != 0) continue;
        any = true;
        (total += cnk(cnt, i)) %= P;
        (good += abs(x) * cnk(cnt, i) / 4) %= P;
    }

//    cerr << total << ' ' << good << ' ' << delta << ' ' << cnt << '\n';

    if (!any) cout << -1 << '\n';
    else cout << good * deg(total, -1) % P << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}