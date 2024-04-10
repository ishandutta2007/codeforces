#include <bits/stdc++.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
const ll inf = 1e18 + 50;
int n, K, nx[N];
ll g[N], w[N], pre[N], suf[N], out, maxp[N * 4], minc[N * 4], ans[N * 4];
ll fz[N * 4];
ll tag[N * 4];
vector<int> to[N];
stack<pair<ll, int>> S;
void build_tree() {
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + g[i] - w[i - 1];
        suf[i] = suf[i - 1] + g[i] - w[i];
    }
    S.push(make_pair(0, 0));
    for (int i = 1; i < n; i++) {
        while (S.size() && S.top().first > suf[i]) {
            nx[S.top().second + 1] = i + 1;
            to[i + 1].push_back(S.top().second + 1);
            S.pop();
        }
        S.push(make_pair(suf[i], i));
    }
}
void putag(int x, ll v) {
    tag[x] += v;
    maxp[x] += v;
    ans[x] += v;
}

void down(int x) {
    if (tag[x] != 0) {
        putag(x << 1, tag[x]), putag(x << 1 | 1, tag[x]);
        tag[x] = 0;
    }
}

void calc(int x, int l, int r, ll pre_mx, ll &ret) {
    if (l == r) {
        ret = min(ret, minc[x] + pre_mx);
        return;
    }
    down(x);
    if (pre_mx >= maxp[x << 1]) {
        ret = min(ret, pre_mx + minc[x << 1]);
        calc(x << 1 | 1, (l + r >> 1) + 1, r, pre_mx, ret);
    } else {
        ret = min(ret, ans[x << 1 | 1]);
        calc(x << 1, l, l + r >> 1, pre_mx, ret);
    }
}

void update(int x, int l, int r) {
    maxp[x] = max(maxp[x << 1], maxp[x << 1 | 1]);
    fz[x] = fz[x << 1] + fz[x << 1 | 1];
    ans[x] = inf;
    calc(x << 1 | 1, (l + r >> 1) + 1, r, maxp[x << 1], ans[x]);
}

void build(int x, int l, int r) {
    if (l == r) {
        maxp[x] = pre[l];
        minc[x] = -pre[l];
        return;
    }
    build(x << 1, l, l + r >> 1);
    build(x << 1 | 1, (l + r >> 1) + 1, r);
    update(x, l, r);
    minc[x] = min(minc[x << 1], minc[x << 1 | 1]);
}

int LE;
void erfen(int x, int l, int r, ll pre_mx) {
    if (l == r) {
        if (pre_mx + minc[x] <= K)
            out = max(out, r - LE + 1);
        return;
    }
    down(x);
    if (minc[x << 1 | 1] + pre_mx <= K) {
        erfen(x << 1 | 1, (l + r >> 1) + 1, r, pre_mx);
    } else {
        erfen(x << 1, l, l + r >> 1, pre_mx);
    }
}

void _query(int x, int l, int r, ll pre_mx) {
    if (l == r) {
        if (pre_mx + minc[x] <= K) {
            out = max(out, r - LE + 1);
        }
        return;
    }
    down(x);
    if (pre_mx >= maxp[x << 1]) {
        erfen(x << 1, l, l + r >> 1, pre_mx);
        _query(x << 1 | 1, (l + r >> 1) + 1, r, pre_mx);
    } else {
        if (ans[x] <= K) {
            _query(x << 1 | 1, (l + r >> 1) + 1, r, maxp[x << 1]);
        } else {
            _query(x << 1, l, l + r >> 1, pre_mx);
        }
    }
}

void query(int x, int l, int r, int tl, int tr, ll &pre_mx) {
    if (tl <= l && r <= tr) {
        _query(x, l, r, pre_mx);
        pre_mx = max(pre_mx, maxp[x]);
        return;
    }
    if (l > tr || r < tl)
        return;
    down(x);
    query(x << 1, l, l + r >> 1, tl, tr, pre_mx);
    query(x << 1 | 1, (l + r >> 1) + 1, r, tl, tr, pre_mx);
}

void pre_change(int x, int l, int r, int tl, int tr, ll v) {
    if (tl <= l && r <= tr) {
        putag(x, v);
        return;
    }
    if (l > tr || r < tl)
        return;
    down(x);
    pre_change(x << 1, l, l + r >> 1, tl, tr, v);
    pre_change(x << 1 | 1, (l + r >> 1) + 1, r, tl, tr, v);
    update(x, l, r);
}

void fz_change(int x, int l, int r, int tg, ll v) {
    if (l == r) {
        fz[x] += v;
        return;
    }
    if (tg <= (l + r >> 1)) {
        fz_change(x << 1, l, l + r >> 1, tg, v);
    } else
        fz_change(x << 1 | 1, (l + r >> 1) + 1, r, tg, v);
    fz[x] = fz[x << 1] + fz[x << 1 | 1];
}

void find(int x, int l, int r, int rest, int &ri) {
    if (l == r) {
        if (rest >= fz[x])
            ri = r;
        return;
    }
    down(x);
    if (rest >= fz[x << 1]) {
        ri = l + r >> 1;
        find(x << 1 | 1, (l + r >> 1) + 1, r, rest - fz[x << 1], ri);
    } else {
        find(x << 1, l, l + r >> 1, rest, ri);
    }
}

void dfs(int x) {
    LE = x;
    ll tmp = -inf;
    int ri = 0;
    find(1, 1, n, K, ri);
    query(1, 1, n, x, ri + 1, tmp);
    for (int y : to[x]) {
        ll d = suf[y - 1] - suf[x - 1];
        pre_change(1, 1, n, x - 1, n, d);
        fz_change(1, 1, n, x - 1, d);
        dfs(y);
        pre_change(1, 1, n, x - 1, n, -d);
        fz_change(1, 1, n, x - 1, -d);
    }
}

int main() {
    cin >> n >> K;
    for (int i = 1; i < n; i++) scanf("%lld", &w[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &g[i]);
    build_tree();
    build(1, 1, n);
    while (S.size()) {
        dfs(S.top().second + 1);
        S.pop();
    }
    cout << out << endl;
}