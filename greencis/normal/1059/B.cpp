#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m;
char s[1005][1005], t[1005][1005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j)
            t[i][j] = '.';
    }

    int ok = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int cur = 1;
            for (int y = 0; y < 3; ++y) {
                for (int x = 0; x < 3; ++x) {
                    if (y == 1 && x == 1) continue;
                    if (s[i + y][j + x] != '#')
                        cur = 0;
                }
            }
            if (!cur) continue;
            for (int y = 0; y < 3; ++y) {
                for (int x = 0; x < 3; ++x) {
                    if (y == 1 && x == 1) continue;
                    if (i + y < n && j + x < m)
                        t[i + y][j + x] = '#';
                }
            }
        }
    }

    for (int i = 0; i < n; ++i)
        ok &= strcmp(s[i], t[i]) == 0;
    cout << (ok ? "YES" : "NO");
}