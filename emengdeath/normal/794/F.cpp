#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 1e5 + 10;
struct node{
    long long v[10];
    int tag[10];
    void init(int x) {
        int y = 1;
        memset(v, 0, sizeof(v));
        while (x) {
            v[x % 10] += y;
            x /= 10;
            y *= 10;
        }
    }
    void updtag(int*_tag) {
        for (int i = 0; i < 10; i ++)
            tag[i] = _tag[tag[i]];
    }
    bool havetag() {
        for (int i = 0; i < 10 ; i++)
            if (tag[i] != i) return 1;
        return 0;
    }
}f[N * 4];
int a[N];
int n, q;
int tag[10];
long long ans;
void upd(int s) {
    for (int i = 0; i < 10; i ++)
        f[s].v[i] = f[s+s].v[i] + f[s+s+1].v[i];
}
void build(int l, int r, int  s) {
    for (int i = 0; i < 10; i ++)
        f[s].tag[i] = i;
    if (l == r) {
        f[s].init(a[l]);
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    upd(s);
}

long long tmp[10] = {0};
void down(int l, int r, int s) {
    if (!f[s].havetag()) return;
    for (int i = 0; i < 10; i ++)
        tmp[f[s].tag[i]] += f[s].v[i];
    for (int i = 0; i < 10; i ++)
        f[s].v[i] = tmp[i], tmp[i] = 0;
    if (l != r)
        f[s+s].updtag(f[s].tag), f[s+s+1].updtag(f[s].tag);
    for (int i = 0; i < 10; i ++)
        f[s].tag[i] = i;
}
void change(int l, int r, int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l &&r <= rr) {
        f[s].updtag(tag);
        down(l, r, s);
        return;
    }
    change(l, (l +r )/ 2, s +s, ll, rr);
    change((l + r) / 2 + 1, r, s +s  +1, ll, rr);
    upd(s);
}
void get(int l, int r, int s, int ll, int rr) {
    down(l, r, s);
    if (r < ll || rr < l) return ;
    if (ll <= l && r <= rr) {
        for (int i = 1; i < 10; i ++)
            ans += f[s].v[i] * i;
        return;
    }
    get(l, (l + r) / 2, s + s, ll, rr);
    get((l + r) / 2 + 1, r, s + s + 1, ll, rr);
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i= 1; i <= n ; i ++) {
        scanf("%d", &a[i]);
    }
    build(1, n, 1);
    while (q --) {
        int sig, l, r, x, y;
        scanf("%d %d %d", &sig, &l, &r);
        if (sig ==1) {
            scanf("%d %d", &x, &y);
            for (int i = 0; i < 10; i ++)  tag[i] = i;
            tag[x] = y;
            change(1, n, 1, l, r);
            continue;
        }
        ans = 0;
        get(1, n, 1, l, r);
        printf("%lld\n", ans);
    }
    return 0;
}