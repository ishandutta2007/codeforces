#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <unordered_map>
using namespace std;
const int N = 1e6;
struct node{
    int mx, mn, all;
    int tag;
}f[N * 4  +100];
int n;
int a[N + 100];
void down(int l, int r, int s) {
    if (f[s].tag) {
        f[s].mx += f[s].tag;
        f[s].mn += f[s].tag;
        f[s].all += f[s].tag;
        if (l != r) {
            f[s+s].tag += f[s].tag;
            f[s+s+1].tag += f[s].tag;
        }
        f[s].tag = 0;
    }
}
void combine(node&a, const node&b, const node&c) {
    a.all = b.all + c.all;
    a.mx = max(b.mx, c.mx + b.all);
    a.mn = min(b.mn, c.mn + b.all);

}
void ins(int l, int r, int s, int ll, int rr, int v) {
    down(l, r, s);
    if (r < ll || rr < l) return;
    if (ll <= l && r <= rr) {
        f[s].tag += v;
        down(l, r, s);
        return;
    }
    ins(l, (l + r) / 2, s + s, ll, rr, v);
    ins((l + r)/ 2 + 1, r, s + s + 1, ll, rr, v);
    combine(f[s], f[s+s], f[s+s+1]);
}
void del(int x) {
    if (a[x] == 1)
        ins(1, N, 1, x, x, -1);
    else
        if (a[x] == -1)
            ins(1, N, 1, x, x, 1);
}
int main() {
    scanf("%d", &n);
    int x = 1;
    while (n --) {
        char c;
        scanf(" %c", &c);
        if (c == '(') {
            del(x);
            a[x] = 1;
            ins(1, N, 1, x, x, 1);
        } else
            if (c == ')') {
                del(x);
                ins(1, N, 1, x, x, -1);
                a[x] = -1;
            } else
                if (c == 'R') {
                    x ++;
                } else
                    if (c == 'L') {
                        if (x > 1) x --;
                    } else {
                        del(x);
                        a[x] = 0;
                    }
        if (f[1].all != 0 || f[1].mn < 0)
            printf("-1 ");
        else
            printf("%d ", f[1].mx);
    }
    return 0;
}