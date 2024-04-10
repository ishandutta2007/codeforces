#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
int calc(int x, int y, int m) {
    int z = 1;
    while (y){
        if (y & 1) z =1ll * z * x% m;
        x = 1ll *x * x%m, y /= 2;
    }
    return z;
}
const int N = 1e5 + 10;
int n, m, q;
vector<int> p;
int a[N];
int getphi(int x) {
    int tmp = 1;
    for (int i = 2; 1ll * i * i <= x; i ++)
        if (x % i == 0) {
            tmp *= (i - 1);
            x /= i;
            while (x % i == 0) x /= i, tmp *= i;
        }
    if (x != 1)
        tmp *= x - 1;
    return tmp;
}
int main() {
    scanf("%d %d", &n, &m);
    while (m != 1) {
        p.push_back(m);
        m = getphi(m);
    }
    p.push_back(1);
    for (int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    while (m --) {
        int l, r;
        scanf("%d %d", &l, &r);
        int len = min(r - l + 1, (int)p.size());
        int v = 0;
        if (p.size() < r - l + 1) v = 1;
        else {
            if (p[r - l] <= a[r]) v = a[r] % p[r - l] + p[r - l];
            else
                v = a[r] % p[r - l];
        }
        for (int i = len - 2; i >= 0; i --) {
            int sig = 0;
            long long y = 1;
            if (a[l + i] != 1)
            for (int j = 1; j <= v; j ++)
                if ((y *= a[l + i]) >= p[i]) {
                    sig = p[i];
                    break;
                }
            v = calc(a[l + i], v, p[i]) + sig;
        }
        printf("%d\n", v % p[0]);
    }
    return 0;
}