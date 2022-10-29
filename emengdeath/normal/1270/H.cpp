#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1e6;
struct node{
    int tag;
    int mn;
    int cnt;
}f[(N + 10) * 4];
int a[N], b[N + 10];
int n, q;
void combine(node&f, node a, node b) {
    if (!a.cnt) {
        f = b;
        return;
    }
    else
    if (!b.cnt) {
        f = a;
        return;
    }
    if (a.mn < b.mn)
        f = a;
    else {
        if (a.mn > b.mn)
            f = b;
        else
            f = a, f.cnt += b.cnt;
    }
}
void build(int l, int r, int s) {
    if (l == r) {
        f[s].mn = b[l];
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    combine(f[s], f[s+s],f[s+s+1]);
}
void down(int l, int r, int s){
    if (f[s].tag) {
        f[s].mn += f[s].tag;
        if (l != r)
            f[s+s].tag +=f[s].tag, f[s+s+1].tag+=f[s].tag;
        f[s].tag = 0;
    }
}
void add(int l, int r, int s, int ll, int rr, int v) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        f[s].tag += v;
        down(l, r, s);
        return;
    }
    add(l, (l + r) / 2, s + s, ll, rr, v);
    add((l + r) / 2 + 1, r, s + s + 1, ll, rr, v);
    combine(f[s], f[s+s],f[s+s+1]);
}
void change(int l, int r, int s, int ll, int v) {
    down(l, r, s);
    if (r < ll || l > ll) return;
    if (l == r) {
        f[s].cnt = v;
        return;
    }
    change(l, (l + r) / 2, s + s, ll, v);
    change((l + r) / 2+ 1, r, s + s + 1, ll, v);
    combine(f[s], f[s+s], f[s+s+1]);
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i<= n; i ++)
        scanf("%d", &a[i]);
    a[0] = N + 1;
    a[n + 1] = 0;
    for (int i = 0; i <= n; i ++)
        if (a[i] < a[i + 1]) {
            b[a[i] + 1] ++;
            b[a[i + 1] + 1] --;
        }
    for (int i = 1; i <= N ; i++)
        b[i] += b[i - 1];
    build(1, N, 1);
    for (int i = 1; i <= n; i ++)
        change(1, N , 1, a[i], 1);
    while (q --) {
        int x ,y;
        scanf("%d %d", &x, &y);
        if (a[x] != y) {
            if (a[x] < y) {
                add(1, N, 1, a[x] + 1, y, 1);
                add(1, N, 1, a[x] + 1, min(a[x+1], y), -1);
                add(1, N, 1, a[x] + 1, min(a[x - 1], y), -1);
            } else {
                add(1, N, 1, y + 1, a[x], -1);
                add(1, N, 1, y + 1, min(a[x+1], a[x]), 1);
                add(1, N, 1, y + 1, min(a[x - 1], a[x]), 1);
            }
            change(1, N ,1 , a[x], 0);
            change(1, N ,1 , y, 1);
            a[x] = y;
        }
        printf("%d\n", f[1].cnt);
    }
    return 0;
}