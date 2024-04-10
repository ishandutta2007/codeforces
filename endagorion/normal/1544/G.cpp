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

int n, k;

void op(int lg, bool l0, string &s, vector<pii> &ops) {
    vi ones = {-1};
    forn(i, s.size()) if (s[i] == '1') ones.pb(i);
    ones.pb(s.size());
    int L, R;
    if (l0) L = ones[lg] + 1, R = ones[lg + k];
    else L = ones[lg + 1], R = ones[lg + k + 1] - 1;
//    cerr << s << ' ' << lg << ' ' << l0 << '\n';
//    cerr << L << ' ' << R << '\n';
    string t = s;
    assert(count(s.begin() + L, s.begin() + R + 1, '1') == k);
    reverse(s.begin() + L, s.begin() + R + 1);
    if (t != s) ops.pb(mp(L, R));
}

void minim(string &s, int c, vector<pii> &ops) {
    for (int i = c; i >= k; --i) op(i - k, false, s, ops);
    int R = k - 1;
    while (R > 1) {
        op(1, true, s, ops);
        op(0, false, s, ops);
        R -= 2;
    }
    op(1, false, s, ops);
//    cerr << s << '\n';
    if (k == 1) op(0, false, s, ops);
    else if (k % 2 == 1) {
        int i = 1;
        while (i != k - 1) {
            op(0, false, s, ops);
            i = k - i - 1;
            op(1, false, s, ops);
            i = k - i;
        }
        op(0, false, s, ops);
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

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> k;
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == s2) {
            cout << 0 << '\n';
            continue;
        }
        int c1 = count(all(s1), '1'), c2 = count(all(s2), '1');
        if (c1 != c2 || c1 < k || k == 0) {
            cout << -1 << '\n';
            continue;
        }
        vector<pii> ops1, ops2;
        if (c1 == k) {
            op(0, false, s1, ops1);
            op(0, false, s2, ops2);
            if (s1 != s2) op(0, false, s1, ops1);
//            cerr << s1 << ' ' << s2 << '\n';
        } else {
            minim(s1, c1, ops1);
            minim(s2, c2, ops2);
        }
        if (s1 == s2) {
            assert(ops1.size() + ops2.size() <= 4 * n);
            cout << ops1.size() + ops2.size() << '\n';
            for (auto [x, y]: ops1) cout << x + 1 << ' ' << y + 1 << '\n';
            reverse(all(ops2));
            for (auto [x, y]: ops2) cout << x + 1 << ' ' << y + 1 << '\n';
//            cout << 0 << '\n';
        }
        else cout << -1 << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}