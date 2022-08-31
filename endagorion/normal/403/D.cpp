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

const int maxn = 1010;
const int P = 1000000000 + 7;
int ways[maxn][maxn];
int CNK[maxn][maxn];
int fact[maxn];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    ways[0][0] = 1;
    for (int d = 0; d <= 1005; ++d) {
        for (int k = d; k >= 0; --k) {
            for (int i = 0; i <= 1005 - d; ++i) {
                ways[k + 1][i + d] += ways[k][i];
                ways[k + 1][i + d] %= P;
            }
        }
    }
    fact[0] = 1;
    forn(i, maxn - 1) {
        fact[i + 1] = (i64)(i + 1) * fact[i] % P;
    }
    CNK[0][0] = 1;
    for (int i = 1; i <= 1005; ++i) {
        CNK[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            CNK[i][j] = CNK[i - 1][j - 1] + CNK[i - 1][j];
            CNK[i][j] %= P;
        }
    }

    int T;
    scanf("%d", &T);
    forn(t, T) {
        int N, K;
        scanf("%d%d", &N, &K);
        int ans = 0;
        for (int m = K * (K - 1) / 2; m <= N; ++m) {
            ans += (i64)ways[K][m] * CNK[N - m][K] % P;
            ans %= P;
        }
        ans = (i64)ans * fact[K] % P;
        printf("%d\n", ans);
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}