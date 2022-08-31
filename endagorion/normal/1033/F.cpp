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

int a[1 << 12];
i64 aa[1 << 24];

i64 query(const string &s, int i, int m) {
    if (i == s.size()) return aa[m];
    if (s[i] == 'A') return query(s, i + 1, 4 * m) + query(s, i + 1, 4 * m + 1);
    if (s[i] == 'O') return query(s, i + 1, 4 * m);
    if (s[i] == 'X') return query(s, i + 1, 4 * m) + query(s, i + 1, 4 * m + 2);
    if (s[i] == 'a') return query(s, i + 1, 4 * m + 2);
    if (s[i] == 'o') return query(s, i + 1, 4 * m + 1) + query(s, i + 1, 4 * m + 2);
    if (s[i] == 'x') return query(s, i + 1, 4 * m + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    // kekw

    int w, n, m;
    cin >> w >> n >> m;
    forn(i, n) {
        int x;
        cin >> x;
        ++a[x];
    }

    forn(b1, 1 << w) forn(b2, 1 << w) {
        int sb = 0;
        forn(i, w) sb += (((b1 >> i) & 1) + ((b2 >> i) & 1)) << (2 * i);
        aa[sb] += 1LL * a[b1] * a[b2];
    }

    forn(i, m) {
        string s;
        cin >> s;
        cout << query(s, 0, 0) << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}