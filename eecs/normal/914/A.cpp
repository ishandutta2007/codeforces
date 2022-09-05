#include <bits/stdc++.h>
using namespace std;

int n, ans = INT_MIN;

int main() {
    scanf("%d", &n);
    while (n--) {
        int a; scanf("%d", &a);
        if (a < 0) { ans = max(ans, a); continue; }
        int b = sqrt(a) - 1;
        while ((b + 1) * (b + 1) <= a) b++;
        if (a != b * b) ans = max(ans, a);
    }
    printf("%d\n", ans);
    return 0;
}