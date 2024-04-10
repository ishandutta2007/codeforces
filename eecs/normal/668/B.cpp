#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, q, a[maxn];

int main() {
    scanf("%d %d", &n, &q);
    int s1 = 0, s2 = 0, flag = 0;
    while (q--) {
        int op, x; scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
            (s1 += x) %= n, (s2 += x) %= n;
            if (abs(x) & 1) flag ^= 1;
        } else {
            if (!flag) ++s1 %= n, --s2 %= n;
            else --s1 %= n, ++s2 %= n;
            flag ^= 1;
        }
    }
    s1 = (s1 + n) % n, s2 = (s2 + n) % n;
    for (int i = 1; i <= n; i++) {
        if (i & 1) a[(i + s1 - 1 + n) % n + 1] = i;
        else a[(i + s2 - 1 + n) % n + 1] = i;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}