#include <bits/stdc++.h>

using namespace std;

double mid;

struct edge {
    int a, b, id;
    double c;

    edge(int a, int b, double c, int id) : a(a), b(b), c(c), id(id) {}

    bool operator <(const edge &o) const {
        double c1 = c, c2 = o.c;
        if(a == 1 || b == 1) c1 += mid;
        if(o.a == 1 || o.b == 1) c2 += mid;
        return c1 < c2;
    }
};

int n, m, k, a, b, c;
vector<edge> adj;
vector<int> used;

struct union_find {
    vector<int> parent, rank_;

    union_find() {}

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
} MST;

int check() {
    sort(adj.begin(), adj.end());
    used.clear();
    int count_ = 0;
    MST.init(n);

    for(int i = 0; i < adj.size(); i++) {
        a = adj[i].a, b = adj[i].b;
        if(MST.join(a, b)) {
            used.push_back(adj[i].id);
            if(a == 1 || b == 1) count_++;
        }
    }

    return count_;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        adj.push_back(edge (a, b, c + (a == 1 || b == 1)*1e-7*i, i));
    }

    int it = 100;
    double l = -100002, r = 100002;
    while(it--) {
        mid = (l + r)/ 2;
        int ch = check();
        //printf("%.15lf %.15lf %.15lf %d\n", l, mid, r, ch);
        if(ch == k) break;
        if(ch > k) l = mid;
        else r = mid;
    }

    if(check() == k) {
        printf("%d\n", used.size());
        for(int i = 0; i < used.size(); i++)
            printf("%d ", used[i]);
    } else printf("-1\n");


    return 0;
}