#include <bits/stdc++.h>
using namespace std;
struct node {
    int l, r, len;
    inline int operator < (const node &b) const {
        return l < b.l;
    }
} nd[200010];
int a[200010], b[200010];
int n;
int main() {
    scanf("%d%*d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", a + i), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    int cnt = unique(b + 1, b + 1 + n) - b - 1;
    for(int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + 1 + cnt, a[i]) - b;
        if(nd[a[i]].l == 0) nd[a[i]].l = i;
        nd[a[i]].r = i;
        nd[a[i]].len += 1;
    }
    sort(nd + 1, nd + 1 + cnt);
    int ans = 0;
    for(int l = 1, r; l <= cnt; l = r + 1) {
        int _max = nd[l].r;
        for(r = l; r < cnt && nd[r + 1].l <= _max; r++) _max = max(_max, nd[r + 1].r);
        int d = 0;
        for(int i = l; i <= r; i++) ans += nd[i].len, d = max(d, nd[i].len);
        ans -= d;
    }
    return cout << ans << endl, 0;
}