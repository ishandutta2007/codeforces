#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 3e5 + 10;
int n;
int a[N];
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
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
        a[i] = add(a[i], a[i - 1]);
    int inv = calc(n, mod - 2);
    for (int i = 1; i <= n; i ++){
        int x = min(i, n - i);
        int r = n - i;
        int ans = 0;
        int id = 0;
        while (r) {
            ++id;
            int l = max(r - x, 0);
            ans = add(ans, mul(id, sub(a[r], a[l])));
            r = l;
        }
        printf("%d ", mul(ans, inv));
    }
    return 0;
}