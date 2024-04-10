#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int T, n, q, tot, a[maxn], rt[maxn];
vector<int> V;
struct node { int l, r, s; } t[maxn * 35];

#define mid ((l + r) >> 1)
void ins(int &k1, int k2, int l, int r, int p) {
    t[k1 = ++tot] = t[k2], t[k1].s++;
    if (l == r) return;
    if (mid >= p) ins(t[k1].l, t[k2].l, l, mid, p);
    else ins(t[k1].r, t[k2].r, mid + 1, r, p);
}

void query(int k1, int k2, int l, int r) {
    if (t[k1].s == t[k2].s || V.size() > 35) return;
    if (l == r) {
        for (int i = 0; i < t[k1].s - t[k2].s; i++) {
            V.push_back(l);
            if (V.size() > 35) break;
        }
        return;
    }
    query(t[k1].l, t[k2].l, l, mid);
    query(t[k1].r, t[k2].r, mid + 1, r);
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n), tot = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ins(rt[i], rt[i - 1], 0, (1 << 30) - 1, a[i]);
        }
        scanf("%d", &q);
        while (q--) {
            int l, r;
            scanf("%d %d", &l, &r);
            V.clear(), query(rt[r], rt[l - 1], 0, (1 << 30) - 1);
            int ans = INT_MAX;
            for (int i = 0; i < V.size(); i++) {
                for (int j = i + 1; j < V.size(); j++) {
                    ans = min(ans, V[i] | V[j]);
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}