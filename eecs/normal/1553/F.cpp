#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 300010, SZ = 550;
int n, a[maxn];

struct BIT {
    ll s1[maxn], s2[maxn];

    void add(int p, int v) {
        for (int i = p; i < min(maxn, (p / SZ + 1) * SZ); i++) s1[i] += v;
        for (int i = p / SZ + 1; i <= maxn / SZ; i++) s2[i] += v;
    }

    ll query(int p) {
        return s1[p] + s2[p / SZ];
    }
} c1, c2;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        /* for (int j = 1; j <= i; j++) {
            ans += a[j] % a[i];
            if (j < i) ans += a[i] % a[j];
        } */
        ans += 1LL * a[i] * (c1.query(300000) - c1.query(a[i]));
        int _cnt = 0;
        long long _sum = 0;
        for (int j = 1, k; j <= a[i]; j = k + 1) {
            k = a[i] / (a[i] / j);
            int foo = c1.query(k);
            long long bar = c2.query(k);
            int cnt = foo - _cnt;
            long long sum = bar - _sum;
            _cnt = foo, _sum = bar;
            ans += 1LL * cnt * a[i] - sum * (a[i] / j);
        }
        c1.add(a[i], 1), c2.add(a[i], a[i]);
        for (int j = 0; j <= 300000; j += a[i]) {
            int cnt = c1.query(min(300000, j + a[i] - 1)) - c1.query(j - 1);
            long long sum = c2.query(min(300000, j + a[i] - 1)) - c2.query(j - 1);
            ans += sum - 1LL * j * cnt;
        }
        printf("%lld ", ans);
    }
    return 0;
}