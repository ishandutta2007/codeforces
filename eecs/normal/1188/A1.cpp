#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, d[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) {
        scanf("%d %d", &u, &v), d[u]++, d[v]++;
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] == 2) puts("NO"), exit(0);
    }
    puts("YES");
    return 0;
}