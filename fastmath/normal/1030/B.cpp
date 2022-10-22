#include <bits/stdc++.h>

using namespace std;

bool check(int n, int d, int x, int y) {
    return (x - d <= y && y <= x + d && d <= x + y && x + y <= n + n - d);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

   int q;
   cin >> q;
   for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        if (check(n, d, x, y)) cout << "YES\n";
        else cout << "NO\n";
   }

    return 0;
}