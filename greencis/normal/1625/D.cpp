#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

struct Node {
    int go[2] = {0, 0};
    int who = -1;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << n << '\n';
        for (int i = 1; i <= n; ++i)
            cout << i << ' ';
        cout << '\n';
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int highest = -1;
    for (int i = 0; i < 30; ++i)
        if (k & (1 << i))
            highest = i;
    map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i] >> (highest + 1)].push_back(i);
    }
    vector<int> ans;
    for (const auto& [_, bucket] : mp) {
        if (bucket.empty()) continue;
        vector<Node> trie;
        trie.resize(2);
        for (int idx : bucket) {
            int v = 1;
            for (int i = highest; i >= 0; --i) {
                int digit = (a[idx] >> i) & 1;
                if (!trie[v].go[digit]) {
                    trie[v].go[digit] = (int)trie.size();
                    trie.emplace_back();
                }
                v = trie[v].go[digit];
            }
            trie[v].who = idx;
        }

        int best = -1;
        int bestIdx1 = -1;
        int bestIdx2 = -1;
        function<void(int, int, int, int)> dfs = [&](int v0, int v1, int cur, int bit) {
            if (!v0 || !v1) return;
            if (bit == -1) {
                if (cur > best) {
                    best = cur;
                    bestIdx1 = trie[v0].who;
                    bestIdx2 = trie[v1].who;
                }
                return;
            }
            if ((trie[v0].go[0] && trie[v1].go[1]) || (trie[v0].go[1] && trie[v1].go[0])) {
                dfs(trie[v0].go[0], trie[v1].go[1], cur | (1 << bit), bit - 1);
                dfs(trie[v0].go[1], trie[v1].go[0], cur | (1 << bit), bit - 1);
            } else {
                dfs(trie[v0].go[0], trie[v1].go[0], cur, bit - 1);
                dfs(trie[v0].go[1], trie[v1].go[1], cur, bit - 1);
            }
        };
        dfs(1, 1, 0, highest);
        if (best >= k) {
            ans.push_back(bestIdx1);
            ans.push_back(bestIdx2);
        } else {
            ans.push_back(bucket[0]);
        }
    }
    if (ans.size() <= 1) {
        cout << "-1\n";
        return 0;
    }
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i + 1 << ' ';
    cout << '\n';
}