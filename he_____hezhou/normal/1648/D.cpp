#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll a[3][500010];
int n, q;
struct pqnode {
    priority_queue < ll > pq1, pq2;
    void add(ll x) {
        pq1.push(x);
    }
    void rmv(ll x) {
        pq2.push(x);
        while (pq2.size() && pq1.top() == pq2.top()) pq1.pop(), pq2.pop();
    }
    ll top() {
        return pq1.top();
    }
    int empty() {
        return pq1.empty();
    }
} t[2000010];
ll v1[2000010], v2[2000010];
void up(int x) {
    v2[x] = max(v2[x << 1], v2[x << 1 | 1]);
    v1[x] = max(v1[x << 1], v1[x << 1 | 1]);
    if (!t[x].empty()) v1[x] = max(v1[x], v2[x] + t[x].top());
}
void modify(int x, int l, int r, int k, ll v) {
    if (l == r) {
        v2[x] = v;
        v1[x] = t[x].empty() ? -inf : v2[x] + t[x].top();
        return;
    }
    int mid = l + r >> 1;
    if (k <= mid) modify(x << 1, l, mid, k, v);
    else modify(x << 1 | 1, mid + 1, r, k, v);
    up(x);
}
void addseg(int x, int l, int r, int L, int R, ll v) {
    if (l > R || L > r) return;
    if (L <= l && r <= R) {
        t[x].add(v);
        v1[x] = t[x].empty() ? -inf : v2[x] + t[x].top();
        return;
    }
    int mid = l + r >> 1;
    addseg(x << 1, l, mid, L, R, v);
    addseg(x << 1 | 1, mid + 1, r, L, R, v);
    up(x);
}
void rmvseg(int x, int l, int r, int L, int R, ll v) {
    if (l > R || L > r) return;
    if (L <= l && r <= R) {
        t[x].rmv(v);
        if (l == r) v1[x] = t[x].empty() ? -inf : v2[x] + t[x].top();
        else up(x);
        return;
    }
    int mid = l + r >> 1;
    rmvseg(x << 1, l, mid, L, R, v);
    rmvseg(x << 1 | 1, mid + 1, r, L, R, v);
    up(x);
    // cerr << x << ' ' << l << ' ' << r << ' ' << v1[x] << ' ' << v2[x] << endl;
}
vector < pair < int, int > > dlt[500010];
int main() {
    scanf("%d%d", &n, &q);
    memset(v1, ~0x3f, sizeof v1);
    memset(v2, ~0x3f, sizeof v2);
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j <= n; j++) scanf("%lld", &a[i][j]), a[i][j] += a[i][j - 1];
    }
    for (int i = 1; i <= q; i++) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        addseg(1, 0, n, l - 1, n, -k);
        dlt[r].emplace_back(l - 1, -k);
    }
    ll ans = -inf;
    for (int i = 0; i <= n; i++) {
        ll cur = a[0][i + 1] - a[1][i];
        cur = max(cur, v1[1]);
        // cerr << cur << ' ' << v1[1] << ' ' << a[1][i] << ' ' << a[2][n] - a[2][i - 1] << endl;
        if (i) ans = max(ans, v1[1] + a[1][i] + a[2][n] - a[2][i - 1]);
        modify(1, 0, n, i, cur);
        for (auto j : dlt[i]) {
            // cerr << "rmv " << j.first << ' ' << j.second << endl;
            rmvseg(1, 0, n, j.first, n, j.second);
        }
    }
    cout << ans << endl;
}