#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int b, g;
    cin >> b >> g;
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        int x = n - i;
        if (i <= b && x <= g) ++ans;
    }
    cout << ans << '\n';
}