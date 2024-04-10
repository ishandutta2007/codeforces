#include <bits/stdc++.h>
using namespace std;
using LL = long long;
struct BIT{
    int n;
    vector<int> c, s;
    BIT(int n) : n(n), c(n + 1), s(n + 1) {}
    int sum(int x) {
        int res = 0;
        for (; x; x -= x & -x)
            res += s[x];
        return res;
    }
    void add(int x, int d) {
        c[x] += d;
        if ((d == 1 and c[x] == 1) or (d == -1 and c[x] == 0))
            for (; x <= n; x += x & -x)
                s[x] += d;
    }
    bool query(int L, int R) {
        return sum(R) - sum(L - 1) == R - L + 1;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    BIT r(n), c(n);
    for (int i = 0, t, x, y, x2, y2; i < q; i += 1) {
        cin >> t >> x >> y;
        if (t == 1) {
            r.add(x, 1);
            c.add(y, 1);
        }
        else if (t == 2) {
            r.add(x, -1);
            c.add(y, -1);
        }
        else {
            cin >> x2 >> y2;
            cout << (r.query(x, x2) or c.query(y, y2) ? "Yes\n" : "No\n");
        }
    }
}