#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn], cnt[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (mx < a[i]) printf("%d\n", i), exit(0);
        if (a[i] > n) break;
        cnt[a[i]]++;
        while (cnt[mx]) mx++;
    }
    puts("-1");
    return 0;
}