#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int ans = 0;
int r1 = 1e9, l2 = -1e9;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (r < r1) {
            r1 = r;
        }
        if (l > l2)
            l2 = l;
    }
    scanf("%d", &n);
    while (n--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l > r1)
            ans = max(ans, l - r1);
        if (r < l2)
            ans = max(ans, l2 - r);
    }
    printf("%d\n", ans);
    return 0;
}