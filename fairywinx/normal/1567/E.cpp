#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

const int N = (1 << 18);

array<long long, 3> t[2 * N];
array<long long, 3> mod[2 * N];

array<long long, 3> merge(array<long long, 3> a, array<long long, 3> b) {
    return {a[0] + b[0], min(a[1], b[1]), max(a[2], b[2])};
}

void push(int v, int l, int r) {
    if (mod[v][0] == -1)
        return;
    int m = (l + r) / 2;
    mod[v * 2 + 1] = mod[v];
    mod[v * 2] = mod[v];
    t[v * 2 + 1] = mod[v];
    t[v * 2] = mod[v];
    t[v * 2 + 1][0] = 1ll * mod[v][0] * (m - l);
    t[v * 2][0] = 1ll * mod[v][0] * (r - m);
    mod[v][0] = -1;
}

void update(int v, int l, int r, int L, int R, array<long long, 3> val) {
    if (r <= L || R <= l)
        return;
    if (L <= l && r <= R) {
        t[v] = val;
        t[v][0] = 1ll * val[0] * (r - l);
        mod[v] = val;
        return;
    }

    int m = (l + r) / 2;
    push(v, l, r);
    update(v * 2 + 1, l, m, L, R, val);
    update(v * 2, m, r, L, R, val);
    t[v] = merge(t[v * 2 + 1], t[v * 2]);
}

array<long long, 3> get(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l)
        return {0, (int) 1e9 + 228, 0};
    if (L <= l && r <= R)
        return t[v];

    push(v, l, r);
    int m = (l + r) / 2;
    return merge(get(v * 2 + 1, l, m, L, R), get(v * 2, m, r, L, R));
}

int n;

void update(int l, int r, array<long long, 3> val) {
    // cout << l << ' ' << r << ' ' << val[0] << '\n';
    update(1, 0, n, l, r, val);
}

array<long long, 3> get(int l, int r) {
    // cout << l << ' ' << r << ':';
    auto z = get(1, 0, n, l, r);
    // cout << z[0] << ' ' << z[1] << ' ' << z[2] << '\n';
    return z;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q;
    cin >> n >> q;
    vector<int> a(n);
    int lst = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && a[i] < a[i - 1]) {
            int len = i - lst;
            update(lst, i, {len + 1, lst, i});
            lst = i;
        }
    }
    update(lst, n, {n - lst + 1, lst, n});

    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            --x;

            if (x != n - 1) {
                if (a[x] <= a[x + 1] && y > a[x + 1]) {
                    auto z = get(x, x + 1);
                    update(z[1], x + 1, {x + 1 - z[1] + 1, z[1], x + 1});
                    update(x + 1, z[2], {z[2] - x - 1 + 1, x + 1, z[2]});
                } else if (a[x] > a[x + 1] && y <= a[x + 1]) {
                    auto z = get(x + 1, x + 2);
                    auto z1 = get(x, x + 1);
                    update(z1[1], z[2], {z[2] - z1[1] + 1, z1[1], z[2]});
                }
            }
            if (x != 0) {
                if (a[x - 1] <= a[x] && y < a[x - 1]) {
                    auto z = get(x - 1, x);
                    update(z[1], x, {x - z[1] + 1, z[1], x});
                    update(x, z[2], {z[2] - x + 1, x, z[2]});
                } else if (a[x - 1] > a[x] && y >= a[x - 1]) {
                    auto z = get(x - 1, x);
                    auto z1 = get(x, x + 1);
                    update(z[1], z1[2], {z1[2] - z[1] + 1, z[1], z1[2]});
                }
            }

            a[x] = y;
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            auto z = get(l, r);
            auto z1 = get(l, l + 1), z2 = get(r - 1, r);
            if (z1[1] == z2[1]) {
                cout << 1ll * (r - l) * (r - l + 1) / 2 << '\n';
                continue;
            }
            long long ans = z[0] - (z1[2] - l) * z1[0] - (r - z2[1]) * z2[0];
            ans += 1ll * (z1[2] - l) * (z1[2] - l + 1) + 1ll * (r - z2[1]) * (r - z2[1] + 1);
            cout << ans / 2 << '\n';
        }
    }
}