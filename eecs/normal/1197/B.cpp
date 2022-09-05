#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, a[maxn];
bool pre[maxn], suf[maxn];

int main() {
    scanf("%d", &n);
    pre[1] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (i > 1) pre[i] = pre[i - 1] & (a[i] > a[i - 1]);
    }
    suf[n] = 1;
    for (int i = n - 1; i; i--) {
        suf[i] = suf[i + 1] & (a[i] > a[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        if (pre[i] & suf[i]) printf("YES\n"), exit(0);
    }
    printf("NO\n");
    return 0;
}