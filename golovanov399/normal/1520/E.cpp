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
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '*') {
            a.push_back(i);
        }
    }
    if (a.empty()) {
        cout << "0\n";
        return;
    }
    int start = a[a.size() / 2] - (int)a.size() / 2;
    long long ans = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        ans += abs(a[i] - start - i);
    }
    cout << ans << "\n";
}

int main() {
    int t = nxt();
    while (t--) {
        solve();
    }

    return 0;
}