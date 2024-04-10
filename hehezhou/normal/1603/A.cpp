#include <bits/stdc++.h>
using namespace std;
int t;
int n, a[100010];
inline void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; i++) {
        int tag = 0;
        for (int j = 2; j <= i + 1; j++) if (a[i] % j != 0) {
            tag = 1;
            break;
        }
        if (tag == 0) return puts("NO"), void();
    }
    puts("YES");
}
int main() {
    scanf("%d", &t);
    while (t--) rmain();
}