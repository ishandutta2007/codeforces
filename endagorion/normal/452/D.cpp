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

const int maxT = (int)2e7;

int u[3][maxT];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ios::sync_with_stdio(false);
    int K;
    int n[3], t[3];
    int sh[3];
    cin >> K;
    forn(i, 3) cin >> n[i];
    forn(i, 3) cin >> t[i];
    sh[0] = 1;
    sh[1] = 1 - t[0];
    sh[2] = 1 - t[0] - t[1];
    int c = 0;
    int ans = 0;
    forn(i, K) {
        int cc = c;
        ans = c;
//        cerr << c << '\n';
        forn(j, 3) {
            forn(z, t[j]) {
                ++u[j][cc];
                if (u[j][cc] == n[j]) {
                    c = max(c, cc + sh[j]);
                }
                ++cc;
            }
        }
    }
    cout << ans + t[0] + t[1] + t[2] << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}