#include <bits/stdc++.h>
using namespace std;
int n, m;
char a[55], b[55];

void rmain() {
    scanf("%d%d", &n, &m);
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    while (m > 1) {
        if (a[n] != b[m]) return puts("NO"), void();
        n--, m--;
    }
    for (int i = 1; i <= n; i++) if (a[i] == b[1]) return puts("YES"), void();
    puts("NO");
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) rmain();
}