#include <algorithm>
#include <cstdio>
#include <vector>
#include <cctype>
#define new_node(size, val, ls, rs, fa) (&(*st[leafy_cnt ++] = node(size, val, ls, rs, fa)))
#define merge(a,b) rotate(new_node(a->size + b->size, b->val, a, b, null))
#define release(a) (st[--leafy_cnt] = a)
#define ratio 4

using namespace std;
const int N = 1e6;
struct node{
    int size, val;
    node *ls, *rs;
    node *fa;
    node(int size = 0, int val = 0, node * ls = NULL, node * rs = NULL, node * fa = NULL):size(size), val(val), ls(ls), rs(rs), fa(fa){}
};
int leafy_cnt, n, m;
node *root, *null, *st[N], t[N], *a[N];
void pre() {
    for (int i = 0;i < N; i ++)
        st[i] = &t[i];
    leafy_cnt = 0;
    null = new node(0, 0, 0, 0);
}
node * link_fs(node * u) {//
    u->ls->fa = u->rs->fa = u;
    return u;
}
node * rotate(node *u) {
    if (u->ls->size > u->rs->size * ratio)
        rotate(u->ls), u->rs = merge(u->ls->rs, u->rs), release(u->ls), u->ls = u->ls->ls;
    else
    if (u->rs->size > u->ls->size * ratio)
        rotate(u->rs), u->ls = merge(u->ls, u->rs->ls), release(u->rs), u->rs = u->rs->rs;
    link_fs(u);
    return u;
}
node* build(int l, int r) {
    if (l == r)
        return a[l] = new_node(1, l, null, null, null);
    node * ls = build(l, (l + r) / 2), * rs = build((l + r) / 2 + 1, r);
    return merge(ls, rs);
}
void split(node * u, int s) {//1~su
    if (u->ls->size < s) {
        split(u->rs, s - u->ls->size);
        u->ls = merge(u->ls, u->rs->ls);
        release(u->rs);
        u->rs = u->rs->rs;
    } else
    if (u->ls->size > s) {
        split(u->ls, s);
        u->rs = merge(u->ls->rs, u->rs);
        release(u->ls);
        u->ls = u->ls->ls;
    }
    link_fs(u);
}
int get_rank_from_node(node*u) {
    int rank = 1;
    while (u->fa != null) {
        if (u->fa->rs == u)
            rank += u->fa->ls->size;
        u = rotate(u->fa);
    }
    return rank;
}
vector<int> ans;
int l[N], r[N];
void dfs(node*u) {
    if (u->size == 1) {
        ans.push_back(u->val);
        return;
    }
    dfs(u->ls), dfs(u->rs);
}
void update(int x, int y) {
    r[x] = max(r[x], y);
    l[x] = min(l[x], y);
}

namespace IO {
    const int BUF_SIZE = 1 << 15;
    char in_buf[BUF_SIZE], out_buf[BUF_SIZE];
    char *p_in_buf = in_buf + BUF_SIZE;
    char *p_out_buf = out_buf;
    inline char get_char() {
        if (p_in_buf == in_buf + BUF_SIZE) {
            fread(in_buf, 1, BUF_SIZE, stdin), p_in_buf = in_buf;
        }
        return *(p_in_buf++);
    }
    inline void put_char(char x) {
        if (p_out_buf == out_buf + BUF_SIZE) {
            fwrite(out_buf, 1, BUF_SIZE, stdout), p_out_buf = out_buf;
        }
        *(p_out_buf++) = x;
    }
    inline void flush() {
        if (p_out_buf != out_buf) {
            fwrite(out_buf, 1, p_out_buf - out_buf, stdout);p_out_buf = out_buf;
        }
    }
}
#define getchar() IO::get_char()
#define putchar(x) IO::put_char(x)
inline int getint() {
    int x = 0;
    char c = getchar();
    while (c <= 32) c = getchar();
    while (c > 32) x = x * 10 + c - 48, c = getchar();
    return x;
}
inline int getint(char &c) {
    int x = 0;
    c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}
template <class T>
inline void _putint(T x) {
    return x ? _putint(x / 10), putchar(48 + x % 10), void() : void();
}
template <class T>
inline void putint(T x) {
    return x == 0 ? putchar('0'), void() : _putint(x), void();
}
inline void getline(char *s) {
    char c = getchar();
    while (c == '\n') c = getchar();
    while (c != '\n') *(s++) = c, c = getchar();
    *s = 0;
}

int main() {
    n = getint(), m = getint();
    pre();
    for (int i = 1; i <= n; i  ++)
        l[i] = r[i] = i;
    root = build(0, n + 1);
    while (m -- ){
        int x;
        x = getint();
        x = get_rank_from_node(a[x]) - 1;
        if (x == 1) continue;
        split(root, x + 1);
        split(root->ls, 1);
        split(root->ls->rs, x - 1);
        update(root->ls->rs->rs->val, x);
        update(root->ls->rs->rs->val, 1);
        swap(root->ls->rs->ls, root->ls->rs->rs);
    }
    dfs(root);
    for (int i = 1; i <= n; i ++)
        update(ans[i], i);
    for (int i = 1; i <= n; i ++)
        printf("%d %d\n", l[i], r[i]);
    return 0;
}