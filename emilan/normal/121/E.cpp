#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

const int maxn = 1 << 17, maxm = 2e4 + 5;
int lucky[] = {
    4, 7,
    44, 47, 74, 77,
    444, 447, 474, 477, 744, 747, 774, 777,
    4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777,
    7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777,
    2'000'000'000
};
int next_event[maxm];

int a[maxn << 1], a_lz[maxn];
int dist[maxn << 1];
int cnt[maxn << 1];

bool is_lucky(int x) {
    return x > 3 && next_event[x - 1] == x && next_event[x] == x + 1;
}

void fix(int i);

void app(int i, int d) {
    dist[i] += d;
    if (i < maxn) a_lz[i] += d;
    else a[i] += d;
    fix(i);
}

void fix(int i) {
    if (dist[i] < 0) return;

    if (i < maxn) {
        int l = i << 1, r = l | 1;

        app(l, a_lz[i]);
        app(r, a_lz[i]);
        a_lz[i] = 0;

        dist[i] = max(dist[l], dist[r]);
        cnt[i] = cnt[l] + cnt[r];
    } else {
        dist[i] = a[i] - next_event[a[i]];
        cnt[i] = is_lucky(a[i]);
    }
}

void build(int i) {
    while (i >>= 1) {
        int l = i << 1, r = l | 1;

        if (l < maxn) {
            dist[i] = max(dist[l], dist[r]) + a_lz[i];
        } else {
            dist[i] = max(
                a[l] - next_event[a[l]],
                a[r] - next_event[a[r]]
            ) + a_lz[i];
        }
        
        cnt[i] = cnt[l] + cnt[r];
    }
}

void push(int i) {
    for (int s = __lg(i); s; s--) {
        int p = i >> s;
        app(p << 1, a_lz[p]);
        app(p << 1 | 1, a_lz[p]);
        a_lz[p] = 0;
    }
}

int query(int l, int r) {
    int ret = 0;
    for (l += maxn, r += maxn; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ret += cnt[l++];
        if (r & 1) ret += cnt[--r];
    }

    return ret;
}

void update(int l, int r, int d) {
    int l0 = l += maxn, r0 = r += maxn;
    push(l0);
    push(r0 - 1);

    for (; l < r; l >>= 1, r >>= 1) {
        if (l & 1) app(l++, d);
        if (r & 1) app(--r, d);
    }

    build(l0);
    build(r0 - 1);
}

void solve() {
    for (int i = 0, p = 0; i < maxm; i++) {
        if (i == lucky[p]) next_event[i] = lucky[p++] + 1;
        else next_event[i] = lucky[p];
    }

    fill_n(dist, maxn << 1, -4);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        update(i, i + 1, x);
    }

    while (q--) {
        string t;
        int l, r;
        cin >> t >> l >> r;

        if (t == "add") {
            int d;
            cin >> d;

            update(--l, r, d);
        } else {
            cout << query(--l, r) << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}