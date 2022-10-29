#include <iostream>
#include <algorithm>
#include <bitset>
const int K = 21, LEN = 1<<K;
int pos[K], l[LEN], r[LEN], mask[LEN];

void swap(std::bitset<K> &a, int x, int y) {
    int tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
}

int main() {
    int n, m, k;
    std::bitset<K> s, t;
    std::cin >> n >> m >> k >> s >> t;
    for (int i = 1; i <= k; ++i)
        pos[i] = i;
    int len = 1 << k;
    std::fill(l, l + len, n);
    for (int i = 1; i <= n; ++i) {
        if (l[s.to_ulong()] == n)
            l[s.to_ulong()] = i - 1;
        int a, b; scanf("%d%d", &a, &b);
        std::swap(pos[a], pos[b]);
        swap(s, k - pos[a], k - pos[b]);
        swap(t, k - pos[a], k - pos[b]);
        r[t.to_ulong()] = i;
        // std::cout << s << ' ' << t << std::endl;
    }
    for (int i = 0; i < k; ++i)
        for (int j = 0; j < len; ++j)
            if (~j >> i & 1) {
                l[j] = std::min(l[j], l[j ^ 1 << i]);
                r[j] = std::max(r[j], r[j ^ 1 << i]);
            }
    for (int i = 0; i < len; ++i)
        mask[i] = i;
    std::sort(mask, mask + len, [](int x, int y){
        return __builtin_popcount(x) > __builtin_popcount(y);
    });
    for (int i = 0; i < len; ++i)
        if (r[mask[i]] - l[mask[i]] >= m) {
            std::cout << __builtin_popcount(mask[i]) * 2 + k - s.count() - t.count() << std::endl << l[mask[i]] + 1 << ' ' << r[mask[i]] << std::endl;
            break;
        }
}