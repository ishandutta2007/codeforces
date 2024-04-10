#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MAX_BITS = 20;

struct segment {
    int n;
    int basis[MAX_BITS];

    // TODO: make sure the default constructor is the identity segment.
    segment() : n(0) {}

    int get_max() const {
        int answer = 0;

        for (int i = 0; i < n; i++)
            answer = max(answer, answer ^ basis[i]);

        return answer;
    }

    void join(const segment &other) {
        if (n == MAX_BITS)
            return;

        for (int i = 0; i < other.n; i++) {
            int x = other.basis[i];

            for (int j = 0; j < n; j++)
                x = min(x, x ^ basis[j]);

            if (x != 0) {
                basis[n++] = x;

                // Insertion sort.
                for (int k = n - 1; k > 0 && basis[k] > basis[k - 1]; k--)
                    swap(basis[k], basis[k - 1]);
            }
        }

        assert(n <= MAX_BITS);
    }

    // TODO: decide whether to re-implement this for better performance. Mainly relevant when segments contain arrays.
    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct basic_seg_tree {
    int tree_n = 0;
    vector<segment> tree;

    basic_seg_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.assign(2 * tree_n, segment());
    }

    // O(n) initialization of our tree.
    void build(const vector<segment> &initial) {
        int n = initial.size();
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) {
        segment answer;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                answer.join(tree[a++]);

            if (b & 1)
                answer.join(tree[--b]);
        }

        return answer;
    }
};


int N, Q;

int main() {
    scanf("%d", &N);
    vector<segment> initial;

    for (int i = 0; i < N; i++) {
        int burger;
        scanf("%d", &burger);
        initial.emplace_back();
        initial.back().n = burger == 0 ? 0 : 1;
        initial.back().basis[0] = burger;
    }

    basic_seg_tree tree(N);
    tree.build(initial);
    scanf("%d", &Q);

    for (int q = 0; q < Q; q++) {
        int L, R;
        scanf("%d %d", &L, &R);
        L--;
        printf("%d\n", tree.query(L, R).get_max());
    }
}