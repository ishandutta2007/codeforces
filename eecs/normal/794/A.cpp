#include <bits/stdc++.h>
using namespace std;

int a, b, c, n;

int main() {
    scanf("%d %d %d %d", &a, &b, &c, &n);
    int ans = 0;
    while (n--) {
        int x; scanf("%d", &x);
        if (x > b && x < c) ans++;
    }
    printf("%d\n", ans);
    return 0;
}