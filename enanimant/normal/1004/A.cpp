#include <bits/stdc++.h>

using namespace std;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, d;
    cin >> n >> d;

    vector<int> h(n);
    set<int> newh;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    int ans = 2;
    for (int i = 0; i <= n - 2; i++) {
        int dh = h[i + 1] - h[i];
        ans += (dh > 2 * d ? 2 : dh == 2 * d ? 1 : 0);
    }

    cout << ans << '\n';


    return 0;
}