#include <bits/stdc++.h>

using namespace std;

using node = array<int, 3>;

const int N = 1e6;
node st[N << 1];

node Merge(node &x, node &y) {
    int m = min(x[1], y[2]);
    return {x[0] + y[0] + m * 2, x[1] + y[1] - m, x[2] + y[2] - m};
}

int query(int l, int r) {
    node L{}, R{};
    for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
        if (l & 1) L = Merge(L, st[l++]);
        if (r & 1) R = Merge(st[--r], R);
    }

    return Merge(L, R)[0];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string s;
    int q;
    cin >> s >> q;

    int n = s.size();
    for (int i = 0; i < n; i++) {
        st[i + N] = {0, s[i] == '(', s[i] == ')'};
    }
    for (int i = N - 1; i > 0; i--) {
        st[i] = Merge(st[i << 1], st[i << 1 | 1]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(--l, r) << '\n';
    }
}