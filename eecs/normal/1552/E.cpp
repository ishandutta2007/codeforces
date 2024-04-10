#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int n, K, c[maxn], used[110], lst[110], l[maxn], r[maxn];

int main() {
    scanf("%d %d", &n, &K);
    for (int i = 1; i <= n * K; i++) {
        scanf("%d", &c[i]);
    }
    while (1) {
        memset(lst, 0, sizeof(lst));
        bool flag = 0;
        for (int i = 1; i <= n * K; i++) if (!used[c[i]]) {
            if (lst[c[i]]) {
                l[c[i]] = lst[c[i]], r[c[i]] = i;
                used[c[i]] = flag = 1;
                memset(lst, 0, sizeof(lst));
            } else {
                lst[c[i]] = i;
            }
        }
        if (!flag) break;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d %d\n", l[i], r[i]);
    }
    return 0;
}