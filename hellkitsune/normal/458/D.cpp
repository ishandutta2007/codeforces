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
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
long double f[100001];

int main() {
    f[0] = 0;
    for (int i = 1; i <= 100000; ++i) f[i] = f[i - 1] + log(i);
    scanf("%d%d%d", &n, &m, &k);
    long double ans = 0;
    REP(i, n + 1) REP(j, n + 1) {
        int cnt = (i + j) * n - i * j;
        if (cnt > k) continue;
        long double cur = f[n] - f[i] - f[n - i] + f[n] - f[j] - f[n - j];
        cur -= f[m] - f[k];
        cur += f[m - cnt] - f[k - cnt];
        if (cur > 400) {
            printf("1e99\n");
            return 0;
        }
        ans += exp(cur);
    }
    if (ans > 1e99) {
        printf("1e99\n");
    } else {
        printf("%.12f\n", (double)ans);
    }
    return 0;
}