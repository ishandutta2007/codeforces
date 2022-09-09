#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 3;
int a[maxn]; 
LL bit[maxn];
void add(int x, LL y) {
    for (; x < maxn; x += x & -x) bit[x] += y;
}
LL sum(int x) {
    LL res = 0;
    for (; x; x -= x & -x) res += bit[x];
    return res;
}
set<int> s;
void erase(int x) {
    auto it = s.find(x);
    add(x, -(LL)(x - *prev(it)) * (x - *prev(it) + 1) / 2);
    add(*next(it), -(LL)(*next(it) - x) * (*next(it) - x + 1) / 2);
    add(*next(it), (LL)(*next(it) - *prev(it)) * (*next(it) - *prev(it) + 1) / 2);
    s.erase(it);
}
void insert(int x) {
    s.insert(x);
    auto it = s.find(x);
    add(x, (LL)(x - *prev(it)) * (x - *prev(it) + 1) / 2);
    add(*next(it), (LL)(*next(it) - x) * (*next(it) - x + 1) / 2);
    add(*next(it), -(LL)(*next(it) - *prev(it)) * (*next(it) - *prev(it) + 1) / 2);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i += 1) cin >> a[i];
    a[n + 2] = -1;
    s.insert(0);
    for (int i = 1, p = 0; i <= n + 1; i += 1) {
        if (a[i] > a[i + 1]) {
            s.insert(i);
            add(i, (LL)(i - p) * (i - p + 1) / 2);
            p = i;
        }
    }
    for (int i = 1, t; i <= q; i += 1) {
        cin >> t;
        if (t == 1) {
            int x, y;
            cin >> x >> y;
            if (a[x - 1] > a[x]) erase(x - 1);
            if (a[x] > a[x + 1]) erase(x);
            a[x] = y;
            if (a[x - 1] > a[x]) insert(x - 1);
            if (a[x] > a[x + 1]) insert(x);
        }
        else {
            int l, r;
            cin >> l >> r;
            LL res = sum(r) - sum(l - 1);
            auto it = s.lower_bound(l);
            if (*it >= r) {
                cout << (LL)(r - l + 1) * (r - l + 2) / 2 << "\n";
                continue;
            }
            res -= (LL)(*it - *prev(it)) * (*it - *prev(it) + 1) / 2;
            res += (LL)(*it - (l - 1)) * (*it - (l - 1) + 1) / 2;
            it = prev(s.upper_bound(r));
            res += (LL)(r - *it) * (r - *it + 1) / 2;
            cout << res << "\n";
        }
    }
    return 0;
}