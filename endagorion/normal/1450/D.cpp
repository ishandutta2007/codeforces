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

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi cnt(n);
        vi win(n);
        vi a(n);
        forn(i, n) {
            int x;
            cin >> x;
            --x;
            a[i] = x;
            ++cnt[x];
        }

        win[0] = 1;
        forn(i, n) if (cnt[i] > 1) win[0] = 0;
        int L = 0, R = n;
//        win[n - 1] = !pos[0].empty();
        forn(i, n - 1) {
            if (!cnt[i]) break;
            bool lft = a[L] == i, rgt = a[R - 1] == i;
            win[n - i - 1] = 1;
            if (!lft && !rgt) break;
            if (cnt[i] > 1) break;
            if (lft) ++L;
            if (rgt) --R;
        }
        forn(i, n) cout << win[i];
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}