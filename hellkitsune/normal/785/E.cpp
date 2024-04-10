#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

mt19937 mt(123);

struct Node {
    int key, prio;
    int cnt;
    Node *left, *right;

    Node(int key) {
        this->key = key;
        this->prio = mt();
        cnt = 1;
        left = right = NULL;
    }

    Node() {}
};

typedef Node* PNode;

Node nodes[10000000];
int nodeCount = 0;

inline int cnt(const PNode &t) {
    return t ? t->cnt : 0;
}

inline void update(const PNode &t) {
    if (t) {
        t->cnt = cnt(t->left) + cnt(t->right) + 1;
    }
}

void split(PNode t, PNode &l, PNode &r, LL key) {
    if (!t) {
        l = r = NULL;
        return;
    }
    if (t->key < key) {
        split(t->right, t->right, r, key);
        l = t;
    } else {
        split(t->left, l, t->left, key);
        r = t;
    }
    update(t);
}

void merge(PNode l, PNode r, PNode &t) {
    if (!l || !r) {
        t = l ? l : r;
        return;
    }
    if (l->prio > r->prio) {
        merge(l->right, r, l->right);
        t = l;
    } else {
        merge(l, r->left, r->left);
        t = r;
    }
    update(t);
}

void _out(PNode node) {
    if (node == NULL) {
        return;
    }
    _out(node->left);
    cerr << node->key << ' ';
    _out(node->right);
}

void out(PNode node) {
    if (node == NULL) {
        cerr << "empty" << endl;
    } else {
        _out(node);
        cerr << endl;
    }
}

PNode st[1 << 19];
const int off = 1 << 18;

LL res = 0;

void stBuild(int v, int L, int R, int l, int r) {
    for (int i = l; i <= r; ++i) {
        nodes[nodeCount] = Node(i);
        merge(st[v], nodes + nodeCount++, st[v]);
    }
    if (L == R) {
        return;
    }
    int mid = (L + R) >> 1;
    stBuild(2 * v, L, mid, l, min(r, mid));
    stBuild(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

void removeNode(PNode &t, int key) {
    if (key < t->key) {
        removeNode(t->left, key);
    } else if (key > t->key) {
        removeNode(t->right, key);
    } else {
        merge(t->left, t->right, t);
    }
    update(t);
}

void stAdd(int pos, int val) {
    for (pos += off; pos >= 1; pos >>= 1) {
        PNode left, mid, right;
        split(st[pos], left, right, val);
        nodes[nodeCount] = Node(val);
        mid = nodes + nodeCount++;
        merge(left, mid, st[pos]);
        merge(st[pos], right, st[pos]);
    }
}

void stRemove(int pos, int val) {
    for (pos += off; pos >= 1; pos >>= 1) {
        removeNode(st[pos], val);
    }
}

int treeGet(PNode t, int key) {
    if (!t) {
        return 0;
    }
    if (key < t->key) {
        return treeGet(t->left, key);
    }
    return cnt(t->left) + 1 + treeGet(t->right, key);
}

int stVal;
int stGet(int v, int L, int R, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == L && r == R) {
        return treeGet(st[v], stVal);
    }
    int mid = (L + R) >> 1;
    int res = 0;
    res += stGet(2 * v, L, mid, l, min(r, mid));
    res += stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
    return res;
}

int n, q;
int l[50000], r[50000];
int a[200000];
LL ans[50000];

int main() {
    //freopen("input.txt", "r", stdin);
    if (0) {
        mt19937 mt(123);
        n = 200000;
        q = 50000;
        forn(i, q) {
            l[i] = mt() % n;
            r[i] = mt() % n;
        }
    } else {
        scanf("%d%d", &n, &q);
        forn(i, q) {
            scanf("%d%d", l + i, r + i);
            --l[i], --r[i];
        }
    }
    stBuild(1, 0, off - 1, 0, n - 1);
    forn(i, n) a[i] = i;
    forn(i, q) {
//        cerr << i << endl;
        int l = ::l[i];
        int r = ::r[i];
        if (l == r) {
            ans[i] = res;
            continue;
        }
        if (l > r) {
            swap(l, r);
        }
        stVal = a[l];
        int lessLeft = stGet(1, 0, off - 1, 0, l - 1);
        res -= l - lessLeft;
        res -= a[l] - lessLeft;
        stRemove(l, a[l]);

        stVal = a[r];
        lessLeft = stGet(1, 0, off - 1, 0, r - 1);
        res -= r - 1 - lessLeft;
        res -= a[r] - (a[l] < a[r]) - lessLeft;
        stRemove(r, a[r]);

        stVal = a[r];
        lessLeft = stGet(1, 0, off - 1, 0, l - 1);
        res += l - lessLeft;
        res += a[r] - (a[l] < a[r]) - lessLeft;
        stAdd(l, a[r]);

        stVal = a[l];
        lessLeft = stGet(1, 0, off - 1, 0, r - 1);
        res += r - lessLeft;
        res += a[l] - lessLeft;
        stAdd(r, a[l]);

        swap(a[l], a[r]);
        ans[i] = res;
    }
    forn(i, q) {
        printf("%I64d\n", ans[i]);
    }
    return 0;
}