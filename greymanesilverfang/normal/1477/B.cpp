#include <cstdio>
#include <cstring>
const int MAX = 3e5;

struct SegTree {
    char s[MAX];
    struct Node {
        int l, r, len, cnt, lazy = -1;
        void modify(int val) {
            cnt = len * val;
            lazy = val;
        }
    };
    Node node[MAX * 4];
    void update(int id) {
        node[id].cnt = node[id * 2].cnt + node[id * 2 + 1].cnt;
    }
    void build(int l, int r, int id = 1) {
        node[id] = Node();
        node[id].l = l;
        node[id].r = r;
        node[id].len = r - l + 1;
        if (l == r) {
            node[id].modify(s[l - 1] - '0');
            return;
        }
        int m = (l + r) / 2;
        build(l, m, id * 2);
        build(m + 1, r, id * 2 + 1);
        update(id);
    }
    void init(int n, char s[]) {
        strcpy(this->s, s);
        build(1, n);
    }
    void lazy(int id) {
        int& lazy = node[id].lazy;
        if (lazy == -1)
            return;
        node[id * 2].modify(lazy);
        node[id * 2 + 1].modify(lazy);
        lazy = -1;
        return;
    }
    int count(int l, int r, int id = 1) {
        if (node[id].r < l || r < node[id].l)
            return 0;
        if (l <= node[id].l && node[id].r <= r)
            return node[id].cnt;
        lazy(id);
        return count(l, r, id * 2) + count(l, r, id * 2 + 1);
    }
    void paint(int l, int r, int val, int id = 1) {
        if (node[id].r < l || r < node[id].l)
            return;
        if (l <= node[id].l && node[id].r <= r) {
            node[id].modify(val);
            return;
        }
        paint(l, r, val, id * 2);
        paint(l, r, val, id * 2 + 1);
        update(id);
    }
    void build(char s[], int id = 1) {
        if (node[id].lazy != -1) {
            for (int i = node[id].l; i <= node[id].r; ++i)
                s[i - 1] = node[id].lazy + '0';
            return;
        }
        build(s, id * 2);
        build(s, id * 2 + 1);
    }
};

SegTree T;
bool check(int n, int q, int l[], int r[], char s[], char f[]) {
    T.init(n, f);
    for (int i = q; i >= 1; --i) {
        int L = l[i], R = r[i];
        int cnt = T.count(L, R);
        int len = R - L + 1;
        if (cnt * 2 < len)
            T.paint(L, R, 0);
        if (cnt * 2 > len)
            T.paint(L, R, 1);
        if (cnt * 2 == len)
            return false;
        // T.build(f);
        // printf("current %s\n", f);
    }
    T.build(f);
    return !strcmp(s, f);
}

char s[MAX], f[MAX];
int l[MAX], r[MAX];
void solve() {
    int n, q; scanf("%d%d%s%s", &n, &q, s, f);
    for (int i = 1; i <= q; ++i)
        scanf("%d%d", &l[i], &r[i]);
    printf("%s\n", check(n, q, l, r, s, f) ? "YES" : "NO");
}

int main() {
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; ++i)
        solve();
}