#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, h;
    cin >> n >> h;
    int ans = n;

    while (n--) {
        int a;
        cin >> a;
        if (a > h)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}