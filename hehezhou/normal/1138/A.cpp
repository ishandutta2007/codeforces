#include <bits/stdc++.h>
using namespace std;
int a[100010], n, last;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i);
    last = 0;
    int ans = 0;
    for(int l = 1, r; l <= n; l = r + 1) {
        for(r = l; r < n && a[r + 1] == a[l]; r++);
        ans = max(ans, min(last, r - l + 1));
        last = r - l + 1;
    }
    return cout << ans * 2 << endl, 0;
}