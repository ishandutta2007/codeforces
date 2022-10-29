#include <algorithm>
#include <cstdio>
using namespace std;
const int mod = 998244353;
const int N = 2e5 + 10;
int n, m;
int a[N], ni[N];
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
int C(int x, int y) {
    if (x < 0 || y > x) return 0;
    return mul(mul(a[x], ni[y]), ni[x - y]);
}
int main() {
    scanf("%d %d", &n, &m);
    if (n == 2) {
        puts("0");
        return 0;
    }
    a[0] = 1;
    for (int i = 1; i <N; i ++)
        a[i] = mul(a[i - 1], i);
    ni[N - 1] = calc(a[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i --)
        ni[i] = mul(ni[i + 1], i + 1);
    printf("%d\n", mul(mul(C(m, n - 1), calc(2, n - 3)), C(n - 2, 1)));
    return 0;
}