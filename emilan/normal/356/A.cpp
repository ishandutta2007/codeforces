#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;

const int N = 3e5 + 1;
const pii NIL{N, 0};

pii st[2 * N];

void touch(int i, pii u) {
    st[i] = min(st[i], u);
}

int query(int i) {
    pii r(NIL);
    for (i += N; i > 0; i /= 2) {
        r = min(r, st[i]);
    }
    return r.second;
}

void update(int l, int r, pii u) {
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) touch(l++, u);
        if (r & 1) touch(--r, u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    fill_n(st, 2 * N, NIL);
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        update(l, x, {i, x});
        update(x + 1, r + 1, {i, x});
    }

    for (int i = 1; i <= n; i++) {
        cout << query(i) << " \n"[i == n];
    }
}