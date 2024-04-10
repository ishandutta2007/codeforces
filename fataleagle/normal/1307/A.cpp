#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, d;
        scanf("%d%d", &n, &d);
        int a[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        for (int i = 1; i < n; i++) {
            int x = min(a[i], d / i);
            a[0] += x;
            d -= x * i;
        }
        printf("%d\n", a[0]);
    }
    return 0;
}