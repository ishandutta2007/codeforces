#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
const int N = 5e5 + 10;
const int S = 19;
int n, m, q;
int r[N], a[N], e[N][2], b[N], h[N], cnt, a2id[N];
struct node{
    int x, y;
    bool can_cut;
}Q[N];
int geth(int x) {return h[x] == x? x: h[x] = geth(h[x]);}
struct point{
    int o, all;
    priority_queue<pair<int, int>, vector<pair<int, int> >, less<pair<int, int> > >vir_all;
    int fa;
    int son[2];
    bool rev;
}tr[N];
int st[N];
void change(int x){
    swap(tr[x].son[0],tr[x].son[1]);
    tr[x].rev^=1;
}
void down(int x){
    if (tr[x].rev){
        tr[x].rev=0;
        if (tr[x].son[0])change(tr[x].son[0]);
        if (tr[x].son[1])change(tr[x].son[1]);
    }
}
bool root(int x){
    return tr[tr[x].fa].son[0]==x||tr[tr[x].fa].son[1]==x;
}
bool son(int x) {
    return tr[tr[x].fa].son[1] == x;
}

void upd_vir_all(int x) {
    while (tr[x].vir_all.size() && (tr[tr[x].vir_all.top().second].fa != x || tr[x].son[0] == tr[x].vir_all.top().second || tr[x].son[1] == tr[x].vir_all.top().second|| tr[x].vir_all.top().first != tr[tr[x].vir_all.top().second].all) )
        tr[x].vir_all.pop();
}
void update(int x){
    if (x) {
        tr[x].all = tr[x].o;
        upd_vir_all(x);
        if (tr[x].vir_all.size())
            tr[x].all = max(tr[x].all, tr[x].vir_all.top().first);
        if (tr[x].son[0])
            tr[x].all = max(tr[x].all, tr[tr[x].son[0]].all);
        if (tr[x].son[1])
            tr[x].all = max(tr[x].all, tr[tr[x].son[1]].all);
    }
}
void rotate(int x){
    int p = tr[x].fa, g = tr[p].fa, d = son(x);
    tr[tr[p].son[d] = tr[x].son[!d]].fa = p;
    if (root(p))tr[g].son[son(p)] = x;
    tr[x].fa = g;
    tr[tr[x].son[!d] = p].fa = x, update(p), update(x);
}
void splay(int x){
    update(x);
    st[0] = 1, st[1] = x;
    while (root(st[st[0]])) st[st[0] + 1] = tr[st[st[0]]].fa, st[0] ++;
    while (st[0]) down(st[st[0] --]);
    for (int p;root(x);rotate(x))
        if (root(p = tr[x].fa) && son(x) == son(p)) rotate(p);
}
int access(int x){
    static int y;
    y=0;
    for (;x;tr[x].son[1]=y,update(x),y=x,x=tr[x].fa) {
        splay(x);
        if (tr[x].son[1]) {
            tr[x].vir_all.push({tr[tr[x].son[1]].all, tr[x].son[1]});
        }
    }
    for (;tr[y].son[0]; y = tr[y].son[0]);
    return y;
}
void evert(int x){
    access(x);
    splay(x);
    change(x);
}
void link(int u,int v){
    evert(u);
    if (access(v) != u) {
        splay(v);
        tr[u].fa = v;
        tr[v].vir_all.push({tr[u].all, u});
        update(v);
    }
}
void cut(int u,int v){
    evert(u);
    if (access(v) == u) {
        splay(v);
        if (tr[v].son[0] == u) {
            tr[v].son[0] = 0, tr[u].fa = 0;
            update(v);
        }
    }
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
bool isdigit(char c) {
    return c >= '0' && c <= '9';
}
inline int getint() {
    int x = 0;
    char c;
    c = getchar();
    while (!isdigit(c)) c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}
int main() {
    //freopen("input", "r", stdin);
    n = getint();
    m = getint();
    q = getint();
    for (int i = 1; i <= n; i ++) {
        a[i] = getint();
        a2id[a[i]] = i;
        h[i] = i;
        tr[i].o = a[i];
    }
    for (int i = 1; i <= m;i ++) {
        r[i] = q + 1;
        e[i][0] = getint();
        e[i][1] = getint();
        b[i] = i;
    }
    for (int i = 1; i <= q; i ++) {
        Q[i].x = getint();
        Q[i].y = getint();
        if (Q[i].x == 2) {
            r[Q[i].y] = i;
        }
    }
    sort(b + 1, b + m + 1, [](int x ,int y) {return r[x] > r[y];});
    for (int i = 1; i <= m; i ++)
    {
        int x = b[i];
        if (geth(e[x][0]) != geth(e[x][1])) {
            int y = geth(e[x][0]);
            int z = geth(e[x][1]);
            h[y] = z;
            link(e[x][0], e[x][1]);
            Q[r[x]].can_cut = 1;
        }
    }
    for (int i = 1; i <= q ;i ++) {
        if (Q[i].x == 1) {
            evert(Q[i].y);
            int x = tr[Q[i].y].all;
            printf("%d\n", x);
            if (x) {
                x = a2id[x];
                evert(x);
                tr[x].o = 0;
                update(x);
            }
        } else {
            if (Q[i].can_cut)
            cut(e[Q[i].y][0], e[Q[i].y][1]);
        }
    }
    return 0;
}