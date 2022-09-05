#include <bits/stdc++.h>
using namespace std;

int T, r, b, d;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &r, &b, &d);
        if (abs(r - b) <= 1LL * d * min(r, b)) puts("YES");
        else puts("NO");
    }
    return 0;
}