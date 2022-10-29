#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
using namespace std;
const int N = 1e6;
const int mod =  1e9 +7;
int n;
long long ans, ans0, ans00[N], all1[N];
int l[N], r[N];
long long calc(long long x ,long long y) {
    long long z = 1;
    x %= mod;
    while (y) {
        if (y & 1) (z *= x ) %= mod;
        (x *= x )%= mod, y /= 2;
    }
    return z;
}
long long ni(long long x) {
    return calc(x, mod - 2);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
        scanf("%d", &l[i]);
    for (int i = 1; i <= n ; i ++) {
        scanf("%d", &r[i]);
    }
    long long all = r[1] - l[1] + 1 ;
    ans = r[1] - l[1] + 1;
    ans0= r[1] - l[1] + 1;
    ans00[1] = ans0;
    all1[1] = all;
    all1[0] = 1;
    for (int i = 2; i <= n; i ++) {
        all = (long long) all * (r[i] - l[i] + 1) % mod;
        all1[i] = all;
        long long x = ((long long)(r[i] - l[i] + 1) * (r[i  - 1] - l[i - 1] + 1) % mod  - max(min(r[i], r[i - 1]) - max(l[i], l[i - 1]) + 1, 0) + mod) % mod;

        ans0 = ans0 * (r[i] - l[i] + 1) % mod + (long long)x * all % mod * ni(r[i] - l[i] + 1) % mod * ni(r[i - 1] - l[i - 1] + 1) % mod;
        ans0 %= mod;
        ans00[i] = ans0;
        ans = ans * (r[i] - l[i] + 1) % mod  - (long long)all * ni(r[i] - l[i] +1) % mod * ni(r[i - 1] - l[i - 1] + 1) % mod * x % mod + mod;
        ans %= mod;
        int L = max(l[i], l[i - 1]), R = min(r[i], r[i - 1]);
        if (i == 2) {
            ans += 4 * ((long long)(r[i] - l[i] + 1) * (r[i - 1] - l[i - 1] + 1) % mod - max(R - L + 1, 0) + mod) %mod;
        } else {
            long long v =ans00[i - 2] * max(R - L + 1, 0) % mod + all1[i - 3] * ((long long) max(R - L + 1, 0) * (r[i - 2] - l[i - 2] + 1) % mod - max(min(R, r[i - 2]) - max(L, l[i - 2]) + 1, 0) + mod) % mod;
            ans += 2 * (ans0 - v % mod + mod) % mod;

        }
        ans %= mod;
    }
    ans = ((long long)ans * ni(all) % mod + mod ) % mod;
    printf("%d\n", (int)ans);
    return 0;
}