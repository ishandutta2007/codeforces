#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, tim, a[maxn], vis[maxn], sg[maxn], ord[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    iota(ord + 1, ord + n + 1, 1);
    sort(ord + 1, ord + n + 1, [&](int x, int y) { return a[x] > a[y]; });
    for (int $ = 1; $ <= n; $++) {
        int i = ord[$];
        tim++;
        for (int j = i - a[i]; j >= 1; j -= a[i]) {
            if (a[j] > a[i]) vis[sg[j]] = tim;
        }
        for (int j = i + a[i]; j <= n; j += a[i]) {
            if (a[j] > a[i]) vis[sg[j]] = tim;
        }
        while (vis[sg[i]] == tim) sg[i]++;
    }
    for (int i = 1; i <= n; i++) {
        putchar(sg[i] ? 'A' : 'B');
    }
    return 0;
}