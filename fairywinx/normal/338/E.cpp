#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

const int N = (1 << 18);

int t[2 * N];
int mod[2 * N];

int m;

void build(int v, int l, int r) {
    if (r - l == 1) {
        t[v] = -l - 1;
        return;
    }

    int m = (l + r) / 2;
    build(v * 2 + 1, l, m);
    build(v * 2, m, r);
    t[v] = min(t[v * 2 + 1], t[v * 2]);
}

void update(int v, int l, int r, int L, int R, int val) {
    if (r <= L || R <= l)
        return;
    if (L <= l && r <= R) {
        t[v] += val;
        mod[v] += val;
        return;
    }

    int m = (l + r) / 2;
    update(v * 2 + 1, l, m, L, R, val);
    update(v * 2, m, r, L, R, val);
    t[v] = min(t[v * 2 + 1], t[v * 2]) + mod[v];
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, h;
    cin >> n >> m >> h;
    vector<int> a(n), b(m);
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    sort(all(b));
    build(1, 0, m);
    for (int i = 0; i < m; ++i) {
        update(1, 0, m, lower_bound(all(b), h - a[i]) - b.begin(), m, 1);
    }
    int ans = (t[1] >= 0 ? 1 : 0);
    for (int i = m; i < n; ++i) {
        update(1, 0, m, lower_bound(all(b), h - a[i]) - b.begin(), m, 1);
        update(1, 0, m, lower_bound(all(b), h - a[i - m]) - b.begin(), m, -1);
        ans += (t[1] >= 0 ? 1 : 0);
    }
    cout << ans << '\n';
}