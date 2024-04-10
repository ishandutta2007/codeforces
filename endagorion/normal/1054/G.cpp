#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

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

const int maxn = 2011, maxm = 2011;
typedef bitset<maxm> bs;
bs b[maxn];
char buf[maxm];
int dist[maxn][maxn];
pii me[maxn];
int used[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        forn(i, n) forn(j, maxm) b[i][j] = 0;
        vi cnt(m);
        forn(i, m) {
            scanf("%s", buf);
            forn(j, n) if (buf[j] == '1') b[j].set(i), ++cnt[i];
        }
        forn(i, n) forn(j, n) {
            dist[i][j] = (b[i] & b[j]).count();
        }

        forn(i, n) me[i] = {-1e9, -1}, used[i] = 0;
        int Z = 0;
        vector<pii> e;
        forn(i, n) {
            int v = -1;
            forn(j, n) {
                if (used[j]) continue;
                if (v == -1 || me[j] > me[v]) v = j;
            }
            used[v] = 1;
            if (me[v].se != -1) e.pb({v, me[v].se});
            forn(j, n) uax(me[j], mp(dist[v][j], v));
        }

        bool ok = true;
        forn(j, m) {
            int z = 0;
            for (auto w: e) if (b[w.fi][j] && b[w.se][j]) ++z;
            ok &= z == cnt[j] - 1;
        }
        if (ok) {
            cout << "YES\n";
            for (auto w: e) cout << w.fi + 1 << ' ' << w.se + 1 << '\n';
        } else cout << "NO\n";
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}