#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, d, x, a[maxn], b[maxn], pos[maxn], ans[maxn];
bitset<maxn> cur, tmp, ones;

int get() {
    x = (37LL * x + 10007) % 1000000007;
    return x;
}

int main() {
    scanf("%d %d %d", &n, &d, &x);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    for (int i = 0; i < n; i++) {
        swap(a[i], a[get() % (i + 1)]);
    }
    for (int i = 0; i < n; i++) {
        b[i] = i < d;
    }
    for (int i = 0; i < n; i++) {
        swap(b[i], b[get() % (i + 1)]);
    }
    for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
        if (b[i]) ones.set(i);
    }
    for (int i = 0; i < n; i++) {
        cur.set();
    }
    for (int i = n; i; i--) {
        int j = pos[i];
        tmp = cur & (ones << j);
        for (int k = tmp._Find_first(); k < n; k = tmp._Find_next(k)) ans[k] = i;
        cur ^= tmp;
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}