#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 998244353;
int n, a[maxn];
long long ans, tmp[20];

int main() {
    scanf("%d", &n);
    tmp[0] = 1;
    for (int i = 1; i <= 19; i++) {
        tmp[i] = tmp[i - 1] * 10LL % P;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        vector<int> b;
        while (a[i]) {
            b.push_back(a[i] % 10), a[i] /= 10;
        }
        for (int i = 0; i < b.size(); i++) {
            int j = i + 1;
            ans += 1LL * b[i] * n * (tmp[j * 2 - 2] + tmp[j * 2 - 1]);
            ans %= P;
        }
    }
    printf("%lld\n", ans % P);
    return 0;
}