#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<int> f(n + 1);
    for (int x : a) f[x]++;

    int mex = n + 1;
    for (int i = n; i >= 0; i--) {
        if (f[i] == 0) mex = i;
    }

    vector<int> b;
    vector<bool> vis(n + 1);
    for (int l = 0, r = 0; r < n; r++) {
        int mex_cur = 0;
        vis[ a[r] ] = true;
        while (vis[mex_cur]) mex_cur++;
        if (mex_cur == mex) {
            b.push_back(mex);
            for (int i = l; i <= r; i++) {
                vis[ a[i] ] = false;
                if (--f[ a[i] ] == 0 && a[i] < mex) mex = a[i];
            }
            l = r + 1;
        }
    }

    int m = b.size();
    cout << m << '\n';
    for (int i = 0; i < m; i++) cout << b[i] << " \n"[i == m - 1];
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