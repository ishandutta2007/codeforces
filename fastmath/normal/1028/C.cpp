#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 7;
const int INF = 1e9 + 7;

struct Pr {
    int l1, r1, l2, r2;
};

int n;
Pr a[MAXN];

void check(int del) {
    int tl1 = -INF, tr1 = INF, tl2 = -INF, tr2 = INF;
    for (int i = 0; i < n; ++i) {
        if (i == del) continue;
        tl1 = max(tl1, a[i].l1);
        tr1 = min(tr1, a[i].r1);
        tl2 = max(tl2, a[i].l2);
        tr2 = min(tr2, a[i].r2);
    }
    if (tl1 <= tr1 && tl2 <= tr2) {
        cout << tl1 << ' ' << tl2 << '\n';
        exit(0);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].l1 >> a[i].l2 >> a[i].r1 >> a[i].r2;

    int bl1 = 0, br1 = 0, bl2 = 0, br2 = 0;
    for (int i = 0; i < n; ++i) {
        if (a[bl1].l1 < a[i].l1) bl1 = i;
        if (a[br1].r1 > a[i].r1) br1 = i;
        if (a[bl2].l2 < a[i].l2) bl2 = i;
        if (a[br2].r2 > a[i].r2) br2 = i;
    }

    check(bl1); check(br1); check(bl2); check(br2);
    return 0;
}