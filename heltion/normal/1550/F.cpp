#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000;
int a[maxn + 1], mp[maxn + 1], ans[maxn + 1], d;
vector<pair<int, int>> vp[maxn + 1];
set<int> rm, added;
void add(int u, int k) {
        if (not rm.count(u)) return;
        rm.erase(u);
        added.insert(u);
        if (mp[u]) {
            {
                int L = u - d - k, R = u - d + k;
                while (true) {
                    auto it = rm.lower_bound(L);
                    if (it == rm.end() or *it > R) break;
                    add(*it, k);
                }
            }
            {
                int L = u + d - k, R = u + d + k;
                while (true) {
                    auto it = rm.lower_bound(L);
                    if (it == rm.end() or *it > R) break;
                    add(*it, k);
                }
            }
        }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, q, s;
    cin >> n >> q >> s >> d;
    for (int i = 1; i <= n; i += 1) {
        cin >> a[i];
        mp[a[i]] = i;
    }
    for (int i = 1; i <= q; i += 1) {
        int x, k;
        cin >> x >> k;
        if (x == s) ans[i] = 1;
        vp[k].push_back({x, i});
    }
    for (int i = 1; i <= maxn; i += 1) rm.insert(i);
    int b = maxn;
    for (int i = 1; i <= n; i += 1) {
        int x = abs(a[s] - a[i]);
        b = min(b, abs(x - d));
    }
    for (int k = b; k <= maxn; k += 1) {
        if (k == b) add(a[s], k);
        else {
            set<int> tmp;
            tmp.swap(added);
            for (int x : tmp) {
                add(x - 1, k);
                add(x + 1, k);
            }
        }
        for (auto [x, i] : vp[k])
            ans[i] = not rm.count(a[x]);
    }
    for (int i = 1; i <= q; i += 1) cout << (ans[i] ? "YES\n" : "NO\n");
    return 0;
}