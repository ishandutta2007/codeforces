#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct Node {
    int cnt = 1, key, prior;
    LL sum[5] = {};
    Node *left = NULL, *right = NULL;
};

typedef Node* PNode;

Node nodes[111111];
int pri[111111];
int nodeCount = 0;

inline int cnt(PNode &v) {
    return v ? v->cnt : 0;
}

inline void update(PNode &v) {
    if (v) {
        v->cnt = cnt(v->left) + cnt(v->right) + 1;
        int off = 0;
        if (v->left) {
            REP(i, 5) v->sum[i] = v->left->sum[i];
            off = v->left->cnt % 5;
        } else {
            REP(i, 5) v->sum[i] = 0;
        }
        v->sum[off] += v->key;
        if (++off == 5) off = 0;
        if (v->right) {
            REP(i, 5) {
                int ii = i + off;
                if (ii >= 5) ii -= 5;
                v->sum[ii] += v->right->sum[i];
            }
        }
    }
}

void merge(PNode l, PNode r, PNode &t) {
    if (!l || !r) {
        t = l ? l : r;
        return;
    }
    if (l->prior > r->prior) {
        merge(l->right, r, l->right);
        t = l;
    } else {
        merge(l, r->left, r->left);
        t = r;
    }
    update(t);
}

void split(PNode t, PNode &l, PNode &r, int key) {
    if (!t) {
        l = r = NULL;
        return;
    }
    if (key < t->key) {
        split(t->left, l, t->left, key);
        r = t;
    } else {
        split(t->right, t->right, r, key);
        l = t;
    }
    update(t);
}

PNode root = NULL;

void addKey(int x) {
    PNode t1, t2, t3;
    split(root, t1, t3, x);
    nodes[nodeCount].key = x;
    nodes[nodeCount].prior = pri[nodeCount];
    t2 = nodes + nodeCount++;
    update(t2);
    merge(t1, t2, root);
    merge(root, t3, root);
}

void delKey(PNode &t, int x) {
    if (t->key == x) {
        merge(t->left, t->right, t);
    } else if (x < t->key) {
        delKey(t->left, x);
    } else {
        delKey(t->right, x);
    }
    update(t);
}

mt19937 mt;

int myRand(int bound) {
    return mt() % bound;
}

char s[10];
int zzz;

int main() {
    REP(i, 111111) pri[i] = i;
    random_shuffle(pri, pri + 111111, myRand);
    int q;
    scanf("%d", &q);
    REP(query, q) {
        scanf("%s", s);
        if (s[0] == 'a') {
            scanf("%d", &zzz);
            addKey(zzz);
        } else if (s[0] == 'd') {
            scanf("%d", &zzz);
            delKey(root, zzz);
        } else {
            if (root == NULL) {
                printf("0\n");
            } else {
                printf("%I64d\n", root->sum[2]);
            }
        }
    }
    return 0;
}