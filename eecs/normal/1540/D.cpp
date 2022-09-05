#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, SZ = 120;
int n, q, a[maxn], bel[maxn], bl[maxn], br[maxn];
vector<int> pos[maxn / SZ + 5];

namespace BIT {
int c[maxn];

void add(int p, int v) {
    for (; p <= n; p += p & -p) c[p] += v;
}

// min p s.t. c_p >= s
int find(int s) {
    int p = 1;
    for (int i = 1 << 16; i; i >>= 1) {
        if (p + i <= n && c[p + i - 1] < s) p += i, s -= c[p - 1];
    }
    return p;
}
}  // namespace BIT

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), a[i] = i - a[i];
    }
    for (int i = 1; i <= n; i++) {
        br[bel[i] = (i - 1) / SZ + 1] = i;
        if (!bl[bel[i]]) bl[bel[i]] = i;
    }
    auto rebuild = [&](int k) {
        for (int i = bl[k]; i <= br[k]; i++) {
            BIT::add(pos[k][i - bl[k]] = BIT::find(a[i]), 1);
        }
        for (int x : pos[k]) BIT::add(x, -1);
        sort(pos[k].begin(), pos[k].end());
    };
    for (int i = 1; i <= n; i++) {
        BIT::add(i, 1);
    }
    for (int i = 1; i <= bel[n]; i++) {
        pos[i].resize(br[i] - bl[i] + 1), rebuild(i);
    }
    scanf("%d", &q);
    while (q--) {
        int op, i, x;
        scanf("%d %d", &op, &i);
        if (op == 1) {
            scanf("%d", &x);
            a[i] = i - x, rebuild(bel[i]);
        } else {
            int cur = a[i];
            for (int j = i + 1; j <= br[bel[i]]; j++) {
                cur += a[j] <= cur;
            }
            for (int j = bel[i] + 1; j <= bel[n]; j++) {
                cur += upper_bound(pos[j].begin(), pos[j].end(), cur) - pos[j].begin();
            }
            printf("%d\n", cur);
        }
    }
    return 0;
}