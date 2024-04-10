#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, s, a[maxn];
map<int, int> mp;
unordered_map<int, vector<int>> G;
vector<int> st;
vector<vector<int>> ans;

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]), mp[a[i]]++;
    }
    int sum = 1;
    for (auto &p : mp) {
        for (int i = sum; i < sum + p.second; i++) {
            if (a[i] ^ p.first) G[p.first].push_back(i);
        }
        sum += p.second;
    }
    function<void(int)> dfs = [&](int u) {
        while (!G[u].empty()) {
            int v = G[u].back();
            G[u].pop_back(), dfs(a[v]);
            st.push_back(v);
        }
        G.erase(u);
    };
    while (!G.empty()) {
        st.clear(), dfs(G.begin()->first);
        reverse(st.begin(), st.end()), ans.push_back(st);
        if ((s -= st.size()) < 0) puts("-1"), exit(0);
    }
    s = min(s, (int)ans.size());
    printf("%d\n", ans.size() - max(0, s - 2));
    if (s > 2) {
        vector<int> all, fir;
        for (int i = 0; i < s; i++) {
            copy(ans[i].begin(), ans[i].end(), back_inserter(all));
            fir.push_back(ans[s - i - 1][0]);
        }
        ans.erase(ans.begin(), ans.begin() + s);
        ans.insert(ans.begin(), fir), ans.insert(ans.begin(), all);
    }
    for (auto &V : ans) {
        printf("%d\n", V.size());
        for (int x : V) printf("%d ", x);
        putchar('\n');
    }
    return 0;
}