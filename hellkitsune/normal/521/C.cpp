#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
char s[100005];
int a[100000];
int f[100001], c[2][100001];

const int MOD = 1e9 + 7;

int binPow(int a, int p) {
    int res = 1;
    while (p) {
        if (p & 1) res = ((LL)res * a) % MOD;
        a = ((LL)a * a) % MOD;
        p >>= 1;
    }
    return res;
}

int C(int n, int k) {
    int di = ((LL)f[k] * f[n - k]) % MOD;
    return ((LL)f[n] * binPow(di, MOD - 2)) % MOD;
}

int main() {
    scanf("%d%d%s", &n, &k, s);
    REP(i, n) a[i] = s[n - 1 - i] - '0';
    f[0] = 1;
    for (int i = 1; i <= n; ++i)
        f[i] = ((LL)f[i - 1] * i) % MOD;
    REP(i, n + 1) if (i < k) c[0][i] = 0;
    else c[0][i] = C(i, k);
    REP(i, n + 1) if (i < k - 1) c[1][i] = 0;
    else c[1][i] = C(i, k - 1);
    int ans = ((LL)a[0] * c[0][n - 1]) % MOD, sum = 0, p10 = 1;
    for (int i = 1; i < n; ++i) {
        sum = (sum + (LL)p10 * c[1][n - 1 - i]) % MOD;
        ans = (ans + (LL)sum * a[i]) % MOD;
        p10 = ((LL)p10 * 10) % MOD;
        ans = (ans + (((LL)p10 * a[i]) % MOD) * c[0][n - 1 - i]) % MOD;
    }
    cout << ans << endl;
    return 0;
}