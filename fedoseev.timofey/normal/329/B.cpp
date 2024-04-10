#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int Inf = 1e9;

vector <int> dx = {0, 0, -1, 1};
vector <int> dy = {-1, 1, 0, 0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <vector <char>> f(n, vector <char> (m));
    int fx, fy;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> f[i][j]; 
            if (f[i][j] == 'E') {
                fx = i, fy = j;
            }
        }
    }
    vector <vector <int>> d(n, vector <int> (m, Inf));
    d[fx][fy] = 0;
    queue <pair <int, int>> q;
    q.push({fx, fy});
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 <= nx && nx < n && 0 <= ny && ny < m && f[nx][ny] != 'T' && d[nx][ny] > d[x][y] + 1) {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    int dist = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (f[i][j] == 'S') dist = d[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ('1' <= f[i][j] && f[i][j] <= '9' && d[i][j] <= dist) {
                ans += f[i][j] - '0';
            }
        }
    }
    cout << ans << '\n';
}