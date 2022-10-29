#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int mod = 1e9  +7;
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

namespace C{
    const int mod = 1e9+7;
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
}
int h;
const int N = 500;
int f[N][N];
int main() {
    scanf("%d", &h);
    C::pre(h);
    f[1][0] = f[1][1] = 1;
    for (int i = 2; i <= h; i ++)
        for (int j = 0; j <= h; j ++)
            for (int k = 0; k <= j; k ++) {
                f[i][j] = add(f[i][j], mul(f[i - 1][j - k], f[i - 1][k]));
                f[i][j + 1] = add(f[i][j + 1], mul(f[i - 1][j - k], f[i - 1][k]));
                f[i][j] = add(f[i][j], mul(mul(mul(f[i - 1][j - k], f[i - 1][k]), 2), j));
                if (j) {
                    f[i][j - 1] = add(f[i][j - 1], mul(mul(mul(f[i - 1][j - k], f[i - 1][k]), 2), C::C(j, 2)));
                }
            }
    printf("%d\n", f[h][1]);
    return 0;
}