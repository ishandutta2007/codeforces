#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

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

ll t, n, m, ans, x[MN], y[MN];

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &m);

    union_find dsu(n);
    ans = m;
    for(int i = 0; i < m; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
        if(x[i] == y[i]) ans--;
        else if(!dsu.join(x[i], y[i])) ans++;
    }

    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}