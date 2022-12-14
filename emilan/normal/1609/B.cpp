#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    string s;
    cin >> n >> q >> s;

    s = "dd" + s + "dd";

    auto query = [&](int p) {
        int cnt = 0;
        for (int i = p - 2; i <= p; i++) {
            if (s.substr(i, 3) == "abc") cnt++;
        }
        return cnt;
    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s.substr(i, 3) == "abc") ans++;
    }

    while (q--) {
        int i;
        char c;
        cin >> i >> c;
        i++;

        ans -= query(i);
        s[i] = c;
        ans += query(i);

        cout << ans << "\n";
    }
}