#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 3e5 + 10;
int sum[N], a[N], d[N], mu[N], ni[N], sum1[N];
int n;
const int mod = 1e9 + 7;
int add(int x, int y) {
    x += y;
    return x >= mod ? x - mod :x;
}
int sub(int x, int y) {
    x -= y;
    return x < 0 ? x + mod :x;
}
int mul(int x, int y) {
    return 1ll * x * y % mod;
}
int C(int x, int y) {
    return (x < 0 || x < y) ?0 : mul(mul(a[x], ni[y]), ni[x - y]);
}
int calc(int x, int y) {
    int z =1;
    while (y) {
        if (y & 1) z = mul(z, x);
        x = mul(x, x), y >>= 1;
    }
    return z;
}
bool check(int x){
    int v = 0;
    for (int i = 1; i <= 300000; i ++)
        v = add(v, mul(C(sum1[i], x), mu[i]));
    return v;
}
int main() {
    mu[1] = 1;
    for (int i = 2; i < N ; i ++ ){
        if (!a[i]){
            d[a[i]= ++d[0]]= i, mu[i] = mod -1;
        }
        for (int j = 1; j <= a[i] && 1ll * i * d[j] < N; j ++){
            a[d[j] * i] = j;
            if (j !=a[i])
                mu[d[j] * i] = mod - mu[i];
        }
    }
    a[0] = 1;
    for (int i = 1; i < N ; i++)
        a[i] = mul(a[i - 1], i);
    ni[N - 1] = calc(a[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--)
        ni[i] = mul(ni[i +1], i + 1);
    scanf("%d", &n);
    int x = 0;
    for (int i = 1; i <= n; i ++){
        int y;
        scanf("%d", &y);
        if (sum[y]) {
            n --;
            i --;
            continue;
        }
        sum[y] = 1;
        x = __gcd(x, y);
    }
    if (x!= 1) {
        puts("-1");
        return 0;
    }
    if (sum[1]) {
        puts("1");
        return 0;
    }
    for (int i = 1; i <= 300000; i ++)
        if (sum[i])
            for (int j = 1; 1ll *j *j <= i; j ++)
                if (i %j == 0) {
                    sum1[j] ++;
                    if (1ll *j *j != i)
                        sum1[i / j] ++;
                }
    int l = 1, r = n, s = n, mid = 0;
    while (l <= r)
        if (check(mid = (l + r) / 2)) s = min(s, mid), r = mid -1;
        else l = mid +1;
    printf("%d\n", s);
    return 0;
}