#include <algorithm>
#include <cstdio>
using namespace std;
const int N = (1 << 18) + 10;
struct node{
    int son[2];
    int tag;
    long long sum;
}f[N * 4];
int a[N];
int n, m;
void upd(int s){
    f[s].sum = f[f[s].son[0]].sum + f[f[s].son[1]].sum;
}
void build(int l, int r, int s) {
    if (l == r) {
        f[s].sum = a[l];
        return;
    }
    f[s].son[0] = s + s;
    f[s].son[1] = s + s + 1;
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    upd(s);
}
void down(int l, int r, int s) {
    if (f[s].tag) {
        if (f[s].tag & 1)
            swap(f[s].son[0], f[s].son[1]);
        if (l != r)
            f[f[s].son[0]].tag ^= (f[s].tag >> 1), f[f[s].son[1]].tag ^= (f[s].tag >> 1);
        f[s].tag = 0;
    }
}
void change(int l, int r, int s, int ll, int v) {
    down(l, r, s);
    if (l == r) {
        f[s].sum = v;
        return;
    }
    if ((l + r) / 2 >= ll) change(l, (l + r) / 2, f[s].son[0], ll, v);
    else
        change((l + r) / 2 + 1, r, f[s].son[1], ll, v);
    upd(s);
}
long long get(int l, int r, int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return 0;
    if (ll <= l && r <= rr) {
        return f[s].sum;
    }
    return get(l, (l + r) / 2, f[s].son[0], ll, rr) + get((l + r) / 2 + 1, r, f[s].son[1], ll, rr);
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= (1 << n); i ++)
        scanf("%d", &a[i]);
    build(1, (1 << n), 1);
    while (m --) {
        int sig, x, y;
        scanf("%d %d", &sig, &x);
        switch(sig) {
            case 1:
                scanf("%d", &y);
                change(1, (1 << n), 1, x, y);
                break;
            case 2:
                f[1].tag ^= (((1 << n) - 1) - ((1 << (n - x)) - 1));
                break;
            case 3:
                f[1].tag ^= (1 <<(n - x - 1));
                break;
            case 4:
                scanf("%d", &y);
                printf("%lld\n", get(1, (1 << n), 1, x, y));
                break;
        }
    }
    return 0;
}