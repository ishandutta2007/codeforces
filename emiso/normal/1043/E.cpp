#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, x[300030], y[300030], d[300030];

vector<int> ys;
ll bit[3][300030]; // 0 - count, 1 - x, 2 - y

void upd(int t, int idx, ll delta) {
    for(; idx < 300030; idx += (idx & -idx)) bit[t][idx] += delta;
}

ll query(int t, int idx) {
    ll ret = 0;
    for(; idx; idx -= (idx & -idx)) ret += bit[t][idx];
    return ret;
}

ll ans[300030];

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        ys.push_back(x[i] - y[i]);
    }

    sort(ys.begin(), ys.end());
    ys.resize(unique(ys.begin(), ys.end()) - ys.begin());

    for(int i = 1; i <= n; i++) {
        d[i] = lower_bound(ys.begin(), ys.end(), x[i] - y[i]) - ys.begin() + 1;
        upd(0, d[i], 1);
        upd(1, d[i], x[i]);
        upd(2, d[i], y[i]);
    }

    for(int i = 1; i <= n; i++) {
        ans[i] += 1LL * y[i] * query(0, d[i]);
        ans[i] += query(1, d[i]);

        ans[i] += 1LL * x[i] * (query(0, 300001) - query(0, d[i]));
        ans[i] += (query(2, 300001) - query(2, d[i]));
    }

    //edge i-i
    for(int i = 1; i <= n; i++) {
        ans[i] -= (x[i] + y[i]);
    }

    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        ll mini = min(x[a] + y[b], y[a] + x[b]);
        ans[a] -= mini;
        ans[b] -= mini;
    }

    for(int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }
}