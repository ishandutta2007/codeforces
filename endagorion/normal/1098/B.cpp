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

const int maxn = 310000;
string f[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, n) cin >> f[i];
    string chars = "ACGT";

    string bchars;
    bool frows;
    vi to_flip;
    int bcost = 1e9;

    do {
        {
            vi flip_rows(n);
            int cost = 0;
            forn(i, n) {
                int dif0 = 0, dif1 = 0;
                forn(j, m) {
                    if (f[i][j] != chars[2 * (i & 1) + (j & 1)]) ++dif0;
                    if (f[i][j] != chars[2 * (i & 1) + ((j ^ 1) & 1)]) ++dif1;
                }
                cost += min(dif0, dif1);
                flip_rows[i] = dif0 < dif1 ? 0 : 1;
            }
            if (uin(bcost, cost)) {
                bchars = chars;
                frows = 1;
                to_flip = flip_rows;
            }
        }    
        {
            vi flip_cols(m);
            int cost = 0;
            forn(j, m) {
                int dif0 = 0, dif1 = 0;
                forn(i, n) {
                    if (f[i][j] != chars[2 * (i & 1) + (j & 1)]) ++dif0;
                    if (f[i][j] != chars[2 * ((i ^ 1) & 1) + (j & 1)]) ++dif1;
                }
                cost += min(dif0, dif1);
                flip_cols[j] = dif0 < dif1 ? 0 : 1;
            }
            if (uin(bcost, cost)) {
                bchars = chars;
                frows = 0;
                to_flip = flip_cols;
            }
        }    
    } while (next_permutation(all(chars)));

    if (frows) {
        forn(i, n) {
            forn(j, m) cout << bchars[2 * (i & 1) + ((j ^ to_flip[i]) & 1)];
            cout << '\n';
        }
    } else {
        forn(i, n) {
            forn(j, m) cout << bchars[2 * ((i ^ to_flip[j]) & 1) + (j & 1)];
            cout << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}