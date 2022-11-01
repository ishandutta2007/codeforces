#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

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

ll n, m;
vector<pair<ll, pair<int, int>>> edges;
map<ll, pair<ll, ll>> comp;

pair<ll, ll> mst(ll x) {
    union_find DSU(n);
    sort(edges.begin(), edges.end(), [&](pair<ll, pair<int, int>> &a, pair<ll, pair<int, int>> &b) {
        return abs(a.first - x) < abs(b.first - x);
    });
    pair<ll, ll> ret(0, 0);
    for (auto edge : edges) {
        if (DSU.join(edge.second.first, edge.second.second)) {
            if (edge.first <= x) ret.second++;
            ret.first += abs(edge.first - x);
        }
    }
    return ret;
}

int main() {
    scanf("%lld %lld", &n, &m);
    for (int i = 0, u, v, w; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges.push_back({w, {u, v}});
    }

    comp[0];
    comp[100000000];
    for (auto edge1 : edges)
        for (auto edge2 : edges) {
            ll s = (edge1.first + edge2.first) / 2;
            comp[s];
            comp[s-1];
            comp[s+1];
        }

    for (auto &cc : comp) {
        cc.second = mst(cc.first);
    }

    ll p, k, a, b, c, q, ans = 0;
    scanf("%lld %lld %lld %lld %lld", &p, &k, &a, &b, &c);
    for (int i = 0; i < k; i++) {
        if (i < p) scanf("%lld", &q);
        else q = (q * a + b) % c;

        auto bb = prev(comp.upper_bound(q));
        
        ll value = bb->second.first;
        value += (q - bb->first) * bb->second.second;
        value -= (q - bb->first) * (n - 1 - bb->second.second);
        ans ^= value;
    }
    printf("%lld\n", ans);
    return 0;
}