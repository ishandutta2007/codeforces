#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string.h>
#include <assert.h>
using namespace std;

int f[1000];
int seen[1000];

int n;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

long long lcm(long long a, long long b) {
    long long g = gcd(a,b);
    return b*(a/g);
}

int mm = 0;
long long ll = 1;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) scanf("%d", &f[i]);

    for (int i = 1; i <= n; i++) {
        memset(seen,0,sizeof(seen));
        seen[i] = 1;

        int cur = f[i];
        int cnt = 2;
        while (!seen[cur]) {
            seen[cur] = cnt;
            cur = f[cur];
            cnt++;
        }

        int cyc = cnt - seen[cur];
        int anti = seen[cur] - 1;

        mm = max(mm, anti);
        ll = lcm(ll, cyc);
    }

    long long ans = mm + ( (ll-(mm%ll))%ll);
    if (ans == 0) ans = ll;
    printf("%lld\n", ans);
}