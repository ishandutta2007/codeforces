#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
const int N = 1e6;
priority_queue<pair<long long, int> > q;
int fa[N];
int head, tail;
int getfa(int x){
    return x == fa[x] ? x : fa[x] = getfa(fa[x]);
}
long long allen, alls;
int n, m, tot, root;
struct node{
    int l, r;
    long long len;
    void refresh() {
        l = getfa(l);
        r = getfa(r);
    }
}a[N];
void add_event(long long v, long long len, int x) {
    q.push(make_pair(-((v + len - 1) / len + alls), x));
}
struct node1{
    int son[2];
    long long v, b, k;
    int fa;
    long long size,osize;
}f[N * 4];
void update(int x){
    int l=f[x].son[0],r=f[x].son[1];
    f[l].fa=f[r].fa=x;
    f[x].size=f[l].size+f[r].size+ f[x].osize;
}
void down(int x) {
    if (f[x].b || f[x].k) {
        if (f[x].son[0]) {
            f[x].v += f[x].b + f[x].k * f[f[x].son[0]].size;
            f[f[x].son[0]].b += f[x].b;
            f[f[x].son[0]].k += f[x].k;
        }else
            f[x].v += f[x].b;
        if (f[x].son[1]) {
            f[f[x].son[1]].b += f[x].b + f[x].k * (f[f[x].son[0]].size + f[x].osize);
            f[f[x].son[1]].k += f[x].k;
        }
        f[x].b = f[x].k = 0;
    }
}
void rotate(int x){
    int y=f[x].fa;
    down(y);
    down(x);
    bool e=(f[y].son[1]==x);
    f[y].son[e]=f[x].son[e^1];
    f[x].son[e^1]=y;
    if (f[x].fa=f[y].fa)f[f[x].fa].son[f[f[x].fa].son[1]==y]=x;
    update(y);
    update(x);
}
void splay(int x,int y){
    down(x);
    if (x==y)return;
    while (1){
        if (f[x].fa==y){
            rotate(x);
            break;
        }else{
            int fa=f[x].fa,fa1=f[fa].fa;
            if ((f[fa].son[0]==x)==(f[fa1].son[0]==fa))rotate(fa);
            else
                rotate(x);
            rotate(x);
            if (fa1==y)break;
        }
    }
    if (y == root)
        root = x;
}
long long nowv(int x) {
    x = getfa(x);
    splay(x, root);
    return f[x].v;
}
int main() {
    scanf("%d %d", &n, &m);
    a[++tot].len = n;
    allen = n;
    head = tail = tot;
    root = tot;
    f[tot].osize = f[tot].size = n;
    for (int i = 1; i < N; i ++) fa[i] = i;
    while (m --) {
        int x, y, z;
        scanf("%d %d", &x, &y);
        tail = getfa(tail);
        head = getfa(head);
        if (x <= 2) {
            allen += y;
            if (x == 1) {
                ++tot;
                a[tot].len = allen;
                tail = head = tot;
                root = tot;
                f[tot].size = f[tot].osize = allen;
                while (!q.empty())q.pop();
            } else {
                if (!nowv(tail)) {
                    splay(tail, root);
                    f[tail].osize += y;
                    f[tail].size += y;
                    a[tail].len += y;
                }else {
                    a[++tot].len = y;
                    a[tail].r = tot;
                    a[tot].l = tail;
                    splay(tail, root);
                    f[tail].son[1] = tot;
                    f[tot].size = f[tot].osize = y;
                    update(tail);
                    add_event(nowv(tail) - nowv(tot), a[tail].len, tot);
                    tail = tot;
                }
            }
        } else {
            scanf("%d", &z);
            alls += z;
            f[root].b += y;
            f[root].k += z;
            while (!q.empty() && -q.top().first <= alls) {
                int x = getfa(q.top().second);
                q.pop();
                tail = getfa(tail);
                head = getfa(head);
                a[x].refresh();
                if (a[x].l) {
                    int y = a[x].l;
                    a[y].refresh();
                    if (nowv(x) >= nowv(y) && x != y) {
                        fa[x] = y;
                        a[y].len += a[x].len;
                        splay(y, root);
                        splay(x, f[y].son[1]);
                        f[y].osize += a[x].len;
                        f[y].son[1] = f[x].son[1];
                        update(y);
                        a[y].r = a[x].r;
                        if (!a[y].r) {
                            tail = y;
                        }else
                            add_event(nowv(y) - nowv(a[y].r), a[y].len, a[y].r);
                    }
                }
            }
        }
        tail = getfa(tail);
        head = getfa(head);
        printf("%lld %lld\n", allen - a[tail].len + 1, nowv(tail));
    }
    return 0;
}