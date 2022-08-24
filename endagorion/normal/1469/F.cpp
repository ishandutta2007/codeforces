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
    i64 k;
    cin >> n >> k;
    vi64 a(n);
    forn(i, n) cin >> a[i];
    sort(rall(a));

    int L = 0, R = 4e5;
    while (R - L > 1) {
        int M = (L + R) / 2;
        vi64 delta(M + 2);
        delta[0] = 1;
        delta[1] = -1;
        int ptr = 0;
        i64 v = 0, total = 0;
        forn(i, M + 1) {
            v += delta[i];
            while (i + 2 <= M && v && ptr < n) {
                --v; --delta[i]; ++delta[i + 1];
                int l = a[ptr++];
                int l1 = l / 2, l2 = l - 1 - l1;
                ++delta[i + 2]; --delta[min(i + 2 + l1, M + 1)];
                ++delta[i + 2]; --delta[min(i + 2 + l2, M + 1)];
            }
            total += v;
        }
//        cerr << M << ' ' << total << '\n';
        (total >= k ? R : L) = M;
    }

    if (R > 3e5) R = -1;
    cout << R << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}