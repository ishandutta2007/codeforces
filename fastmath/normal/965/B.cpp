#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 107;

char a[MAXN][MAXN];
int ans[MAXN][MAXN];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, len;
    cin >> n >> len;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> a[i][j];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + len - 1 < n; ++j) {
            bool ch = true;
            for (int k = j; k < j + len; ++k) ch &= (a[i][k] == '.');
            for (int k = j; k < j + len; ++k) ans[i][k] += ch;
        }
    }
    
    for (int i = 0; i + len - 1 < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool ch = true;
            for (int k = i; k < i + len; ++k) ch &= (a[k][j] == '.');
            for (int k = i; k < i + len; ++k) ans[k][j] += ch;
        }
    }

    int mx = 0;
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) mx = max(mx, ans[i][j]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[i][j] == mx) {
                cout << i + 1 << ' ' << j + 1 << '\n';
                return 0;
            }
        }
    }

    return 0;
}