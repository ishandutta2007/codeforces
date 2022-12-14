#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    if (t == "abc" &&
            count(s.begin(), s.end(), 'a') > 0 &&
            count(s.begin(), s.end(), 'b') > 0 &&
            count(s.begin(), s.end(), 'c') > 0) {
        array<int, 128> p = {};
        iota(p.begin(), p.end(), 0);
        p['a'] = 'a';
        p['b'] = 'c';
        p['c'] = 'b';

        sort(s.begin(), s.end(), [&](char x, char y) { return p[x] < p[y]; });
    } else {
        sort(s.begin(), s.end());
    }

    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tcs = 1;
    cin >> tcs;
    for (int tc = 1; tc <= tcs; tc++) {
        solve();
    }
}