#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, ans, perm[3] = {0, 1, 2};
vector<pair<int, int>> V[3];

struct BIT {
    int c[maxn];
    void init() { memset(c, 0, sizeof(c)); }

    void add(int p, int v) {
        for (; p <= n; p += p & -p) c[p] += v;
    }
    int sum(int p) {
        int s = 0;
        for (; p; p -= p & -p) s += c[p];
        return s;
    }
} c1, c2;

int main() {
    scanf("%d", &n);
    vector<int> num;
    for (int i = 1, x, y, c; i <= n; i++) {
        scanf("%d %d %d", &x, &y, &c);
        V[c - 1].emplace_back(x, y), num.push_back(x);
    }
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    for (int c : {0, 1, 2}) {
        for (auto &p : V[c]) {
            p.first = lower_bound(num.begin(), num.end(), p.first) - num.begin() + 1;
        }
    }
    num.clear();
    for (int c : {0, 1, 2}) {
        for (auto &p : V[c]) num.push_back(p.second);
    }
    sort(num.begin(), num.end());
    num.resize(unique(num.begin(), num.end()) - num.begin());
    for (int c : {0, 1, 2}) {
        for (auto &p : V[c]) {
            p.second = lower_bound(num.begin(), num.end(), p.second) - num.begin() + 1;
        }
    }
    auto solve = [&]() {
        vector<array<int, 3>> all;
        for (int c : {0, 1, 2}) {
            for (auto &p : V[c]) all.push_back({p.first, p.second, c});
        }
        sort(all.begin(), all.end());
        c1.init(), c2.init();
        for (auto &p : V[perm[1]]) c1.add(p.second, 1);
        for (auto &p : V[perm[2]]) c2.add(p.second, 1);
        int c0 = 0;
        for (int i = 0, j; i < all.size(); i = j) {
            for (j = i; j < all.size() && all[i][0] == all[j][0]; j++) {
                if (all[j][2] == perm[1]) c1.add(all[j][1], -1);
                else if (all[j][2] == perm[2]) c2.add(all[j][1], -1);
                else c0++;
            }
            int l = 1, r = n, mx = 0, all = c2.sum(n);
            while (l <= r) {
                int mid = (l + r) / 2;
                int v1 = c1.sum(mid), v2 = all - c2.sum(mid);
                mx = max(mx, min(v1, v2));
                v1 <= v2 ? l = mid + 1 : r = mid - 1;
            }
            ans = max(ans, min(c0, mx));
        }
        reverse(all.begin(), all.end()), c0 = 0;
        c1.init(), c2.init();
        for (auto &p : V[perm[1]]) c1.add(p.second, 1);
        for (auto &p : V[perm[2]]) c2.add(p.second, 1);
        for (int i = 0, j; i < all.size(); i = j) {
            for (j = i; j < all.size() && all[i][0] == all[j][0]; j++) {
                if (all[j][2] == perm[1]) c1.add(all[j][1], -1);
                else if (all[j][2] == perm[2]) c2.add(all[j][1], -1);
                else c0++;
            }
            int l = 1, r = n, mx = 0, all = c2.sum(n);
            while (l <= r) {
                int mid = (l + r) / 2;
                int v1 = c1.sum(mid), v2 = all - c2.sum(mid);
                mx = max(mx, min(v1, v2));
                v1 <= v2 ? l = mid + 1 : r = mid - 1;
            }
            ans = max(ans, min(c0, mx));
        }
        reverse(all.begin(), all.end());
        int l = 1, r = n / 3;
        while (l <= r) {
            int mid = (l + r) / 2, cur = 0;
            bool flag = 1;
            for (int c : perm) {
                int x , cnt = 0;
                while (cnt < mid && cur < all.size()) {
                    x = all[cur][0], cnt += all[cur++][2] == c;
                }
                if (cnt < mid) { flag = 0; break; }
                while (cur < all.size() && all[cur][0] == x) cur++;
            }
            if (flag) ans = max(ans, mid), l = mid + 1;
            else r = mid - 1;
        }
    };
    do {
        solve();
        for (int c : {0, 1, 2}) {
            for (auto &p : V[c]) swap(p.first, p.second);
        }
        solve();
    } while (next_permutation(perm, perm + 3));
    printf("%d\n", 3 * ans);
    return 0;
}