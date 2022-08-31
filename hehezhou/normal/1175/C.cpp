#include <bits/stdc++.h>
using namespace std;
int t, n, k;
int a[200010];
int ans, ansi;
int main() {
    cin >> t;
    while(t--) {
        ans = 2e9;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) scanf("%d", a + i);
        for(int i = 1; i <= n - k; i++) {
            if(a[i + k] - a[i] < ans) ans = a[i + k] - a[i], ansi = (a[i + k] + a[i]) / 2;
        }
        printf("%d\n", ansi);
    }
    return 0;
}