#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, ans, a[maxn], l[maxn], r[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        l[i] = l[i - 1] + (a[i] == 1);
    }
    for (int i = n; i; i--) {
        r[i] = r[i + 1] + (a[i] == 2);
    }
    for (int i = 1; i <= n; i++) {
        int mn = INT_MAX;
        for (int j = i; j <= n; j++) {
            mn = min(mn, l[j] + r[j]);
            ans = max(ans, l[i - 1] + l[j] + r[i] + r[j + 1] - mn);
        }
    }
    printf("%d\n", ++ans);
    return 0;
}