#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

int nxt() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = nxt();
    string s;
    cin >> s;
    vector<char> used(26);
    char last = 0;
    for (char c : s) {
        if (c != last && used[c - 'A']) {
            cout << "NO\n";
            return;
        }
        used[c - 'A'] = 1;
        last = c;
    }
    cout << "YES\n";
}

int main() {
    int t = nxt();
    while (t--) {
        solve();
    }

    return 0;
}