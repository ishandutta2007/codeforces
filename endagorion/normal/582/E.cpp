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

string lets = "abcdABCD";
vi bfs;

string s;
int pos;

const i64 P = 1000000000 + 7;

vi64 sos(vi64 a) {
    vi64 res = a;
    forn(i, 16) forn(m, 1 << 16) {
        if (((m >> i) & 1)) continue;
        (res[m | (1 << i)] += res[m]) %= P;
    }
    return res;
}

vi64 unsos(vi64 a) {
    vi64 res = a;
    forn(i, 16) forn(m, 1 << 16) {
        if (((m >> i) & 1)) continue;
        (res[m | (1 << i)] += P - res[m]) %= P;
    }
    return res;
}

vi64 parse() {
    char c = s[pos++];
    vi64 res(1 << 16);
    if (c == '(') {
        vi64 a = parse();
        ++pos;
        c = s[pos++];
        ++pos;
        vi64 b = parse();
        ++pos;
        for (char op: {'&', '|'}) {
            if (c != '?' && c != op) continue;
            if (op == '&') {
                reverse(all(a));
                reverse(all(b));
            }

            vi64 sa = sos(a);
            vi64 sb = sos(b);
            forn(i, 1 << 16) (sa[i] *= sb[i]) %= P;
            vi64 p = unsos(sa);

            if (op == '&') {
                reverse(all(a));
                reverse(all(b));
                reverse(all(p));
            }
            forn(i, 1 << 16) (res[i] += p[i]) %= P;
        }
    } else {
        forn(i, 8) {
            if (c != '?' && c != lets[i]) continue;
            ++res[bfs[i]];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    forn(z, 2) forn(i, 4) {
        int mask = 0;
        forn(m, 16) {
            if (((m >> i) & 1) == z) mask |= 1 << m;
        }
        bfs.pb(mask);
    }
    cin >> s;
    int n;
    cin >> n;
    vi xs(n), vs(n);
    forn(i, n) {
        forn(j, 4) {
            int x;
            cin >> x;
            xs[i] |= x << j;
        }
        cin >> vs[i];
    }

    auto res = parse();
    i64 ans = 0;
    forn(m, 1 << 16) {
//        if (res[m]) cerr << bitset<16>(m) << ' ' << res[m] << '\n';
        bool good = true;
        forn(i, n) good &= ((m >> xs[i]) & 1) == vs[i];
        if (good) (ans += res[m]) %= P;
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}