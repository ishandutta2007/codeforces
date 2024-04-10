#include <algorithm>
#include <cstdio>
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
int T;
int n, p;
const int N = 1e6 + 10;
int a[N], g[N], v[N];
pair<int, long long> f[N], tmp;
void update(pair<int, long long>& a, int b) {
    if (a.first < b) {
        if (p != 1)
        while (a.second && a.first != b) {
            a.first++;
            a.second /= p;
        }
        a.first = b;
    } else {
        if (p != 1 && a.second)
        while (a.second <= 1e6 && a.first != b) {
            a.second *= p;
            a.first --;
        }
        a.first = b;
    }
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d %d", &n, &p);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        f[n] = {a[n], 1};
        v[n] = g[n] = calc(p, a[n]);
        for (int i = n - 1; i >= 1; i --) {
            f[i] = f[i + 1];
            update(f[i], a[i]);
            f[i].second ++;
            g[i] = add(g[i + 1], v[i] = calc(p, a[i]));
        }
        int ans = v[1];
        tmp = {a[1], 1};
        for (int i = 2; i <= n; i ++) {
            update(tmp, f[i].first);
            if (tmp.second > f[i].second) {
                ans = sub(ans, g[i]);
                break;
            } else {
                if (tmp.second) {
                    tmp.second--;
                    ans = sub(ans, v[i]);
                } else {
                    tmp.second ++;
                    ans = add(ans, v[i]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}