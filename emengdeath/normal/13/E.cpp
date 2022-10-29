#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e5 + 10;
struct point{
    int v,fa,o, sum;
    int son[2];
    bool rev;
}tr[N];
int getroot(int x){
    for (;tr[x].fa;x=tr[x].fa);
    return x;
}
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
void update(int x){
    if (x) {
        tr[x].v = tr[x].o;
        tr[x].sum = 1;
        if (tr[x].son[0])
            tr[x].v = max(tr[x].v, tr[tr[x].son[0]].v), tr[x].sum += tr[tr[x].son[0]].sum;
        if (tr[x].son[1])
            tr[x].v = max(tr[x].v, tr[tr[x].son[1]].v), tr[x].sum += tr[tr[x].son[1]].sum;
    }
}
void rotate(int x){
    int p = tr[x].fa, g = tr[p].fa, d = son(x);
    tr[tr[p].son[d] = tr[x].son[!d]].fa = p;
    if (root(p))tr[g].son[son(p)] = x;
    tr[x].fa = g;
    tr[tr[x].son[!d] = p].fa = x, update(p), update(x);
}
int st[N];
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
    for (;x;tr[x].son[1]=y,update(x),y=x,x=tr[x].fa)splay(x);
    for (;tr[y].son[0]; y = tr[y].son[0]);
    return y;
}
void evert(int x){//
    access(x);
    splay(x);
    change(x);//
}
void link(int u,int v){
    evert(u);
    if (access(v) != u) {
        tr[u].fa = v;
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
pair<int, int> quest(int u,int v) {
    evert(u);
    access(v);
    splay(v);
    return {tr[v].v, tr[v].sum};
}
int n, m;
int a[N];
void link(int x) {
    if (a[x] + x > n) link(x, n + 1);
    else
        link(x, a[x] + x);
}
void cut(int x) {
    if (a[x] + x > n) cut(x, n + 1);
    else
        cut(x, a[x] + x);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)tr[i].o = tr[i].v = i, tr[i].sum = 1;
    tr[n + 1].sum = 1;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        link(i);
    }
    while (m --) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x == 1) {
            auto u = quest(y, n + 1);
            printf("%d %d\n", u.first, u.second - 1);
        } else {
            int z;
            scanf("%d", &z);
            cut(y);
            a[y] = z;
            link(y);
        }
    }
    return 0;
}