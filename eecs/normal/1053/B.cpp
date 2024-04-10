#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, b[maxn], cnt[2];
long long ans, a[maxn];
vector<int> st;

int main() {
    scanf("%d", &n);
    cnt[0]++;
    for (int i = 1, j = 0; i <= n; i++) {
        scanf("%lld", &a[i]);
        b[i] = __builtin_popcountll(a[i]);
        (j += b[i]) %= 2;
        ans += cnt[j]++;
    }
    for (int i = 1; i <= n; i++) {
        int s = 0, mx = 0;
        for (int j = i; j <= min(n, i + 100); j++) {
            s += b[j], mx = max(mx, b[j]);
            if (!(s & 1) && mx > s - mx) ans--;
        }
    }
    printf("%lld\n", ans);
    return 0;
}