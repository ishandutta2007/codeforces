#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<bool> vis(n + 1);
    vector<int> ex;
    for (int x : a) {
        if (x <= n && !vis[x]) vis[x] = true;
        else ex.push_back(x);
    }

    int m = int(ex.size());
    sort(ex.begin(), ex.end());

    int i = 1;
    for (int x : ex) {
        while (vis[i]) i++;
        if ((x - 1) / 2 < i) return -1;
        vis[i] = true;
    }

    return m;
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