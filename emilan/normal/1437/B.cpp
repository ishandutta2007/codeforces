#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        int ans = s[0] == s[n - 1];
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == s[i]) ans++;
        }

        cout << ans / 2 << '\n';
    }
}