#pragma GCC optimize("O3")

#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

using uint = unsigned int;

mt19937 rnd(time(nullptr));

struct Node {
    int x;
    uint y;
    Node* l;
    Node* r;
    int size;

    explicit Node(int val) {
        x = val;
        y = rnd();
        l = nullptr;
        r = nullptr;
        size = 1;
    }

    static int Size(Node* node) {
        if (!node) {
            return 0;
        }
        return node->size;
    }

    static void Upd(Node* node) {
        if (!node) {
            return;
        }
        node->size = 1 + Size(node->l) + Size(node->r);
    }

    static Node* Merge(Node* l, Node* r) {
        if (!l) {
            return r;
        }
        if (!r) {
            return l;
        }
        if (l->y > r->y) {
            l->r = Merge(l->r, r);
            Upd(l);
            return l;
        } else {
            r->l = Merge(l, r->l);
            Upd(r);
            return r;
        }
    }

    static pair<Node*, Node*> Split(Node* node, int x) {
        if (!node) {
            return {};
        }
        if (Size(node->l) + 1 <= x) {
            auto tmp = Split(node->r, x - Size(node->l) - 1);
            node->r = tmp.first;
            Upd(node);
            return {node, tmp.second};
        } else {
            auto tmp = Split(node->l, x);
            node->l = tmp.second;
            Upd(node);
            return {tmp.first, node};
        }
    }

    static void Insert(Node*& node, int pos, int val) {
        auto tmp = Split(node, pos - 1);
        Node* new_node = new Node(val);
        node = Merge(tmp.first, Merge(new_node, tmp.second));
    }

    static int Get(Node*& node, int pos) {
        auto tmp1 = Split(node, pos);
        auto tmp2 = Split(tmp1.first, pos - 1);
        int result = tmp2.second->x;
        node = Merge(tmp2.first, Merge(tmp2.second, tmp1.second));
        return result;
    }
};

struct Treap {
    Node* root;

    explicit Treap(int n) {
        root = nullptr;
        for (int i = 0; i < n; ++i) {
            Insert(1, -1);
        }
    }

    void Insert(int pos, int val) {
        Node::Insert(root, pos, val);
    }

    int Get(int pos) {
        return Node::Get(root, pos);
    }
};

struct MergeSortTree {
    int n;
    vector<vector<int>> t;

    explicit MergeSortTree(int _n) {
        n = _n;
        t.resize(n << 2);
    }

    void Build(int v, int tl, int tr, vector<int>& a) {
        if (tl == tr) {
            t[v].push_back(a[tl]);
            return;
        }
        int tm = (tl + tr) / 2;
        Build(v * 2, tl, tm, a);
        Build(v * 2 + 1, tm + 1, tr, a);
        merge(t[v * 2].begin(), t[v * 2].end(),
              t[v * 2 + 1].begin(), t[v * 2 + 1].end(), back_inserter(t[v]));
    }

    int Get(int v, int tl, int tr, int l, int r, int l_val, int r_val) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return (int) (upper_bound(t[v].begin(), t[v].end(), r_val) -
                          lower_bound(t[v].begin(), t[v].end(), l_val));
        int tm = (tl + tr) / 2;
        int x = Get(v * 2, tl, tm, l, min(r, tm), l_val, r_val);
        int y = Get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, l_val, r_val);
        return x + y;
    }

    void Build(vector<int>& a) {
        Build(1, 0, n - 1, a);
    }

    int Get(int l, int r, int l_val, int r_val) {
        return Get(1, 0, n - 1, l, r, l_val, r_val);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = i + 1 - a[i];
    }
    vector<int> p(n, -1);
    Treap treap(n + 1);
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) {
            treap.Insert(a[i] + 1, a[i] ? treap.Get(a[i]) : i);
            p[i] = treap.Get(a[i] + 1);
        }
    }
    MergeSortTree merge_sort_tree(n);
    merge_sort_tree.Build(p);
    while (q--) {
        int l, r;
        cin >> l >> r;
        r = n - r - 1;
        cout << merge_sort_tree.Get(l, r, l, n + 1) << "\n";
    }
    return 0;
}