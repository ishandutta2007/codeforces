#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

mt19937 mt(123);

struct Node {
    int key, prior;
    int val;
    LL sum;
    Node *left, *right;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        this->sum = val;
        this->prior = mt();
        left = right = NULL;
    }

    Node() {}
};

typedef Node* PNode;

Node nodes[2000000];
vector<PNode> fr;
int nodeCount = 0;

PNode tree = NULL;

inline LL sum(const PNode &t) {
    return t ? t->sum : 0ll;
}

inline void update(const PNode &t) {
    if (t) {
        t->sum = sum(t->left) + sum(t->right) + t->val;
    }
}

void split(PNode t, PNode &l, PNode &r, int key) {
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
    if (l->prior > r->prior) {
        merge(l->right, r, l->right);
        t = l;
    } else {
        merge(l, r->left, r->left);
        t = r;
    }
    update(t);
}

void erase(PNode &t, int key) {
    if (key == t->key) {
        fr.pb(t);
        merge(t->left, t->right, t);
    } else if (key < t->key) {
        erase(t->left, key);
    } else {
        erase(t->right, key);
    }
    update(t);
}

void insert(PNode &t, PNode node) {
    if (t == NULL) {
        t = node;
    } else if (t->prior < node->prior) {
        split(t, node->left, node->right, node->key);
        t = node;
    } else if (node->key < t->key) {
        insert(t->left, node);
    } else {
        insert(t->right, node);
    }
    update(t);
}

void insert(PNode &t, int key, int val) {
    PNode cur;
    if (fr.empty()) {
        nodes[nodeCount] = Node(key, val);
        cur = nodes + nodeCount++;
    } else {
        cur = fr.back();
        fr.pop_back();
        *cur = Node(key, val);
    }
    insert(t, cur);
}

int n, m;
int a[100000];
int nx[100000], tmp[100000];
set<int> se[100000];

const int OFF = 1 << 17;
PNode st[1 << 18];

int to;
LL stGet(int v, int L, int R, int l, int r) {
    if (l > r) return 0;
    if (L == l && R == r) {
        PNode t1, t2;
        split(st[v], t1, t2, to + 1);
        LL res = sum(t1);
        merge(t1, t2, st[v]);
        return res;
    }
    int mid = (L + R) >> 1;
    return stGet(2 * v, L, mid, l, min(r, mid)) +
        stGet(2 * v + 1, mid + 1, R, max(l, mid + 1), r);
}

void stErase(int ind, int key) {
    for (ind += OFF; ind >= 1; ind >>= 1) {
        erase(st[ind], key);
    }
}

void stInsert(int ind, int key, int val) {
    for (ind += OFF; ind >= 1; ind >>= 1) {
        insert(st[ind], key, val);
    }
}

vector<PII> toErase;
vector<pair<int, PII> > toInsert;

void applyEI() {
    for (PII p : toErase) {
        stErase(p.first, p.second);
    }
    for (auto p : toInsert) {
        stInsert(p.first, p.second.first, p.second.second);
    }
    toErase.clear();
    toInsert.clear();
}

void setNx(int ind, int val) {
    if (nx[ind] != -1) {
        toErase.pb(mp(ind, nx[ind]));
    }
    nx[ind] = val;
    toInsert.pb(mp(ind, mp(val, val - ind)));
}

void change(int ind, int x) {
    if (a[ind] == x) {
        return;
    }
    auto it = se[a[ind]].lower_bound(ind);
    if (it != se[a[ind]].begin()) {
        auto it2 = it;
        --it2;
        auto it3 = it;
        ++it3;
        if (it3 == se[a[ind]].end()) {
            setNx(*it2, *it2 + n);
        } else {
            setNx(*it2, *it3);
        }
    }
    se[a[ind]].erase(it);
    it = se[x].insert(ind).first;
    a[ind] = x;
    if (it != se[x].begin()) {
        auto it2 = it;
        --it2;
        setNx(*it2, ind);
    }
    ++it;
    if (it != se[x].end()) {
        setNx(ind, *it);
    } else {
        setNx(ind, ind + n);
    }
    applyEI();
}

LL solve(int from, int to) {
    ::to = to;
    return stGet(1, 0, OFF - 1, from, to);
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    forn(i, n) {
        scanf("%d", a + i);
        --a[i];
    }
    memset(tmp, -1, sizeof tmp);
    memset(nx, -1, sizeof nx);
    forn(i, n) {
        setNx(i, i + n);
        applyEI();
        if (tmp[a[i]] != -1) {
            setNx(tmp[a[i]], i);
            applyEI();
        }
        tmp[a[i]] = i;
        se[a[i]].insert(i);
    }
    forn(i, m) {
        int qt;
        scanf("%d", &qt);
        if (qt == 1) {
            int ind, x;
            scanf("%d%d", &ind, &x), --ind, --x;
            change(ind, x);
        } else {
            int from, to;
            scanf("%d%d", &from, &to), --from, --to;
            printf("%I64d\n", solve(from, to));
        }
    }
    return 0;
}