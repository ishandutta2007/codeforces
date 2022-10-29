#include <stdio.h>
#include <vector>
using namespace std;

struct node {
    int cnt;
    node * child[2];
    node() {
        cnt = 0;
        child[0] = child[1] = nullptr;
    }
} * root;

void add(node* &idx, const int &x, int lvl = 29) {
    if (idx == nullptr)
        idx = new node;
    ++ idx -> cnt;
    if (lvl >= 0)
        add(idx -> child[x>>lvl&1], x, lvl - 1);
}

void del(node* &idx, const int &x, int lvl = 29) {
    if (lvl >= 0)
        del(idx -> child[x>>lvl&1], x, lvl - 1);
    -- idx -> cnt;
    if (idx -> cnt == 0) {
        delete idx;
        idx = nullptr;
    }
}

int get(node* &idx, const int &x, int lvl = 29) {
    if (lvl == -1)
        return 0;
    if (idx -> child[x>>lvl&1^1] != nullptr)
        return (get(idx -> child[x>>lvl&1^1], x, lvl - 1) + (1<<lvl));
    return get(idx -> child[x>>lvl&1], x, lvl - 1);
}

int main() {
    root = new node; add(root, 0);
    int q; scanf("%d", &q);
    while (q--) {
        char c; int x; scanf("\n%c%d", &c, &x);
        switch (c) {
            case '+': add(root, x); break;
            case '-': del(root, x); break;
            default : printf("%d\n", get(root, x)); break;
        }
    }
    return 0;
}