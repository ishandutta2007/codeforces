#include <bits/stdc++.h>

using namespace std;

string solve() {
    int n;
    string s;
    cin >> n >> s;

    if (n == 1 || s[0] == s[1]) return string{s[0]} + s[0];
    else {
        int i = 1;
        for (; i < n; i++) {
            if (s[i - 1] < s[i]) break;
        }
        string t = s.substr(0, i);
        return t + string(t.rbegin(), t.rend());
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        cout << solve() << '\n';
    }
}