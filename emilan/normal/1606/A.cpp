#include <bits/stdc++.h>

using namespace std;

string solve() {
    string s;
    cin >> s;

    if (s[0] == s.back()) return s;
    else return s.back() + s.substr(1);
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