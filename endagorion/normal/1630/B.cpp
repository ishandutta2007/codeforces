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
        int n, k;
        cin >> n >> k;
        vi a(n);
        forn(i, n) cin >> a[i], --a[i];
        vi cnt(n);
        for (int x: a) ++cnt[x];
        int bl = -1e9, br = -1;
        int R = 0;
        int ins = 0;
        forn(L, n) {
            while (R < n && ins < (n - ins) + k) {
                ins += cnt[R];
                ++R;
            }
            if (ins >= (n - ins) + k) {
                if (R - L < br - bl) bl = L, br = R;
            }
            ins -= cnt[L];
        }
        cout << bl + 1 << ' ' << br << '\n';
        int lb = 0, x = 1;
        int bal = 0;
        forn(i, n) {
            if (bl <= a[i] && a[i] < br) ++bal;
            else --bal;
            if (x < k && bal == x) {
                cout << lb + 1 << ' ' << i + 1 << '\n';
                lb = i + 1;
                ++x;
            }
        }
        cout << lb + 1 << ' ' << n << '\n';
        cout << '\n';
    }
    
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}