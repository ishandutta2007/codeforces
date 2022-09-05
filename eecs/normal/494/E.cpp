#include <bits/stdc++.h>
using namespace std;

const int maxn = 50010;
int n, m, K;
struct rect { int a, b, c, d; } a[maxn], b[maxn];

namespace SEG {
#define mid (l + r >> 1)
int tot;
struct node { int l, r, cnt; bool ans; } t[maxn * 50];

void init() {
    for (int i = 1; i <= tot; i++) t[i].l = t[i].r = 0;
    tot = 0;
}

void maintain(int k, int l, int r) {
    t[k].ans = t[k].cnt ? (r - l + 1) & 1 : (t[t[k].l].ans ^ t[t[k].r].ans);
}

void add(int &k, int l, int r, int ql, int qr, int v) {
    if (!k) k = ++tot;
    if (l >= ql && r <= qr) { t[k].cnt += v, maintain(k, l, r); return;  }
    if (mid >= ql) add(t[k].l, l, mid, ql, qr, v);
    if (mid < qr) add(t[k].r, mid + 1, r, ql, qr, v);
    maintain(k, l, r);
}
}  // namespace SEG

int main() {
    scanf("%d %d %d", &n, &m, &K);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &a[i].a, &a[i].b, &a[i].c, &a[i].d);
    }
    auto chk = [&]() {
        vector<tuple<int, int, int, int>> V;
        int ans = 0, rt = 0, n = 0;
        for (int i = 1; i <= m; i++) if (b[i].a <= b[i].c && b[i].b <= b[i].d) {
            n = max(n, b[i].d), V.emplace_back(b[i].a, b[i].b, b[i].d, 1);
            V.emplace_back(b[i].c + 1, b[i].b, b[i].d, -1);
        }
        sort(V.begin(), V.end()), SEG::init();
        for (int i = 0, j; i < V.size(); i = j) {
            for (j = i; j < V.size() && get<0>(V[i]) == get<0>(V[j]); j++) {
                SEG::add(rt, 1, n, get<1>(V[j]), get<2>(V[j]), get<3>(V[j]));
            }
            if (j == V.size() || !((get<0>(V[j]) - get<0>(V[i])) & 1)) continue;
            ans ^= SEG::t[1].ans;
        }
        return ans;
    };
    for (int i = 0; 1 << i <= K; i++) {
        copy(a + 1, a + m + 1, b + 1);
        for (int j = 1; j <= m; j++) {
            b[j].a = ((b[j].a - 1) >> i) + 1, b[j].c >>= i;
            b[j].b = ((b[j].b - 1) >> i) + 1, b[j].d >>= i;
        }
        if (chk()) puts("Hamed"), exit(0);
    }
    puts("Malek");
    return 0;
}