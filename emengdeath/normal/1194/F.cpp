#include <ctime>
#include <cstdio>
#include <algorithm>
#include <ctime>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
const int mod = 1e9  +7;
const int N = 3e5 + 1;
int n;
long long T;
long long a[N+ 1], ni[N +1], t[N +1];
long long ans;
long long calc(long long x, long long y) {
    long long z = 1;
    while (y){
        if (y & 1) (z *= x) %= mod;
        (x *= x) %= mod,  y/= 2;
    }
    return z;
}
long long C(int x, int y) {
    if (x < 0 || y < 0|| x < y) return 0;
    return a[x] * ni[y] % mod * ni[x - y] % mod;
}
int main() {
    scanf("%d %lld", &n, &T);
    a[0] = 1;
    for (int i = 1; i <= N; i ++)
        a[i] = a[i - 1] * i % mod;
    ni[N] = calc(a[N], mod -2);
    for (int i = N - 1; i >= 0; i --)
        ni[i]= ni[i+1] *(i+1) %mod;
    for (int i = 1; i <= n ; i ++) {
        scanf("%lld", &t[i]);
        t[i] += t[i - 1];
    }
    t[n + 1] = T + 1;
    long long p = 1;
    int r = 0;
    long long v = 1;
    for (int i = 1; i <= n ; i ++ ){
        if (t[i] > T) break;
        p = (p * 2 + C(i -1, r + 1)) % mod;
        int rr = min(1ll * n, T - t[i]);
        ++r;
        while (r > rr) {
            p = (p - C(i, r) + mod) % mod;
            r --;
        }
        v = v * ni[2] % mod;
        ans = (ans + v * p) % mod;
    }
    cout<<ans<<endl;
    return 0;
}