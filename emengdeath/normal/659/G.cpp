#include <algorithm>
#include <cstdio>
using namespace std;
const int mod = 1e9 + 7;
int n;
int a[3000001];
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
int main() {
    scanf("%d", &n);
    int all = 0;
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        a[i] --;
        if (i >= 3) {
            all = mul(all, min(min(a[i], a[i - 1]), a[i - 2]));
        }
        int x = min(a[i], a[i - 1]);
        ans = add(add(add(ans, mul(all, x)), mul(x, x)), a[i]);
        all = add(all, x);
    }
    printf("%d\n", ans);
    return 0;
}