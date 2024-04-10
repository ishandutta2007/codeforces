#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int mod = 1e9 + 7;
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
vector<int>a, nia;
void pre(int n){
    a = vector<int>(n + 1, 1);
    nia = vector<int>(n + 1, 1);
    for (int i = 2; i <= n; i ++)
        a[i] = mul(a[i - 1] , i);
    nia[n] = calc(a[n], mod - 2);
    for (int i = n - 1; i >= 2; i --)
        nia[i] = mul(nia[i + 1] , (i + 1));
}
int C(int x, int y) {
    if (x < y || y < 0) return 0;
    return mul(mul(a[x], nia[y]), nia[x - y]);
}
int n;
int f[1000001];
int main (){
    scanf("%d", &n);
    pre(n);
    int ans = 1;
    for (int i = 1; i <= n; i ++)
        ans = mul(ans, i);
    for (int i = 1; i <= n; i ++)
        ans = sub(ans, C(n - 1, i - 1));
    printf("%d\n", ans);
    return 0;
}