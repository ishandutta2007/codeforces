#include <bits/stdc++.h>
using namespace std;
int T, n;
int a[30010];
void rmain() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    int qwq = 0;
    for (int i = 2; i <= n; i++) {
        qwq += max(0, a[i] - a[i - 1]);
        if (qwq > a[i]) return void(puts("NO"));
    }
    puts("YES");
}
int main() {
    scanf("%d", &T);
    while (T--) rmain();
}