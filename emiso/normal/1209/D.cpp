#include <bits/stdc++.h>

using namespace std;

struct union_find {
    vector<int> parent, rank_;

    union_find(int n) {
        init(n);
    }

    void init(int n) {
        parent.resize(n + 1); rank_.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            rank_[i] = 1;
        }
    }

    int find(int node) {
        if(node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    bool join(int a, int b) {
        a = find(a); b = find(b);
        if(a == b) return false;

        if(rank_[a] > rank_[b]) {
            parent[b] = a;
            rank_[a] += rank_[b];
        } else {
            parent[a] = b;
            rank_[b] += rank_[a];
        }
        return true;
    }
};

int n, k, ans;

int main() {
    scanf("%d %d", &n, &k);
    union_find dsu(n);

    for(int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if(!dsu.join(x, y)) ans++;
    }

    printf("%d\n", ans);
    return 0;
}