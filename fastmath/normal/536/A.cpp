#include <bits/stdc++.h>

using namespace std;

#define int long long

const int INF = 1e9 + 7;

int a, b;

bool check(int l, int r, int t, int m) {
    int rx = a + b * (r - 1);
    int len = r - l + 1;
    int sum = a * len + b * (l - 1) * len + len * (len - 1) / 2 * b;
    return max(rx, (sum + m - 1) / m) <= t;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> a >> b >> n;
    for (int i = 0; i < n; ++i) {
        int l, t, m;
        cin >> l >> t >> m;
        int tl = l - 1;
        int tr = INF;
        while (tl < tr - 1) {
            int tm = (tl + tr) >> 1;
            if (check(l, tm, t, m)) tl = tm;
            else tr = tm;
        }
        if (tl == l - 1) cout << "-1\n";
        else cout << tl << '\n';
    }   

    return 0;
}