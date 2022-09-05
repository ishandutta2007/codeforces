#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, a[maxn], lst[maxn], nxt[maxn];
long long ans;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = n; i; i--) {
        nxt[i] = lst[a[i]], lst[a[i]] = i;
    }
    int pos = 1, cur = 1;
    for (int i = 1; i <= 100000; i++) if (lst[i]) {
        int j = lst[i];
        for (int k = lst[i]; k; k = nxt[k]) {
            if ((k - pos + n) % n < (j - pos + n) % n) j = k;
        }
        for (int k = j; k; pos = k, k = nxt[k]) {
            ans += k < pos ? ++cur : cur;
        }
        for (int k = lst[i]; j ^ k; pos = k, k = nxt[k]) {
            ans += k < pos ? ++cur : cur;
        }
    }
    printf("%lld\n", ans);
    return 0;
}