#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int s, ans = 0, a = 1;
        cin >> s;
        while (s > 0) {
            ans += 1;
            s -= a;
            a += 2;
        }
        cout << ans << "\n";
    }
    return 0;
}