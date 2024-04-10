#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010, P = 1000000007;
int n, p, ans, a[maxn], fib[maxn];

int main() {
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= p; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % P;
    }
    for (int i = 1; i <= p; i++) {
        (fib[i] += fib[i - 1]) %= P;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        int sz = 32 - __builtin_clz(a[i]);
        if (sz > p) break;
        vector<int> V;
        for (int j = sz - 1; ~j; j--) {
            V.push_back(a[i] >> j & 1);
        }
        int x = a[i];
        bool flag = 0;
        while (x) {
            if (binary_search(a + 1, a + i, x)) { flag = 1; break; }
            if (V.back()) x /= 2, V.pop_back();
            else if (V.size() > 1 && !V[V.size() - 2]) x /= 4, V.pop_back(), V.pop_back();
            else break;
        }
        if (!flag) (ans += fib[p - sz]) %= P;
    }
    printf("%d\n", ans);
    return 0;
}