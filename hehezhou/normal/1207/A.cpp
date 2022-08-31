#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    ios :: sync_with_stdio(0);
    cin >> t;
    while(t--) {
        int a, b, c, x, y;
        cin >> a >> b >> c >> x >> y;
        a /= 2;
        int ans = 0;
        if(x < y) swap(x, y), swap(b, c);
        ans += x * min(a, b);
        a -= min(a, b);
        ans += y * min(a, c);
        cout << ans << endl;
    }
}