#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <deque>
#include <set>
#include <vector>
#include <unordered_map>
using namespace std;
const int mod = 1e9 + 7;
const int N = 4e6 + 1;
long long a[N];
long long f[N];
int n;
int main() {
    a[0] = 1;
    for (int i = 1; i < N ; i ++)
        a[i] = a[i - 1] * 2 % mod;
    scanf("%d", &n);
    for (int i = 1;  i<= n ; i ++) {
        int x;
        scanf("%d", &x);
        f[x ^ ((1 << 21) - 1)] ++;
    }
    for (int i = 0; i < 21; i ++)
        for (int j = 0; j < (1 << 21); j ++)
            if (j & (1 << i))
                f[j] += f[j ^ (1 << i)];
    long long ans = 0;
    for (int i = 0; i < (1 << 21);  i ++)
        (ans += a[f[(1 << 21) - 1 - i]] * (__builtin_popcount(i) & 1 ? mod - 1: 1)) %= mod;
    printf("%d\n", (int)ans);
    return 0;
}