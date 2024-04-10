#include <bits/stdc++.h>
using namespace std;
int a[100010], n, k;
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", a + i);
        int tag = 0;
        for (int i = 1; i <= n; i++) tag |= a[i] == k;
        if (tag == 0) {
            puts("no");
        }
        else {
            int tag = n == 1;
            for (int i = 1; i < n; i++) {
                if (a[i] >= k && a[i + 1] >= k) tag = 1;
            }
            for (int i = 1; i < n - 1; i++) {
                if (a[i] >= k && a[i + 2] >= k) tag = 1;
            }
            if (tag) puts("yes");
            else puts("no");
        }
    }
}