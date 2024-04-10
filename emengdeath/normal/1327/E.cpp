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
int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i ++) {
        int ans = 0;
        ans = mul(mul(mul(10, 9), calc(10, (n - i) - 1)), 2);
        if (i != n - 1) {
            ans = add(ans, mul(mul(mul(10, mul(9, 9)), calc(10, (n - i) - 2)), n - i - 1));
        }
        printf("%d ", ans);
    }
    printf("%d\n", 10);
    return 0;
}