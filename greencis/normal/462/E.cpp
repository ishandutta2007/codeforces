//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int MAXN = 100'005;
int t[MAXN];
int a[MAXN];
int n;

inline void add(int x, int val) {
    for (; x < n; x |= x + 1)
        t[x] += val;
}

inline int get(int x) {
    int ans = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
        ans += t[x];
    return ans;
}

inline int get(int L, int R) {
    return get(R) - get(L - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> n >> q;
    fill_n(a, n, 1);
    for (int i = 0; i < n; ++i) add(i, 1);
    int wl = 0, wr = n - 1;
    while (q--) {
        int tp, x, y;
        cin >> tp >> x;
        if (tp == 1) {
            if (wl <= wr) {
                int len = wr - wl + 1;
                if (2 * x <= len) {
                    for (int i = 0; i < x; ++i) {
                        int addon = a[wl + i];
                        a[wl + 2 * x - 1 - i] += addon;
                        add(wl + 2 * x - 1 - i, addon);
                    }
                    wl += x;
                } else {
                    x = len - x;
                    for (int i = 0; i < x; ++i) {
                        int addon = a[wr - i];
                        a[wr - 2 * x + 1 + i] += addon;
                        add(wr - 2 * x + 1 + i, addon);
                    }
                    wr -= x;
                    swap(wl, wr);
                }
            } else {
                int len = wl - wr + 1;
                if (2 * x <= len) {
                    for (int i = 0; i < x; ++i) {
                        int addon = a[wl - i];
                        a[wl - 2 * x + 1 + i] += addon;
                        add(wl - 2 * x + 1 + i, addon);
                    }
                    wl -= x;
                } else {
                    x = len - x;
                    for (int i = 0; i < x; ++i) {
                        int addon = a[wr + i];
                        a[wr + 2 * x - 1 - i] += addon;
                        add(wr + 2 * x - 1 - i, addon);
                    }
                    wr += x;
                    swap(wl, wr);
                }
            }
        } else {
            cin >> y;
            --y;
            int ans;
            if (wl <= wr)
                ans = get(wl + x, wl + y);
            else
                ans = get(wl - y, wl - x);
            cout << ans << '\n';
        }
    }
}