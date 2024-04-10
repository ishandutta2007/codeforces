#include <algorithm>
#include <cstdio>
#include <vector>
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
vector<pair<int, int> > d;
int n, k;
int ans = 0;
int main() {
    scanf("%d %d", &n, &k);
    pre(n);
    for (int i = 1; i <= n;i ++) {
        int l, r;
        scanf("%d %d", &l, &r);
        d.push_back({l, 1});
        d.push_back({r + 1, -1});
    }
    sort(d.begin(), d.end());
    int cnt = 0;
    for (auto u:d) {
        if (u.second == 1)
            ans = add(ans, C(cnt, k - 1));
        cnt += u.second;
    }
    printf("%d\n", ans);
    return 0;
}