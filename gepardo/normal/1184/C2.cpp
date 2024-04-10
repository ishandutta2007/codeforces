#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int NORM = 2000001;
const int M = NORM * 2;
map<int, vector<int>> ev;
int n, r;
int tr[M * 4];
int ps[M * 4];

void push(int v) {
    for (int j = 0; j < 2; j++) {
        tr[v * 2 + j] += ps[v];
        ps[v * 2 + j] += ps[v];
    }
    ps[v] = 0;
}

void md(int v, int l, int r, int ll, int rr, int add) {
    if (ps[v] != 0) {
        if (l < r) {
            push(v);
        }
    }
    if (ll <= l && r <= rr) {
        tr[v] += add;
        ps[v] += add;
        return;
    }
    int mid = (r + l) / 2;
    if (ll <= mid) {
        md(v * 2, l, mid, ll, rr, add);
    }
    if (rr > mid) {
        md(v * 2 + 1, mid + 1, r, ll, rr, add);
    }
    tr[v] = max(tr[v * 2], tr[v * 2 + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> r;
    r *= 2;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int nx = x - y;
        int ny = x + y;
        nx += NORM;
        ny += NORM;
        ev[nx].push_back(ny);
    }
    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (ev.find(i - r - 1) != ev.end()) {
            for (auto y : ev[i - r - 1]) {
                md(1, 1, M, max(y - r, 1), y, -1);
            }
        }
        if (ev.find(i) == ev.end()) {
            continue;
        }
        const auto& v = ev[i];
        for (auto y : v) {
            md(1, 1, M, max(y - r, 1), y, 1);
        }
        ans = max(ans, tr[1]);
    }
    cout << ans << "\n";
    return 0;
}