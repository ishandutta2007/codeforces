#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        vector<vector<int>> p(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> p[i][j];
            }
        }
        int L = 0, R = 1e9;
        while (L != R) {
            int M = (L + R + 1) / 2;
            vector<vector<int>> c(m, vector<int>(n));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (p[j][i] >= M) {
                        c[j][i] = 1;
                    }
                }
            }
            bool can = true;
            for (int i = 0; i < n; ++i) {
                int cnt = 0;
                for (int j = 0; j < m; ++j) {
                    cnt += c[j][i];
                }
                if (!cnt) {
                    can = false;
                    break;
                }
            }
            if (can) {
                can = false;
                for (int j = 0; j < m; ++j) {
                    int cnt = 0;
                    for (int i = 0; i < n; ++i) {
                        cnt += c[j][i];
                    }
                    if (cnt >= 2) {
                        can = true;
                    }
                }
            }
            if (can) {
                L = M;
            } else {
                R = M - 1;
            }
        }
        cout << L << '\n';
    }
    return 0;
}