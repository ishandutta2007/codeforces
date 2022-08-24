#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define LL long long

using namespace std;

int gcd(int x, int y){
    while (y > 0){
        x %= y;
        swap(x, y);
    }
    return x;
}

int main()
{

    int base = 1000000007;
    vector<LL> a(1000001), b(1000001), c(1000001), f(1000001), g(1000001), h(1000001);
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < 1000001; i++){
        a[i] = (1ll * i * i + 1ll * (i - 2) * (i - 2) + a[i - 2]) % base;
    }
    for (int i = 0; i < 1000001; i++){
        b[i] = ((a[i] * i) % base);
        c[i] = ((b[i] * i) % base);
    }
    for (int i = 1; i < 1000001; i++){
        a[i] = (a[i] + a[i - 1]) % base;
        b[i] = (b[i] + b[i - 1]) % base;
        c[i] = (c[i] + c[i - 1]) % base;
    }

    f[1] = 1;
    for (int i = 2; i < 1000001; i++){
        int j = 2;
        while (j * j <= i && i % j > 0) j++;
        if (j * j > i){
            f[i] = i + i - 1;
        } else {
            LL v, w = 1;
            int cc = 0;
            int ii = i;
            while (ii % j == 0){
                v = w;
                w = (w * j) % base;
                ii /= j;
                cc++;
            }
            v = (v * (j * (cc + 1) - cc)) % base;
            f[i] = (v * f[ii]) % base;
        }
    }
    for (int i = 1; i < 1000001; i++){
        g[i] = (f[i] * i) % base;
        h[i] = (g[i] * i) % base;
    }
    for (int i = 2; i < 1000001; i++){
        f[i] = (f[i] + f[i - 1]) % base;
        g[i] = (g[i] + g[i - 1]) % base;
        h[i] = (h[i] + h[i - 1]) % base;
    }
    LL qw[20];
    for (int i = 1; i < 20; i++){
        LL qq = 1;
        while (qq % i > 0) qq += base;
        qw[i] = qq / i;
    }
    vector<LL> d[6];
    for (int i = 0; i < 6; i++) d[i].resize(1000001);
    for (int i = 0; i < 1000001; i++){
        d[0][i] = 1;
        for (int j = 1; j < 6; j++) d[j][i] = (d[j - 1][i] * i) % base;
    }
    for (int i = 1; i < 1000001; i++){
        for (int j = 0; j < 6; j++){
            d[j][i] = (d[j][i - 1] + d[j][i]) % base;
        }
    }

    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        if (n > m) swap(n, m);
        LL ans = 0;
        LL v;
        v = 1ll * (n + 1) * (m + 1);
        v %= base;
        v = (v * a[n]) % base;
        ans += v;
        v = (n + m + 2);
        v = (v * b[n]) % base;
        ans = (ans + base - v) % base;
        ans = (ans + c[n]) % base;
        ans = (ans + d[5][n] * qw[3]) % base;
        v = n + m + 2;
        v = (v * qw[3]) % base;
        v = (v + 2) % base;
        v = (v * d[4][n]) % base;
        ans = (ans + base - v) % base;
        v = (n + 1);
        v = (v * (m + 1)) % base;
        v = (v * qw[3]) % base;
        v = (v + 2 * n + 2 * m + 4) % base;
        v = (v + base - qw[3]) % base;
        v = (v * d[3][n]) % base;
        ans += v;
        v = qw[3] * (n + m + 2);
        v %= base;
        LL w = (n + 1);
        w *= (m + 1);
        w %= base;
        w = (w * 2) % base;
        v = (v + base - w) % base;
        ans = (ans + d[2][n] * v) % base;
        v = (n + 1);
        v = (v * (m + 1)) % base;
        v = (v * qw[3]) % base;
        v = (v * d[1][n]) % base;
        ans = (ans + base - v) % base;
        v = 1ll * (n + 1) * (m + 1) * 2;
        v %= base;
        ans = (ans + v * f[n]) % base;
        v = (n + m + 2) * 2;
        v %= base;
        v = (v * g[n]) % base;
        ans = (ans + base - v) % base;
        ans = (ans + h[n] * 2) % base;
        cout << ans << "\n";
    }

    return 0;
}