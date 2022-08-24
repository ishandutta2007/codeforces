#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector< int > profx(m, 0);
    vector< int > profy(n, 0);

    bool ok = true;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] != '.') {
                int px = ((s[j] - '0') + i * 2) % 4;
                int py = ((s[j] - '0') + j * 2) % 4;
                int cx, cy;
                if (px < 2) {
                    cx = 1;
                } else {
                    cx = 2;
                }
                if (py == 1 || py == 2) {
                    cy = 1;
                } else {
                    cy = 2;
                }
                if (profx[j] == 0 || profx[j] == cx) {
                    profx[j] = cx;
                } else {
                    ok = false;
                }
                if (profy[i] == 0 || profy[i] == cy) {
                    profy[i] = cy;
                } else {
                    ok = false;
                }
            }
        }
    }
    if (!ok) {
        cout << 0 << '\n';
    } else {
        int ans = 1;
        int MOD = 1000003;
        for (int i = 0; i < m; ++i) {
            if (profx[i] == 0) {
                ans = (2 * ans) % MOD;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (profy[i] == 0) {
                ans = (2 * ans) % MOD;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}