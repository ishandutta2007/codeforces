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

int e[1500][1500];
string s[1500];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);
    int N, M, K, W;
    cin >> N >> M >> K >> W;
    forn(i, K) {
        forn(j, N) {
            string t;
            cin >> t;
            s[i] += t;
        }
    }
    forn(i, K) {
        forn(j, i) {
            forn(l, N * M) {
                if (s[i][l] != s[j][l]) {
                    e[i + 1][j + 1] += W;
                    e[j + 1][i + 1] += W;
                }
            }
        }
    }
    forn(i, K) {
        e[i + 1][0] = e[0][i + 1] = N * M;
    }

    vi d(K + 1, 1e9);
    vi vis(K + 1);
    vi from(K + 1, -1);
    d[0] = 0;
    vector<pii> ans;
    int cost = 0;
    while (true) {
        int m = -1;
        forn(i, K + 1) {
            if (vis[i]) continue;
            if (m == -1 || d[i] < d[m]) m = i;
        }
        if (m == -1) break;
        vis[m] = 1;
        cost += d[m];
        if (m > 0) {
            ans.pb(mp(m, from[m]));
        }
        forn(i, K + 1) {
            if (d[i] > e[m][i]) {
                d[i] = e[m][i];
                from[i] = m;
            }
        }
    }
    cout << cost << '\n';
    forn(i, ans.size()) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}