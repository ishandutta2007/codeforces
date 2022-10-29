#include <algorithm>
#include <cstdio>
using namespace std;
const int mod = 5;
const int N = 510;
int a[N][N], b[N][N], c[N];
int ni[mod];
int n, m;
int st;
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
void gauss() {
    st = 1;
    for (int i = 1; i <= n; i ++) {
        for (int j = st; j <= m; j ++)
            if (a[j][i]) {
                for (int k = 1 ;k <= n; k ++)
                    swap(a[j][k], a[st][k]);
                for (int k = 1; k <= m; k ++)
                    swap(b[j][k], b[st][k]);
                break;
            }
        if (a[st][i]) {
            for (int j = st + 1; j <= m; j ++)
                if (a[j][i]) {
                    int v = mul(a[j][i], ni[a[st][i]]);
                    for (int k = 1; k <= n; k ++)
                        a[j][k] = sub(a[j][k], mul(v, a[st][k]));
                    for (int k = 1; k <= m; k ++)
                        b[j][k] = sub(b[j][k], mul(v, b[st][k]));
                }
            st++;
        }
    }
}
int main() {
    for (int i = 1; i < mod; i ++)
        ni[i] = calc(i, mod - 2);
    scanf("%d %d", &n, &m);
    for (int i= 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            char c;
            scanf(" %c", &c);
            a[j][i] = c- 'a';
        }
    for (int i = 1; i <= m; i ++)
        b[i][i] = 1;
    gauss();
    int ans = 1;
    for (int i = 1; i <= n - st + 1; i ++)
        ans = 1ll * ans * 5 % 1000000007;
    int q;
    scanf("%d", &q);
    while (q --) {
        bool sig = 1;
        for (int i = 1; i <= m; i ++) {
            char cc;
            scanf(" %c", &cc);
            c[i] = cc - 'a';
        }
        for (int i = st; i <= m; i ++) {
            int x = 0;
            for (int j = 1; j <= m; j ++)
                x = add(x, mul(b[i][j], c[j]));
            if (x) sig = 0;
        }
        if (!sig) puts("0");
        else
            printf("%d\n", ans);
    }
    return 0;
}