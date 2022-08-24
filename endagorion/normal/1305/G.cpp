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

const int maxn = 1 << 18;
int p[maxn], a[maxn];
int dp[maxn][2];

int root(int v) {
    return v == p[v] ? v : (p[v] = root(p[v]));
}

template<class T>
void intro(T l, int i) {
    if (i == -1) return;
    int p = root(i);
    forn(z, 2) {
        if (l[z] == -1) {
            l[z] = i;
            break;
        }
        if (root(l[z]) == p) {
            if (a[i] > a[l[z]]) l[z] = i;
            break;
        } else {
            if (a[i] > a[l[z]]) swap(l[z], i), p = root(i);
        }
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

    int n;
    cin >> n;
    forn(i, n) cin >> a[i];
    a[n] = 0;
    ++n;
    forn(i, n) p[i] = i;
    i64 ans = 0;
    forn(k, 20) {
        forn(j, maxn) forn(z, 2) dp[j][z] = -1;
        forn(i, n) intro(dp[a[i]], i);
        forn(j, 18) forn(i, maxn) if (!((i >> j) & 1)) forn(z, 2) intro(dp[i + (1 << j)], dp[i][z]);
        vector<pii> best(n, {-1, -1});
        forn(i, n) {
            int x = a[i] ^ (maxn - 1);
            forn(z, 2) {
                int y = dp[x][z];
                if (y != -1 && root(y) != root(i)) {
                    int p = root(i);
                    uax(best[p], {a[i] + a[y], y});
                }
            }
        }
        forn(i, n) {
            int y = best[i].se;
            if (y == -1 || root(y) == root(i)) continue;
            ans += best[i].fi;
            p[i] = root(y);
        }
    }
    forn(i, n) ans -= a[i];
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}