#include <bits/stdc++.h>
using namespace std;

const int n = 32;
int _n, k, d[n][n];

vector<int> get(int n) {
    if (!n) return {0};
    auto res = get(n - 1), tmp = res;
    reverse(tmp.begin(), tmp.end());
    for (int x : tmp) res.push_back(x | (1 << (n - 1)));
    return res;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> _n >> k;
    auto ord = get(5);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 10; k++) {
                if ((k % 2 ? ord[i] : ord[j]) >> (k / 2) & 1) d[i][j] |= 1 << k;
            }
        }
    }
    for (int i = 0; i < _n; i++) {
        for (int j = 0; j < _n - 1; j++) cout << (d[i][j] ^ d[i][j + 1]) << " ";
        cout << endl;
    }
    for (int i = 0; i < _n - 1; i++) {
        for (int j = 0; j < _n; j++) cout << (d[i][j] ^ d[i + 1][j]) << " ";
        cout << endl;
    }
    int x = 0, y = 0;
    while (k--) {
        int z;
        cin >> z;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) if (z == (d[i][j] ^ d[x][y])) {
                cout << i + 1 << " " << j + 1 << endl;
                x = i, y = j; goto nxt;
            }
        }
    nxt:;
    }
    return 0;
}