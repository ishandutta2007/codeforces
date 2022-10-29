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
const int N = 2e6 + 10;
int n, m;
int inv[N];
int main() {
    scanf("%d %d", &n, &m);
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= max(n, m + 1);i ++)
        inv[i] = mul(inv[mod % i], (mod - mod / i));
    int ans = add(1, mul(n, inv[m + 1]));
    int ans1 = 0;
    for (int i = 1; i <= n; i ++)
        ans1 = add(ans1, inv[i]);
    printf("%d\n", mul(ans, add(mul(ans1, m), 1)));
    return 0;
}