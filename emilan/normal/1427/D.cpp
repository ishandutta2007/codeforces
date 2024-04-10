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

void solve() {
    int n;
    cin >> n;
    vt<int> a(n);
    for (int &x : a) cin >> x;

    vt<vt<int>> ops(n / 2 * 2);
    auto operate = [&](vt<int> &o) {
        int p = n;
        vt<int> b;
        for (int x : vt<int>(rall(o))) {
            b.insert(b.end(), a.begin() + p - x, a.begin() + p);
            p -= x;
        }
        a = b;
    };
    for (int i = 0; i < n / 2 * 2; i++) {
        if (~i & 1) {
            int p1 = (int)distance(a.begin(), find(all(a), i + 1)),
                p2 = (int)distance(a.begin(), find(all(a), i + 2));

            ops[i].insert(ops[i].end(), i, 1);

            if (p1 < p2) {
                ops[i].push_back(p1 - i + 1);
                if (p1 != p2 - 1) ops[i].push_back(p2 - p1 - 1);
                ops[i].push_back(n - p2);
            } else {
                ops[i].push_back(p1 - i + 1);
                if (p1 != n - 1) ops[i].push_back(n - p1 - 1);
            }
        } else {
            int p = (int)distance(a.begin(), find(all(a), i + 1));
            if (p) ops[i].push_back(p);
            ops[i].push_back(n - p - i);
            ops[i].insert(ops[i].end(), i, 1);
        }

        operate(ops[i]);
    }

    int len = 0;
    for (auto &op : ops) {
        if (sz(op) > 1) len++;
    }
    cout << len << '\n';
    for (auto &op : ops) {
        if (sz(op) > 1) {
            cout << sz(op);
            for (int x : op) cout << ' ' << x;
            cout << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}