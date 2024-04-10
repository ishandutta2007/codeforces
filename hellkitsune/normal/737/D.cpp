#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 4005;
const int K = 92;
int INF;
typedef unsigned int U;

int n;
int a[N];
int sum[N], rsum[N];

const int MOD = 9999991;

int d[2][N][K][K];

int solve(int who, int from, int to, int k) {
    int &res = d[who][from][abs(from - to)][k];
    if (res != INF) {
        return res;
    }
    int ans, cnt = to - from;
    if (cnt < k) {
        ans = sum[from] - rsum[to];
    } else if (who == 0) {
        ans = solve(1, from + k, to, k);
        if (cnt > k) {
            ans = max(ans, solve(1, from + k + 1, to, k + 1));
        }
    } else {
        ans = solve(0, from, to - k, k);
        if (cnt > k) {
            ans = min(ans, solve(0, from, to - k - 1, k + 1));
        }
    }
    return res = ans;
}

int main() {
    memset(d, 63, sizeof d);
    INF = d[0][0][0][0];
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a + i);
    }
//    mt19937 mt(123);
//    n = 4000;
//    forn(i, n) {
//        a[i] = mt() % (200001) - 100000;
//    }
    sum[0] = 0;
    forn(i, n) {
        sum[i + 1] = sum[i] + a[i];
    }
    rsum[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
        rsum[i] = rsum[i + 1] + a[i];
    }
    printf("%d\n", solve(0, 0, n, 1));
    return 0;
}