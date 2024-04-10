#include <bits/stdc++.h>

using namespace std;

int n, m, h, a[1010], tot;

int main() {
    scanf("%d %d %d", &n, &m, &h);
    for(int i=1; i<=m; i++) {
        scanf("%d", &a[i]);
        tot += a[i];
    }

    if(tot < n) {
        printf("-1\n");
        return 0;
    }

    a[h]--;
    n--;
    tot--;

    double chances = 1;
    for(int i=0; i<n; i++) {
        chances *= max(0.0, tot - i - a[h] + 0.0) / (tot - i);
    }

    printf("%.9f\n", 1 - chances);

    return 0;
}