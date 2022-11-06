#include <bits/stdc++.h>

// Contest: Codeforces Round #599 (Div. 1) (https://codeforces.com/contest/1242)
// Problem: C: Sum Balance (https://codeforces.com/contest/1242/problem/C)

using namespace std;

template <class T, size_t... Is> struct arr_helper;
template <class T, size_t... Is> using arr = typename arr_helper<T, Is...>::type;
template <class T> struct arr_helper<T> { using type = T; };
template <class T, size_t I, size_t... Is>
struct arr_helper<T, I, Is...> { using type = array<arr<T, Is...>, I>; };

using ll = int64_t;
using u64 = uint64_t;
using u32 = uint32_t;

using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<int, int>;
using vpi = vector<pi>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    u32 k; cin >> k;
    map<ll, pair<int, int>> where;
    vector<vector<ll>> boxes(k);
    for (int i = 0; i < k; ++i) {
        int ni; cin >> ni;
        boxes[i].resize(ni);
        for (auto& v : boxes[i]) cin >> v;
        for (int j = 0; j < ni; ++j)
            where[boxes[i][j]] = {i, j};
    }

    vector<ll> sums(k);
    for (int i = 0; i < k; ++i)
        sums[i] = accumulate(begin(boxes[i]), end(boxes[i]), (ll)0);

    ll total_sum = accumulate(begin(sums), end(sums), (ll)0);
    if (total_sum % k) {
        cout << "No\n";
        return 0;
    }
    ll target_sum = total_sum / k;

    vector<pair<int, int>> dp(1u << k, pair(-1, -1));
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < boxes[i].size(); ++j) {
            bitset<15> vis;
            int box = i, val = j;
            bool br = false;
            while (!vis[box]) {
                vis[box] = true;
                ll rem = sums[box] - boxes[box][val];
                ll tar = target_sum - rem;
                auto it = where.find(tar);
                if (it == end(where)) {
                    br = true;
                    break;
                }
                tie(box, val) = it->second;
            }
            if (!br && box == i && val == j)
                dp[vis.to_ulong()] = {i, j};
        }
    }

    for (u32 m = 1; m < (1u << k); ++m) {
        if (dp[m].first != -1)
            continue;
        for (u32 sm = m; sm > 0; sm = (sm - 1) & m) {
            if (dp[sm].first != -1 && dp[m & ~sm].first != -1) {
                dp[m] = dp[sm];
                break;
            }
        }
    }

    u32 full = (1u << k) - 1;
    if (dp[full].first == -1) {
        cout << "No\n";
        return 0;
    }

    u32 m = full;
    vector<pair<int, int>> res(k);
    while (m) {
        auto [box, val] = dp[m];
        bitset<15> vis;
        while (!vis[box]) {
            vis[box] = true;
            ll rem = sums[box] - boxes[box][val];
            ll tar = target_sum - rem;
            auto [next_box, next_val] = where[tar];
            res[next_box] = {boxes[next_box][next_val], box};
            box = next_box;
            val = next_val;
        }

        m &= ~vis.to_ulong();
    }

    cout << "Yes\n";
    for (auto [c, p] : res)
        cout << c << ' ' << (p + 1) << '\n';

    return 0;
}