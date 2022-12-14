#include <bits/stdc++.h>

using namespace std;

bool solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    for (int i = 0, j = 0; i < n || j < m; i++) {
        if (i == n || j == m) return false;
        if (s[i] != t[j]) return false;
        j++;
        if (i == n - 1 || s[i] != s[i + 1]) {
            while (t[j] == s[i]) j++;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
}