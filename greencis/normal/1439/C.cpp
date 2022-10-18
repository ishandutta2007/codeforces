#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;

constexpr int SZ = 500;
int n, a[200200];
int tag[200200 / SZ + 5];
ll sum[200200];

inline void apply(int bi) {
    int tg = tag[bi];
    if (tg != -1) {
        tag[bi] = -1;
        const int upper = min(n, (bi + 1) * SZ);
        const int lower = bi * SZ;
        for (int i = upper - 1; i >= lower; --i) {
            if (a[i] >= tg) break;
            sum[bi] += tg - a[i];
            a[i] = tg;
        }
    }
}

inline ll get_sum(int bi) {
    if (tag[bi] != -1) {
        const int upper = min(n, (bi + 1) * SZ);
        const int lower = bi * SZ;
        return tag[bi] * ll(upper - lower);
    }
    return sum[bi];
}

inline int get_min(int bi) {
    if (tag[bi] != -1) return tag[bi];
    const int upper = min(n, (bi + 1) * SZ);
    return a[upper - 1];
}
inline int get_max(int bi) {
    if (tag[bi] != -1) return tag[bi];
    const int lower = bi * SZ;
    return a[lower];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tag[i / SZ] = -1;
        sum[i / SZ] += a[i];
    }
    const int BLOCKS = (n + SZ - 1) / SZ;

    while (q--) {
        int tp, x, y;
        cin >> tp >> x >> y;
        --x;
        if (tp == 1) {
            int bi = x / SZ;
            apply(bi);
            int lower = bi * SZ;
            for (int i = x; i >= lower; --i) {
                int nval = max(a[i], y);
                sum[bi] += nval - a[i];
                a[i] = nval;
            }
            for (; bi--; ) {
                if (get_max(bi) < y) {
                    tag[bi] = y;
                } else {
                    apply(bi);
                    int upper = min(n, (bi + 1) * SZ);
                    int lower = bi * SZ;
                    for (int i = upper - 1; i >= lower; --i) {
                        if (a[i] >= y) break;
                        sum[bi] += y - a[i];
                        a[i] = y;
                    }
                }
            }
        } else {
            int bi = x / SZ;
            apply(bi);
            int ans = 0;
            int upper = min(n, (bi + 1) * SZ);
            for (int i = x; i < upper; ++i) {
                if (a[i] <= y) {
                    y -= a[i];
                    ++ans;
                }
            }
            for (++bi; bi < BLOCKS; ++bi) {
                int upper = min(n, (bi + 1) * SZ);
                int lower = bi * SZ;
                ll cursum = get_sum(bi);
                if (cursum <= y) {
                    y -= cursum;
                    ans += upper - lower;
                } else if (get_min(bi) <= y) {
                    apply(bi);
                    for (int i = lower; i < upper; ++i) {
                        if (a[i] <= y) {
                            y -= a[i];
                            ++ans;
                        }
                    }
                }
            }
            cout << ans << '\n';
        }
    }
}