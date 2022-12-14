#include <bits/stdc++.h>

using namespace std;

bool solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &s : a) cin >> s;

    bool ok = false;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (a[i][j] == '*' &&
                    a[i - 1][j] == '*' &&
                    a[i][j - 1] == '*' &&
                    a[i + 1][j] == '*' &&
                    a[i][j + 1] == '*') {
                ok = true;

                a[i][j] = '.';
                for (int k = i - 1; k >= 0 && a[k][j] == '*'; k--) {
                    a[k][j] = '.';
                }
                for (int k = i + 1; k < n && a[k][j] == '*'; k++) {
                    a[k][j] = '.';
                }
                for (int k = j - 1; k >= 0 && a[i][k] == '*'; k--) {
                    a[i][k] = '.';
                }
                for (int k = j + 1; k < m && a[i][k] == '*'; k++) {
                    a[i][k] = '.';
                }
                
                goto out;
            }
        }
    }

out:

    for (int i = 0; i < n; i++) {
        if (count(a[i].begin(), a[i].end(), '*')) return false;
    }

    return ok;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << (solve() ? "yES" : "nO") << "\n";
}