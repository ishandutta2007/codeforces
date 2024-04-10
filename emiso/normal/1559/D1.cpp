#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, rank_;
    union_find(int n) { init(n); }
    void init(int n) {
        parent.resize(n + 1); rank_.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }
    bool join(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;
        if(rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        rank_[a] += rank_[b];
        return true;
    }
};
vector<union_find> d(2, union_find(1010));

int n, m[2], ans;
vector<pair<int, int>> ed;

int main() {
    scanf("%d %d %d", &n, &m[0], &m[1]);
    for(int t = 0; t < 2; t++) {
        for(int i = 0, u, v; i < m[t]; i++) {
            scanf("%d %d", &u, &v);
            d[t].join(u, v);
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
            if(d[0].find(i) != d[0].find(j) && d[1].find(i) != d[1].find(j)) {
                d[0].join(i, j);
                d[1].join(i, j);
                ans++;
                ed.emplace_back(i, j);
            }
    
    printf("%d\n", ans);
    for(auto tt : ed) printf("%d %d\n", tt.first, tt.second);
    return 0;
}