#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
using namespace std;
using ld = long double;
using ll = int64_t;
using pii = pair<int, int>;
using ull = uint64_t;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int x, y;
        cin >> x >> y;
        if (x < y) swap(x, y);
        int ans = y * 2;
        x -= y;
        if (x <= 1) ans += x;
        else ans += 2 * x - 1;
        cout << ans << endl;
    }
}