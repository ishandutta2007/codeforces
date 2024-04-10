#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 998244353;
int n, a[maxn], t[maxn], cnt[maxn];
long long ans, tmp[20], r[20];

int main() {
    scanf("%d", &n);
    tmp[0] = r[0] = 1;
    for (int i = 1; i <= 19; i++) {
        tmp[i] = tmp[i - 1] * 10LL % P;
        r[i] = r[i - 1] * 10;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        while (a[i] >= r[t[i] + 1]) t[i]++;
        cnt[t[i]]++;
    }
    for (int i = 1; i <= n; i++) {
        vector<int> b;
        while (a[i]) {
            b.push_back(a[i] % 10), a[i] /= 10;
        }
        for (int i = 0; i < b.size(); i++) {
            int j = i + 1;
            for (int k = 0; k <= 10; k++) {
                if (k >= i) ans += b[i] * cnt[k] % P * (tmp[j * 2 - 1] + tmp[j * 2 - 2]);
                else ans += b[i] * cnt[k] % P * 2 * tmp[i + k + 1];
                ans %= P;
            }
        }
    }
    printf("%lld\n", ans % P);
    return 0;
}