#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using LL = long long;

struct Node{
    int v, p, size;
    Node *L, *R;
    Node(int v, int p, Node* L = nullptr, Node* R = nullptr) : v(v), p(p), size(1), L(L), R(R) {
    }
    Node* copy(Node* L, Node* R) {
        this->L = L;
        this->R = R;
        return this;
    }
};
namespace Treap {
    mt19937 rng;
    int size(Node* p) {
        return p ? p->size : 0;
    }
    Node* update(Node* p) {
        p->size = 1 + size(p->L) + size(p->R);
        return p;
    }
    pair<Node*, Node*> split(Node* p, int v) {
        if (not p) return {};
        if (p->v <= v) {
            auto [L, R] = split(p->R, v);
            return {update(p->copy(p->L, L)), R};
        }
        auto [L, R] = split(p->L, v);
        return {L, update(p->copy(R, p->R))};
    }
    Node* merge(Node*L, Node* R) {
        if (not L) return R;
        if (not R) return L;
        if (L->p < R->p) return update(L->copy(L->L, merge(L->R, R)));
        return update(R->copy(merge(L, R->L), R->R));
    }
    Node* insert(Node* p, int v) {
        auto [L, R] = split(p, v);
        return merge(merge(L, new Node(v, rng())), R);
    }
    Node* remove(Node* p, int v) {
        auto [LM, R] = split(p, v);
        auto [L, M] = split(LM, v - 1);
        return merge(merge(L, M ? merge(M->L, M->R) : M), R);
    }
    int rank(Node* p, int v) {
        if (not p) return 1;
        if (p->v >= v) return rank(p->L, v);
        return 1 + size(p->L) + rank(p->R, v);
    }
    Node* kth(Node* p, int k) {
        if (not p or k > p->size) return nullptr;
        if (k <= size(p->L)) return kth(p->L, k);
        if (k == size(p->L) + 1) return p;
        return kth(p->R, k - size(p->L) - 1);
    }
    Node* pedecessor(Node* p, int v) {
        if (not p) return p;
        if (p->v >= v) return pedecessor(p->L, v);
        auto R = pedecessor(p->R, v);
        return R ? R : p;
    }
    Node* successor(Node* p, int v) {
        if (not p) return p;
        if (p->v <= v) return successor(p->R, v);
        auto L = successor(p->L, v);
        return L ? L : p;
    }
};
using namespace Treap;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        string s;
        cin >> n >> s;
        //(m - p) % 3 == 0 m >= p
        LL ans = 0;
        vector<Node*> r(3, nullptr);
        r[0] = insert(r[0], 0);
        int p = 0;
        for (char c : s) {
            if (c == '-') p += 1;
            else p -= 1;
            int m = (p % 3 + 3) % 3;
            //cout << p << " " << m << "\n";
            ans += Treap::rank(r[m], p + 1) - 1;
            r[m] = insert(r[m], p);
        }
        cout << ans << "\n";
    }
    return 0;
}