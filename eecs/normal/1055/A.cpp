#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
int s, n, a[maxn], b[maxn];

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; i++) if (a[1] && a[i]) {
        if (i == s) puts("YES"), exit(0);
        if (b[i] && b[s] && i >= s) puts("YES"), exit(0);
    }
    puts("NO");
    return 0;
}