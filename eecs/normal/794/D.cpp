#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
const int maxn = 300010;
int n, m, cur, tot, bel[maxn], num[maxn];
vector<int> G[maxn], H[maxn], id[maxn];
map<ull, int> mp;
vector<pair<int, int>> E;

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        if (u > v) swap(u, v);
        E.emplace_back(u, v);
        G[u].push_back(v), G[v].push_back(u);
    }
    sort(E.begin(), E.end());
    for (int i = 1; i <= n; i++) {
        G[i].push_back(i);
        sort(G[i].begin(), G[i].end());
        ull h = 0;
        for (int j : G[i]) h = h * 19260817 + j;
        if (!mp.count(h)) mp[h] = ++tot;
        bel[i] = mp[h];
    }
    for (int i = 1; i <= n; i++) {
        for (int j : G[i]) if (bel[i] ^ bel[j]) {
            H[bel[i]].push_back(bel[j]);
        }
    }
    for (int i = 1; i <= tot; i++) {
        sort(H[i].begin(), H[i].end());
        H[i].resize(unique(H[i].begin(), H[i].end()) - H[i].begin());
    }
    function<void(int)> dfs = [&](int v) {
        num[v] = ++cur;
        for (int u : H[v]) if (!~num[u]) dfs(u);
    };
    memset(num, -1, sizeof(num));
    for (int i = 1; i <= tot; i++) {
        if (H[i].size() <= 1) { dfs(i); break; }
    }
    for (int i = 1; i <= tot; i++) {
        if (!~num[i]) puts("NO"), exit(0);
    }
    for (int i = 1; i <= n; i++) {
        id[num[bel[i]]].push_back(i);
    }
    for (int i = 1; i <= cur; i++) {
        for (int j : id[i]) for (int k : id[i]) if (j < k) {
            if (!binary_search(E.begin(), E.end(), make_pair(j, k))) {
                puts("NO"), exit(0);
            }
        }
        for (int j : id[i]) for (int k : id[i + 1]) {
            if (!binary_search(E.begin(), E.end(), make_pair(min(j, k), max(j, k)))) {
                puts("NO"), exit(0);
            }
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) {
        printf("%d ", num[bel[i]]);
    }
    return 0;
}