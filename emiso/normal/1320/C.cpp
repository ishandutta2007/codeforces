#include <bits/stdc++.h>

#define MN 201000

using namespace std;
typedef long long ll;

int n, m, p, a[MN], ca[MN], b[MN], cb[MN], x[MN], y[MN], z[MN];

vector<int> evs[1000100];
ll minirow[1000100], minicol[1000100], ans = INT_MIN;

ll tree[4000040], lazy[4000040];

void dolazy(int id, int l, int r) {
    if(lazy[id]) {
        tree[id] += lazy[id];
        if(l != r) {
            lazy[id*2] += lazy[id];
            lazy[id*2+1] += lazy[id];
        }
        lazy[id] = 0;
    }
}

void build(int id, int l, int r) {
    if(l == r) {
        tree[id] = -minicol[l+1];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    tree[id] = max(tree[id*2], tree[id*2+1]);
}

ll query(int id, int l, int r) {
    dolazy(id, l, r);
    return tree[id];
}

void update(int id, int l, int r, int x, int y, int delta) {
    dolazy(id, l, r);
    if(x > y || y < l || r < x) return;
    if(x <= l && r <= y) {
        lazy[id] += delta;
        dolazy(id, l, r);
    } else {
        int m = (l + r) / 2;
        update(id * 2,       l, m, x, y, delta);
        update(id * 2 + 1, m+1, r, x, y, delta);
        tree[id] = max(tree[id*2], tree[id*2+1]);
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &p);

    for(int i = 0; i < 1000100; i++) {
        minirow[i] = minicol[i] = 1000000000000LL;
    }

    for(int i = 0; i < n; i++) {
        scanf("%d %d", &a[i], &ca[i]);
        minirow[a[i]] = min(minirow[a[i]], (ll)ca[i]);
    }
    for(int i = 0; i < m; i++) {
        scanf("%d %d", &b[i], &cb[i]);
        minicol[b[i]] = min(minicol[b[i]], (ll)cb[i]);
    }
    for(int i = 0; i < p; i++) {
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
        evs[x[i]].push_back(i);
    }

    for(int i = 1000010; i >= 0; i--) {
        minicol[i] = min(minicol[i+1], minicol[i]);
        minirow[i] = min(minirow[i+1], minirow[i]);
    }
    ans = -(minirow[0] + minicol[0]);

    build(1, 1, 1000010);

    for(int i = 0; i < 1000010; i++) {
        for(int id : evs[i]) {
            update(1, 1, 1000010, y[id], 1000010, z[id]);
        }

        if(!evs[i].empty()) {
            ans = max(ans, query(1, 1, 1000010) - minirow[i+1]);
        }
    }

    printf("%lld\n", ans);
    return 0;
}