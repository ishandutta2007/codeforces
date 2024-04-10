#include <bits/stdc++.h>

using namespace std;

vector<int> z_algo(const string &s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 1; i < n; i++) {
        int &j = z[i];
        if (i < r) j = min(z[i - l], r - i);
        while (i + j < n && s[j] == s[i + j]) j++;
        if (i + j > r) l = i, r = i + j;
    }
    return z;
}

int main() {
    string s;
    cin >> s;

    int n = s.size();
    auto z = z_algo(s);
    vector<int> f(n + 1);

    for (int x : z) f[x]++;
    for (int i = n; i > 0; i--) f[i - 1] += f[i];

    vector<pair<int, int>> ans;
    for (int i = 1; i < n; i++) if (z[n - i] == i) {
        ans.emplace_back(i, f[i] + 1);
    }

    ans.emplace_back(n, 1);
    cout << ans.size() << '\n';
    for (auto [i, x] : ans) cout << i << ' ' << x << '\n';
}