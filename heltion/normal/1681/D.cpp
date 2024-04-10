#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    LL n, x;
    cin >> n >> x;
    auto sx = to_string(x);
    auto no = [&](){
        cout << -1;
        exit(0);
    };
    if (n < sx.size()) no();
    int ans = INT_MAX;
    function<void(LL, int)> DFS = [&](LL x, int d) {
        auto sx = to_string(x);
        if (sx.size() == n) {
            ans = min(ans, d);
            return;
        }
        if (d + (n - sx.size()) >= ans) return;
        ranges::sort(sx);
        ranges::reverse(sx);
        for (int i = 0; i < sx.size(); i += 1)
            if ((not i or sx[i] != sx[i - 1]) and sx[i] >= '2')
                DFS(x * (sx[i] - '0'), d + 1);
    };
    DFS(x, 0);
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}