#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 3e5 + 10;
int n, q;
int a[N];
pair<pair<int, int>, int> w[N];
int v[N];
bool sig[N];
struct node{
    int v;
    pair<int, int> mn;
    int tag;
}f[N * 4];
int ans[N];
void upd(int s) {
    if (f[s+s+1].mn.first <= f[s+s].mn.first)
        f[s] = f[s+s+1];
    else
        f[s] = f[s+s];
}
void down(int l, int r, int s) {
    if (f[s].tag) {
        f[s].v += f[s].tag;
        f[s].mn.first += f[s].tag;
        if (l!=r) f[s+s].tag += f[s].tag, f[s+s+1].tag += f[s].tag;
        f[s].tag = 0;
    }
}
void build(int l, int r, int s) {
    if (l == r) {
        if (sig[l])
            f[s].mn = {v[l - 1] - a[l], l};
        else
            f[s].mn = {1000000, l};
        f[s].v = v[l];
        return;
    }
    build(l, (l + r) / 2, s + s);
    build((l + r) / 2 + 1, r, s + s + 1);
    upd(s);
}
void del(int l, int r, int s, int ll) {
    down(l, r, s);
    if (l == r) {
        f[s].mn.first = 1000000;
        return;
    }
    if ((l + r) / 2 >= ll) del(l, (l + r) / 2,  s + s, ll), down((l + r) / 2 + 1, r, s + s+ 1);
    else del((l + r) / 2 + 1, r, s + s + 1, ll), down(l, (l + r) / 2, s + s);
    upd(s);
}
void add(int l, int r, int s, int ll, int rr, int v) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        f[s].tag += v;
        down(l ,r, s);
        return;
    }
    add(l, (l + r) / 2, s + s ,ll , rr, v);
    add((l + r) / 2 + 1, r, s + s + 1, ll, rr, v);
    upd(s);
}
node get(int l, int r, int s, int ll) {
    while (1) {
        down(l, r, s);
        if (l == r) return f[s];
        if ((l + r) / 2 >= ll) r = (l + r) / 2, s += s;
        else
            l = (l + r)  /2 + 1, s += s + 1;
    }
}
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
        a[i] = i - a[i];
        if (a[i] >= 0 && a[i] <= v[i - 1]) {
            sig[i] = 1;
            v[i] = v[i-1]+1;
        } else v[i] = v[i - 1];
    }
    build(1, n, 1);
    for (int i = 1; i <= q; i ++) {
        scanf("%d %d", &w[i].first.first, &w[i].first.second);
        w[i].first.first ++;
        w[i].first.second = n - w[i].first.second;
        w[i].second = i;
    }
    sort(w+1, w + q + 1);
    int l = 1;
    for (int i = 1; i <= q; i ++) {
        while (l < w[i].first.first) {
            auto v = get(1, n, 1, l);
            if (v.mn.first == 0) {
                while (!f[1].mn.first && f[1].mn.second != l) {
                    auto u = f[1].mn;
                    add(1, n, 1, u.second, n, -1);
                    del(1, n, 1, u.second);
                }
                add(1, n, 1, l, n, -1);
                del(1, n, 1, l);
            }
            ++l;
        }
        ans[w[i].second] = get(1, n, 1, w[i].first.second).v;
    }
    for (int i= 1; i <= q; i ++)
        printf("%d\n",ans[i]);
    return 0;
}