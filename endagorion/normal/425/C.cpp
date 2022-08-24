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

const int maxn = 100001;
const int maxq = 100001;
const int maxl = 400;

int dp[maxl][maxn];
int a[maxn];
vi b[maxq];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M, S, E;
    scanf("%d%d%d%d", &N, &M, &S, &E);
    forn(i, N) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }
    forn(i, M) {
        int x;
        scanf("%d", &x);
        b[x].pb(i);
    }

    int ans = 0;
    forn(i, N) {
        dp[1][i] = b[a[i]].empty() ? 1e9 : b[a[i]][0];
        if (E + i + dp[1][i] + 2 <= S) {
            ans = 1;
        }
    }

    for (int j = 2; j <= S / E; ++j) {
        int minI = 1e9;
        forn(i, N) {
            vi::const_iterator it = upper_bound(all(b[a[i]]), minI);
            if (it == b[a[i]].end()) {
                dp[j][i] = 1e9;
            } else {
                dp[j][i] = *it;
            }
            if (j * E + i + 1 + dp[j][i] + 1 <= S) {
                ans = j;
            }
            minI = min(minI, dp[j - 1][i]);
        }
    }
    cout << ans << '\n';


#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}