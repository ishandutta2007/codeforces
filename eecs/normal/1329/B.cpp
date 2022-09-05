#include <bits/stdc++.h>
using namespace std;

int T, d, m;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &d, &m);
        int ans = 1;
        for (int i = 0; 1 << i <= d; i++) {
            ans = 1LL * ans * (min(1 << (i + 1), d + 1) - (1 << i) + 1) % m;
        }
        printf("%d\n", (ans - 1 + m) % m);
    }
    return 0;
}