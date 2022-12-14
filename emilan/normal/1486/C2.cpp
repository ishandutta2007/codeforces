#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    // [l, r]
    auto ask = [](int l, int r) -> int {
        cout << "? " << l + 1 << ' ' << r + 1 << endl;
        int x;
        cin >> x;
        return x - 1;
    };

    auto ans = [](int i) -> void {
        cout << "! " << i + 1 << endl;
    };

    int p = ask(0, n - 1);

    if (p == n - 1 || (p && ask(0, p) == p)) { // left
        int l = 0, r = p;
        while (l + 1 < r) {
            int m = (l + r) / 2;

            if (ask(m, p) != p) r = m;
            else l = m;
        }

        ans(l);
    } else { // right
        int l = p, r = n - 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;

            if (ask(p, m) != p) l = m;
            else r = m;
        }

        ans(r);
    }
}