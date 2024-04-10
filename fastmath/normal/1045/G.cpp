#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

int n, k;
int x[MAXN], r[MAXN], q[MAXN];
void read() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> x[i] >> r[i] >> q[i];
}

namespace treap {

mt19937 rnd(228);

struct Node {
    int x, y, cnt;
    Node *l, *r;
    Node(int x_) {
        x = x_;
        y = rnd();
        cnt = 1;
        l = r = NULL;
    }
};

int cnt(Node *t) {
    if (!t) return 0;
    else return t->cnt;
}

void relax(Node *t) {
    t->cnt = cnt(t->l) + cnt(t->r) + 1;
}

Node *merge(Node *l, Node *r) {
    if (!l) return r;
    if (!r) return l;
    if (l->y < r->y) {
        l->r = merge(l->r, r);
        relax(l);
        return l;
    }
    else {
        r->l = merge(l, r->l);
        relax(r);
        return r;
    }
}

pair <Node*, Node*> split(Node *t, int x) {
    if (!t) return {NULL, NULL};
    if (t->x <= x) {
        auto tmp = split(t->r, x);
        t->r = tmp.first;
        relax(t);
        return {t, tmp.second};
    }
    else {
        auto tmp = split(t->l, x);
        t->l = tmp.second;
        relax(t);
        return {tmp.first, t};
    }
}

Node *insert(Node *t, int x) {
    auto tmp = split(t, x);
    return merge(merge(tmp.first, new Node(x)), tmp.second);
}

Node *erase(Node *t, int x) {
    auto tmp1 = split(t, x - 1);
    auto tmp2 = split(tmp1.second, x);
    tmp2.first = merge(tmp2.first->l, tmp2.first->r);
    return merge(merge(tmp1.first, tmp2.first), tmp2.second);
}

};

using namespace treap;

struct Comp {
    bool operator () (const int i, const int j) const {
        return (x[i] + r[i] < x[j] + r[j]) || (x[i] + r[i] == x[j] + r[j] && i < j);
    }   
};

bool comp(int i, int j) {
    return x[i] < x[j];
}

map <int, Node*> d;
map <int, vector <int> > close;
set <int, Comp> ms;

void add(int i) {
    if (d.find(q[i]) == d.end()) d[q[i]] = NULL;
    d[q[i]] = insert(d[q[i]], x[i]);    
    ms.insert(i);
}

void del(int i) {
    d[q[i]] = erase(d[q[i]], x[i]);
    ms.erase(i);
}

int ans = 0;
int per[MAXN];
void solve() {
    for (int i = 0; i < n; ++i) per[i] = i;
    sort(per, per + n, comp);           

    for (int i = 0; i < n; ++i) {
        int num = per[i];

        while (ms.size() && x[*ms.begin()] + r[*ms.begin()] < x[num]) {
            del(*ms.begin());
        }

        int sum = 0;
        for (int j = q[num] - k; j <= q[num] + k; ++j) {
            if (d.find(j) == d.end()) continue;
            auto tmp = split(d[j], x[num] - r[num] - 1);
            ans += cnt(tmp.second);
            sum += cnt(tmp.second);
            d[j] = merge(tmp.first, tmp.second);
        }

        add(num);
    }
}

void print() {
    cout << ans << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}