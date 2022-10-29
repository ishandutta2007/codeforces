#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
char s[N];
int T;
vector<pair<int, int> > q[N];
int ans[N];
int f[N];
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
        a[i] = 1ll * a[i - 1] * i % mod;
    nia[n] = calc(a[n], mod - 2);
    for (int i = n - 1; i >= 2; i --)
        nia[i] = 1ll * nia[i + 1] * (i + 1) % mod;
}
int C(int x, int y) {
    if (x < y || y < 0) return 0;
    return 1ll * a[x] * nia[y] % mod * nia[x - y] % mod;
}
int main() {
    scanf("%d", &T);
    scanf("%s", s);
    pre(200000);
    int nows = strlen(s);
    int m = 0;
    while (T --) {
        int x;
        scanf("%d", &x);
        if (x == 1){
            scanf("%s", s);
            nows = strlen(s);
        } else {
            int y;
            scanf("%d", &y);
            ++m;
            q[nows].push_back({y, m});
        }
    }
    for (int i = 1; i <= 1e5; i ++)
        if (q[i].size()) {
            for (int j = 0; j < i; j ++) f[j] = 0;
            int v25 = 1;
            for (int j = i; j <= 1e5; j ++)
                f[j] = add(mul(f[j - 1], 26), mul(C(j - 1, i - 1), v25)), v25 = mul(v25, 25);
            for (auto u:q[i])
                ans[u.second] = f[u.first];
        }
    for (int i = 1; i <= m; i ++)
        printf("%d\n", ans[i]);
    return 0;
}