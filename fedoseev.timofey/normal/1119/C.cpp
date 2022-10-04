#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <int> dx = {0, 0, 1, 1};
vector <int> dy = {0, 1, 0, 1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <vector <int>> a(n, vector <int> (m));
    vector <vector <int>> b(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            if (a[i][j] != b[i][j]) {
                for (int k = 0; k < 4; ++k) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    a[x][y] ^= 1;
                }
            }
        }
    }
    cout << (a == b ? "Yes\n" : "No\n");
}