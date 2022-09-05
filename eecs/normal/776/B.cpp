#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, tot, ans[maxn], mark[maxn];
bool pr[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n + 1; i++) if (!pr[i]) {
        ans[i] = 1;
        for (int j = i + i; j <= n + 1; j += i) pr[j] = 1;
    }
    printf("%d\n", n <= 2 ? 1 : 2);
    for (int i = 2; i <= n + 1; i++) {
        if (!ans[i]) ans[i] = 2;
        printf("%d ", ans[i]);
    }
    return 0;
}