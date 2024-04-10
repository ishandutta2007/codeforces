#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ull = uint64_t;
using ll = int64_t;
using ld = long double;
using pii = pair<int, int>;

constexpr int dx[4] = {-1, 0, 1, 0};
constexpr int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ttt;
    cin >> ttt;
    while (ttt--) {
        int n;
        cin >> n;
        vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> v[i][j];
            }
        }
        vector<vector<char>> a(n, vector<char>(n));
        auto check = [&](int y, int x) {
            int cur = 0;
            for (int z = 0; z < 4; ++z) {
                int ny = y + dy[z];
                int nx = x + dx[z];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                cur ^= a[ny][nx];
            }
            return cur == 1;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i + j) % 2) continue;
                int value = 0;
                for (; value < 2; ++value) {
                    bool good = true;
                    a[i][j] = value;
                    if (i > 0) { // check upper
                        good &= check(i - 1, j);
                    }
                    if (i == n - 1 && j > 0) { // check left
                        good &= check(i, j - 1);
                    }
                    if (good)
                        break;
                }
                if (value > 1)
                    return 4071505;
            }
        }
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
//                if ((i + j) % 2) cerr << ' ';
//            else
//                cerr << (int)a[i][j];
//            }
//            cerr << endl;
//        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int zzz = j;
                if ((i + j) % 2) zzz = n - 1 - j;
                if (a[i][zzz])
                    ans ^= v[i][j];
            }
        }
        cout << ans << '\n';
    }
}