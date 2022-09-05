#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> BST;
const int maxn = 100010;
int n, m, a[maxn];
BST id[300];
map<int, BST> mp;
set<pair<int, int>> sz;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), mp[a[i]].insert(i);
    }
    auto ins = [&](BST &S, int type) {
        auto it = S.begin();
        for (int k = 0; k < 30 && it != S.end(); k++, it++) {
            type ? (void)id[k].insert(*it) : (void)id[k].erase(*it);
        }
    };
    for (auto &p : mp) {
        ins(p.second, 1), sz.emplace(p.second.size(), p.first);
    }
    scanf("%d", &m);
    while (m--) {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 1) {
            ins(mp[a[y]], 0), sz.erase({mp[a[y]].size(), a[y]});
            mp[a[y]].erase(y), ins(mp[a[y]], 1), sz.emplace(mp[a[y]].size(), a[y]);
            a[y] = x, ins(mp[x], 0), sz.erase({mp[x].size(), x});
            mp[x].insert(y), ins(mp[x], 1), sz.emplace(mp[x].size(), x);
        } else {
            if (x == 1) { printf("%d\n", a[y]); continue; }
            int rk = mp[a[y]].order_of_key(y);
            if (!(x % 2)) { printf("%d\n", rk + 1); continue; }
            if (rk < 30) { printf("%d\n", id[rk].order_of_key(y) + 1); continue; }
            int ans = 0;
            for (auto it = sz.rbegin(); it != sz.rend() && it->first > rk; it++) {
                if (*mp[it->second].find_by_order(rk) <= y) ans++;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}