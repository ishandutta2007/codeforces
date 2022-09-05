#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, p[100010];
int m, ans;

int main() {
    scanf("%lld %d %lld", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%lld", &p[i]);
    }
    int i = 1;
    while (i <= m) {
        ll tmp = (p[i] - i + 1 + k - 1) / k;
        int lst = i;
        while (i < m && tmp == (p[i + 1] - lst + 1 + k - 1) / k) i++;
        ans++, i++;
    }
    printf("%d\n", ans);
    return 0;
}