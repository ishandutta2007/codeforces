#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, q;
char s[100010];
struct node {
    int a[3][3];
} qwq[3], t[400010];
node operator * (const node &a, const node &b) {
    node ans;
    memset(&ans, 0x3f, sizeof ans);
    for (int i = 0; i < 3; i++)
        for (int j = i; j < 3; j++)
            for (int k = 0; k < 3; k++) ans.a[i][k] = min(ans.a[i][k], a.a[i][j] + b.a[j][k]);
    return ans;
}
inline void build(int x, int l, int r) {
    if (l == r) return t[x] = qwq[s[l] - 'a'], void();
    int mid = l + r >> 1;
    build(x << 1, l, mid);
    build(x << 1 | 1, mid + 1, r);
    t[x] = t[x << 1] * t[x << 1 | 1];
}
inline void modify(int x, int l, int r, int k) {
    if (l == r) return t[x] = qwq[s[l] - 'a'], void();
    int mid = l + r >> 1;
    if (k <= mid) modify(x << 1, l, mid, k);
    else modify(x << 1 | 1, mid + 1, r, k);
    t[x] = t[x << 1] * t[x << 1 | 1];
}
int main() {
    qwq[0] = {
        1, 0, 0,
        inf, 0, 0,
        inf, inf, 0
    };
    qwq[1] = {
        0, 0, 0,
        inf, 1, 0,
        inf, inf, 0
    };
    qwq[2] = {
        0, 0, 0,
        inf, 0, 0,
        inf, inf, 1
    };
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    build(1, 1, n);
    for (int i = 1; i <= q; i++) {
        int pos;
        char v[5];
        scanf("%d%s", &pos, v);
        s[pos] = v[0];
        modify(1, 1, n, pos);
        printf("%d\n", t[1].a[0][2]);
    }
}