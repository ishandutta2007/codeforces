#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, p[maxn], lb[maxn], rb[maxn];
long long a[maxn], ans[maxn];
bool ok[maxn];

int find1(int x) {
    return x == lb[x] ? x : lb[x] = find1(lb[x]);
}

int find2(int x) {
    return x == rb[x] ? x : rb[x] = find2(rb[x]);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]), lb[i] = rb[i] = i;
    }
    long long cur = 0;
    for (int i = n; i; i--) {
        ans[i] = cur, ok[p[i]] = 1;
        if (ok[p[i] - 1]) lb[p[i]] = p[i] - 1, rb[p[i] - 1] = p[i];
        if (ok[p[i] + 1]) rb[p[i]] = p[i] + 1, lb[p[i] + 1] = p[i];
        int l = find1(p[i]), r = find2(p[i]);
        cur = max(cur, a[r] - a[l - 1]);
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}