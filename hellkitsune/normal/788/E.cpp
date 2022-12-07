#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

inline void modAdd(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

inline void modSub(int &x, int y) {
    x -= y;
    if (x < 0) {
        x += MOD;
    }
}

mt19937 mt(123);

struct Node {
    int key, prio;
    int cnt, val, sum, sum2;
    Node *left, *right;

    Node(int key, int val) {
        this->key = key;
        this->prio = mt();
        cnt = 1;
        this->val = sum = val;
        sum2 = 0;
        left = right = NULL;
    }

    Node() {}
};

typedef Node* PNode;

Node nodes[200000];
int nodeCount = 0;

PNode tree = NULL;

inline int cnt(const PNode &t) {
    return t ? t->cnt : 0;
}

inline int sum(const PNode &t) {
    return t ? t->sum : 0;
}

inline int sum2(const PNode &t) {
    return t ? t->sum2 : 0;
}

inline void update(const PNode &t) {
    if (t) {
        t->cnt = cnt(t->left) + cnt(t->right) + 1;
        t->sum = t->val;
        modAdd(t->sum, sum(t->left));
        modAdd(t->sum, sum(t->right));
        t->sum2 = sum2(t->right);
        modAdd(t->sum2, (LL)t->val * cnt(t->right) % MOD);
        modAdd(t->sum2, (sum2(t->left) + (LL)sum(t->left) * (cnt(t->right) + 1)) % MOD);
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

int n, allc;
int a[100000], all[100000];
int pos[100000], sz[100000];
int le[100000], ri[100000];
vector<int> v[100000];
vector<int> fen;
PNode tle[100000], tri[100000];

void fenAdd(vector<int> &fen, int ind, int val) {
    for (; ind < (int)fen.size(); ind |= ind + 1) {
        modAdd(fen[ind], val);
    }
}

int fenGet(vector<int> &fen, int ind) {
    int res = 0;
    for (; ind >= 0; ind = (ind & (ind + 1)) - 1) {
        modAdd(res, fen[ind]);
    }
    return res;
}

int ans;

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) {
        all[i] = a[i];
    }
    sort(all, all + n);
    allc = unique(all, all + n) - all;
    forn(i, n) {
        a[i] = lower_bound(all, all + allc, a[i]) - all;
    }
    forn(i, allc) {
        v[i].clear();
        sz[i] = 0;
    }
    forn(i, n) {
        pos[i] = sz[a[i]];
        v[a[i]].pb(i);
        ++sz[a[i]];
    }
    fen.assign(allc, 0);
    forn(i, n) {
        le[i] = fenGet(fen, a[i]);
        fenAdd(fen, a[i], 1);
    }
    fen.assign(allc, 0);
    for (int i = n - 1; i >= 0; --i) {
        ri[i] = fenGet(fen, a[i]);
        fenAdd(fen, a[i], 1);
    }
    forn(i, n) {
        nodes[i] = Node(i, le[i]);
        nodes[n + i] = Node(-i, ri[i]);
    }
    forn(i, allc) {
        tle[i] = NULL;
        forn(j, v[i].size()) {
            merge(tle[i], nodes + v[i][j], tle[i]);
        }
        for (int j = (int)v[i].size() - 1; j >= 0; --j) {
            merge(tri[i], nodes + n + v[i][j], tri[i]);
        }
    }
    ans = 0;
    forn(i, n) {
        PNode t1, t2;
        split(tle[a[i]], t1, t2, i);
        int lval = sum(t1);
        merge(t1, t2, tle[a[i]]);

        split(tri[a[i]], t1, t2, -i);
        int rval = sum(t1);
        merge(t1, t2, tri[a[i]]);

        modAdd(ans, (LL)lval * rval % MOD);
    }

    int qc;
    scanf("%d", &qc);
    forn(q, qc) {
        int qt, i;
        scanf("%d%d", &qt, &i), --i;
        if (qt == 1) {
            PNode t1, t2, t3;
            split(tle[a[i]], t1, t2, i);
            split(t2, t2, t3, i + 1);
            int lval = sum(t1);
            modSub(ans, (LL)sum2(t1) * ri[i] % MOD);
            merge(t1, t3, tle[a[i]]);

            split(tri[a[i]], t1, t2, -i);
            split(t2, t2, t3, -i + 1);
            int rval = sum(t1);
            modSub(ans, (LL)sum2(t1) * le[i] % MOD);
            merge(t1, t3, tri[a[i]]);

            modSub(ans, (LL)lval * rval % MOD);
        } else {
            PNode t1, t2, t3;
            split(tle[a[i]], t1, t3, i);
            t2 = nodes + i;
            int lval = sum(t1);
            modAdd(ans, (LL)sum2(t1) * ri[i] % MOD);
            merge(t1, t2, tle[a[i]]);
            merge(tle[a[i]], t3, tle[a[i]]);

            split(tri[a[i]], t1, t3, -i);
            t2 = nodes + n + i;
            int rval = sum(t1);
            modAdd(ans, (LL)sum2(t1) * le[i] % MOD);
            merge(t1, t2, tri[a[i]]);
            merge(tri[a[i]], t3, tri[a[i]]);

            modAdd(ans, (LL)lval * rval % MOD);
        }
        printf("%d\n", ans);
    }
    return 0;
}