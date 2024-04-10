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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    i64 t;
    cin >> n >> t;
    string s;
    cin >> s;
    i64 sum = 0;
    vi64 cnt(50);
    t -= (1 << (s.back() - 'a'));
    s = string(all(s) - 1);
    t += (1 << (s.back() - 'a'));
    s = string(all(s) - 1);
    for (char c: s) ++cnt[c - 'a'];
    forn(i, 26) t += (cnt[i] << i);
    if (t % 2) {
        cout << "No\n";
        return 0;
    }

    t /= 2;
    forn(i, 49) {
        int z = (cnt[i] - 1) / 2;
        cnt[i] -= 2 * z;
        cnt[i + 1] += z;
    }

    set<i64> q = {t};
    forn(i, 50) {
        set<i64> nq;
        for (i64 x: q) forn(j, cnt[i] + 1) {
            i64 y = x - j;
            if (y % 2) continue;
            nq.insert(y / 2);
        }
        q = nq;
    }

    cout << (q.count(0) ? "Yes" : "No") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}