//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,fma,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int dx[4] = {-1, 0, 1, 0};
constexpr int dy[4] = {0, -1, 0, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    bool good = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (v[i][j] == 'S') {
                for (int z = 0; z < 4; ++z) {
                    int ny = i + dy[z];
                    int nx = j + dx[z];
                    if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                    if (v[ny][nx] == 'W') good = false;
                    else if (v[ny][nx] == '.')
                        v[ny][nx] = 'D';
                }
            }
        }
    }
    if (!good) cout << "No\n";
    else {
        cout << "Yes\n";
        for (int i = 0; i < n; ++i) cout << v[i] << '\n';
    }
}