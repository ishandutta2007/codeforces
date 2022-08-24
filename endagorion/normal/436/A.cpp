#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

vector<pii> a[2];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);

    int N, X;
    cin >> N >> X;

    forn(i, N) {
        int t, h, m;
        cin >> t >> h >> m;
        a[t].pb(mp(m, h));
    }

    forn(t, 2) sort(all(a[t]));
    int ans = 0;

    vi eaten[2];
    forn(t, 2) {
        forn(tt, 2) {
            eaten[tt].assign(a[tt].size(), 0);
        }
        int cur = t;
        int h = X;
        int res = 0;
        while (true) {
            int m = -1;
            forn(i, a[cur].size()) {
                if (!eaten[cur][i] && a[cur][i].second <= h) {
                    m = i;
                }
            }
            if (m == -1) break;
            else {
                eaten[cur][m] = 1;
                h += a[cur][m].first;
                cur ^= 1;
                ++res;
            }
        }
        ans = max(ans, res);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}