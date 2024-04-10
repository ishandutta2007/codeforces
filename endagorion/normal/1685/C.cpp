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

bool good(const vi &a) {
    int b = 0;
    for (int x: a) {
        b += x;
        if (b < 0) return false;
    }
    assert(b == 0);
    return true;
}

string tostr(const vi &a) {
    string s;
    for (int x: a) s += (x == 1 ? '(' : ')');
    return s;
}

vi fromstr(const string &s) {
    vi a;
    for (char c: s) a.pb(c == '(' ? 1 : -1);
    return a;
}

int brute(string s) {
    int n = s.size() / 2;
    vi a = fromstr(s);
    vvi q = {a};
    map<vi, int> dist;
    dist[a] = 0;

    forn(cur, q.size()) {
        vi a = q[cur];
        if (good(a)) return dist[a];
        forn(r, 2 * n + 1) forn(l, r) {
            auto b = a;
            reverse(b.begin() + l, b.begin() + r);
            if (dist.count(b)) continue;
            dist[b] = dist[a] + 1;
//            prv[b] = a;
//            cerr << tostr(b) << ": " << dist[b] << '\n';
//            for (auto c = b; !good(c); c = prv[c]) cerr << tostr(prv[c]) << '\n';
            q.pb(b);
        }
    }
}

vector<pii> path;

int solve(string s) {
    vi a = fromstr(s);
    path.clear();
    if (good(a)) return 0;
    vi bal(a.size() + 1);
    forn(i, a.size()) bal[i + 1] = bal[i] + a[i];
    int L = 0, R = a.size();
    while (bal[L + 1] >= 0) ++L;
    while (bal[R - 1] >= 0) --R;
    L = max_element(bal.begin(), bal.begin() + L + 1) - bal.begin();
    R = max_element(bal.begin() + R, bal.end()) - bal.begin();
    vi b = a;
    reverse(b.begin() + L, b.begin() + R);
    if (good(b)) {
        path = {{L, R}};
        return 1;
    }
    int i = max_element(all(bal)) - bal.begin();
    b = a;
    reverse(b.begin(), b.begin() + i);
    reverse(b.begin() + i, b.end());
    assert(good(b));
    path = {{0, i}, {i, b.size()}};
    return 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

/*    for1(n, 9) {
        cerr << n << '\n';
        brute(n);
    }*/

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int res = solve(s);
//        assert(res == brute(s));
        cout << res << '\n';
        for (auto [l, r]: path) cout << l + 1 << ' ' << r << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}