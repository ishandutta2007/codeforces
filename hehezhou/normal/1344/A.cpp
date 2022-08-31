#include <bits/stdc++.h>
using namespace std;
int t, n, a[200010];
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
            a[i] = (a[i] + i) % n;
            a[i] = (a[i] + n) % n;
        }
        sort(a, a + n);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] != i) ans = 0;
        }
        puts(ans ? "YES" : "NO");
    }
}