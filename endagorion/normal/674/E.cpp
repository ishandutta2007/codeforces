#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
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

const int maxn = 510000;
const ld eps = 1e-15;
int p[maxn];
vector<ld> pr[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int v = 1;
    int Q;
    cin >> Q;
    pr[0].pb(1.0);
    forn(i, Q) {
        int t;
        cin >> t;
        if (t == 1) {
            int u;
            cin >> u;
            --u;
            int w = v;
            p[v] = u;
            pr[v].pb(0.0);
            ld newp = 1.0;
            int d = 0;
            for (; v; v = p[v]) {
                if (pr[p[v]].size() <= d + 1) pr[p[v]].resize(d + 2);
                ld oldq = pr[p[v]][d + 1], oldp = pr[v][d];
                pr[v][d] = newp;
                ld q = 1.0 - oldq;
                q /= 1.0 - 0.5 * oldp;
                q *= 1.0 - 0.5 * newp;
                q = 1.0 - q;
//                pr[p[v]][d + 1] = 1.0 - q;
                if (fabs(q - oldq) < eps) break;
                newp = q;
                ++d;
            }
            if (pr[v].size() <= d) pr[v].resize(d + 1);
            pr[v][d] = newp;
            v = ++w;
        } else {
            int u;
            cin >> u;
            --u;
            cout << accumulate(all(pr[u]), (ld)0.0) - 1.0 << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}