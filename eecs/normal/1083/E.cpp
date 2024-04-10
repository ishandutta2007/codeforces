#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000010;
int n, ql = 1, qr, q[maxn];
tuple<int, int, long long> a[maxn];
long long f[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %lld", &get<0>(a[i]), &get<1>(a[i]), &get<2>(a[i]));
    }
    sort(a + 1, a + n + 1);
    q[++qr] = 0;
    auto calc = [&](int i, int j) {
        return f[i] - 1LL * get<0>(a[i]) * get<1>(a[j]);
    };
    auto chk = [&](int i, int j, int k) {
        // (f[i] - f[j]) / (x[i] - x[j]) < (f[j] - f[k]) / (x[j] - x[k])
        return (long double)(f[i] - f[j]) / (get<0>(a[i]) - get<0>(a[j])) <
            (long double)(f[j] - f[k]) / (get<0>(a[j]) - get<0>(a[k]));
        // return (__int128)(f[i] - f[j]) * (get<0>(a[j]) - get<0>(a[k])) <
            // (__int128)(f[j] - f[k]) * (get<0>(a[i]) - get<0>(a[j]));
    };
    for (int i = 1; i <= n; i++) {
        while (ql < qr && calc(q[ql], i) < calc(q[ql + 1], i)) ql++;
        f[i] = calc(q[ql], i) + 1LL * get<0>(a[i]) * get<1>(a[i]) - get<2>(a[i]);
        while (ql < qr && chk(q[qr - 1], q[qr], i)) qr--;
        q[++qr] = i;
    }
    printf("%lld\n", *max_element(f + 1, f + n + 1));
    return 0;
}