#include <bits/stdc++.h>

using namespace std;

#include <bits/extc++.h>

template <typename K, typename V, typename Comp = std::less<K>>
using ordered_map = __gnu_pbds::tree<
	K, V, Comp,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>; // from ecnerwala's library

using pii = pair<int, int>;

const int nil = -2e9;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pii> a(n);
        for (auto &[l, r] : a) cin >> l >> r;
        sort(a.begin(), a.end());

        map<int, int> map_l;
        ordered_map<int, int> map_r;
        vector<pii> op(n);
        for (int i = 0; i < n; i++) {
            auto &[l, r] = a[i];

            int pl = nil, pr = nil;
            if (!map_l.empty()) {
                tie(pl, pr) = *map_l.rbegin();
            }

            if (pr < l) {
                op[i] = {l, nil};
                map_l[l] = r;
            } else {
                op[i] = {pl, pr};
                if (pr < r) map_l[pl] = r;
            }
        }

        int ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            auto &[op_l, op_r] = op[i];
            if (op_r == nil) {
                map_l.erase(op_l);
            } else {
                map_l[op_l] = op_r;
            }

            int overlap = 0;
            if (!map_l.empty() && !map_r.empty()) {
                int x = map_l.rbegin()->second;
                overlap = map_r.order_of_key(x + 1);
            }

            ans = max(int(map_l.size() + map_r.size()) - overlap, ans);

            auto &[l, r] = a[i];
            auto map_r_it = map_r.lower_bound(l);
            while (map_r_it != map_r.end() && map_r_it->second < r) {
                auto rm = map_r_it;
                map_r_it++;
                map_r.erase(rm);
            }

            if (map_r_it == map_r.end() || map_r_it->first > r) {
                map_r[l] = r;
            } else {
                int nr = max(map_r_it->second, r);
                map_r.erase(map_r_it);
                map_r[l] = nr;
            }
        }

        cout << ans << '\n';
    }
}