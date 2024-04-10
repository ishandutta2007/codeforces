#include <algorithm>
#include <cstdio>
using namespace std;
const int mod = 998244353;
int add(int x, int y) {
    x+= y;
    return x >= mod ?x - mod : x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x +mod : x;
}
int mul(int x, int y){
    return 1ll * x * y % mod;
}
int calc(int x, int y) {
    int z = 1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
int n;
int f[1000000], sum[2];
int main() {
    scanf("%d", &n);
    f[0] = 1;
    for (int i = 1; i <= n; i ++) {
        sum[!(i&1)] = add( sum[!(i&1)], f[i - 1]);
        f[i] = sum[!(i & 1)];
    }
    printf("%d\n", mul(f[n], calc(calc(2, n), mod - 2)));
    return 0;
}