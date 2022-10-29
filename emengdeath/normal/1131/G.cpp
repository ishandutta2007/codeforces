#include <algorithm>
#include <cstdio>
using namespace std;
#define min(x, y) (x < y? x: y)
#define max(x, y) (x > y? x: y)
const int N = 1e7 + 10;
long long f[N];
int l[N], r[N], fa[N];
long long c[N];
int a[N];
int n, m, tot;
struct node{
    int a, c;
    node* next;
}b[250000];
node * st[250000];
int getfa(int x) {
    return fa[x] == x ? x: fa[x]  =getfa(fa[x]);
}
void ins(int x, long long v) {
    x ++;
    while (x) {
        f[x] = min(f[x], v);
        x -= x & -x;
    }
}
long long get(int x) {
    x ++;
    long long v = 1e18;
    while (x <= m) {
        v = min(f[x], v);
        x += x & -x;
    }
    return v;
}
int main(){
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i ++) {
        st[i] = &b[tot];
        int k;
        scanf("%d", &k);
        for (int j = 2; j <= k; j ++)
            b[tot].next = &b[tot + 1], tot ++;
        ++tot;
        node * w = st[i];
        for (int j = 1; j <= k; j ++, w = w->next)
            scanf("%d", &w->a);
        w = st[i];
        for (int j = 1; j <= k; j ++, w = w->next)
            scanf("%d", &w->c);
    }
    int q;
    scanf("%d", &q);
    tot = 0;
    while (q --) {
        int id, mul;
        scanf("%d %d", &id, &mul);
        for (node * w = st[id - 1]; w != nullptr; w = w->next)
            a[tot] = w->a, c[tot] = 1ll * w->c * mul, tot ++;
    }
    for (int i = 0; i < m; i ++) {
        fa[i] = i;
        int L = max(i - a[i] + 1, 0);
        int tmp;
        while ((tmp = getfa(i)) > L) {
            fa[tmp] = getfa(tmp - 1);
            tmp = getfa(tmp);
        }
        l[i] = tmp;
    }
    for (int i = m - 1; i >= 0; i --) {
        fa[i] = i;
        int R = min(i + a[i] - 1, m - 1);
        int tmp;
        while ((tmp = getfa(i)) < R) {
            fa[tmp] = getfa(tmp + 1);
            tmp = getfa(tmp);
        }
        r[i] = tmp;
    }
    for (int i = 1; i <= m; i ++)
        f[i] = 1e18;
    for (int i = 0; i < m; i ++) {
        long long v1,v2;
        if (!l[i])
            v1 = c[i];
        else
            v1 = c[i] + get(l[i] - 1);
        if (i)
            v2 = c[i] + get(i - 1);
        else
            v2 = c[i];
        ins(i, v1);
        ins(r[i], v2);
    }
    printf("%lld\n", get(m - 1));
    return 0;
}