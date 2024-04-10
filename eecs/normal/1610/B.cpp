#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, a[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        auto del = [&](int x) {
            int l = 1, r = n;
            while (l <= r) {
                if (a[l] == a[r]) l++, r--;
                else if (a[l] == x) l++;
                else if (a[r] == x) r--;
                else return 0;
            }
            return 1;
        };
        int l = 1, r = n;
        while (l <= r && a[l] == a[r]) l++, r--;
        if (l > r) puts("YES");
        else if (del(a[l]) || del(a[r])) puts("YES");
        else puts("NO");
    }
    return 0;
}