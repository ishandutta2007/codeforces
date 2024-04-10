#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, tot = 1, fa[maxn], L[maxn], R[maxn], son[maxn];
long long s;

int main() {
    scanf("%d %lld", &n, &s), s -= n;
    if (s < n - 1 || s > 1LL * (n - 1) * n / 2) puts("No"), exit(0);
    if (s == 1LL * (n - 1) * n / 2) {
        puts("Yes");
        for (int i = 2; i <= n; i++) {
            printf("%d ", i - 1);
        }
        exit(0);
    }
    auto calc = [&](int n, int k, long long _pw) {
        int num = n, cur = 1;
        long long mn = 0, pw = _pw;
        while (num) {
            int t = min(pw, (long long)num);
            num -= t, mn += 1LL * cur * t;
            pw *= k, cur++;
        }
        return mn;
    };
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        calc(n - 1, mid, mid) <= s ? r = (ans = mid) - 1 : l = mid + 1;
    }
    if (!~ans) puts("No"), exit(0);
    L[1] = R[1] = 1;
    for (int $ = 2; ; $++) {
        L[$] = R[$ - 1] + 1;
        l = L[$], r = n;
        while (l <= r) {
            int mid = (l + r) >> 1;
            long long v = 1LL * ($ - 1) * (n - L[$] + 1) + calc(n - mid, ans,
                1LL * (mid - L[$] + 1) * ans);
            if (v <= s) r = (R[$] = mid) - 1;
            else l = mid + 1;
        }
        s -= 1LL * ($ - 1) * (R[$] - L[$] + 1);
        for (int i = L[$], j = L[$ - 1]; i <= R[$]; i++) {
            if (son[j] == ans) j++;
            fa[i] = j, son[j]++;
        }
        if (R[$] == n) break;
    }
    puts("Yes");
    for (int i = 2; i <= n; i++) {
        printf("%d ", fa[i]);
    }
    return 0;
}