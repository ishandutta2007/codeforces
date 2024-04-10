#include <bits/stdc++.h>
using namespace std;

int n;
char s[3][55][55];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3 * n; j++) {
            for (int k = 0; k < 3 * n; k++) s[i][j][k] = '#';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3 * n; j++) {
            s[0][3 * i][j] = s[2][j][3 * i] = '.';
        }
        s[1][3 * i][3 * i + 1] = '.';
        s[1][3 * i + 1][3 * i + 1] = s[2][3 * i + 1][3 * i + 1] = '.';
        for (int j = 0, v; j < n; j++) {
            cin >> v;
            if (!v) continue;
            for (int k : {0, 1, 2}) s[k][3 * i + 1][3 * j + 1] = '.';
        }
        s[0][3 * i][3 * n - 1] = i + '1';
    }
    cout << 3 * n << " " << 3 * n << " 3\n";
    for (int k : {0, 1, 2}) {
        for (int i = 0; i < 3 * n; i++) {
            for (int j = 0; j < 3 * n; j++) {
                cout << s[k][i][j];
            }
            cout << "\n";
        }
    }
    return 0;
}