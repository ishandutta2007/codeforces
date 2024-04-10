#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1001;
const int INF = 1e9 + 7;
const int T = 3;
int n, m;
char a[N][N];
vector <pair <int, int> > v = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int dist[T][N][N];
bool check(int i, int j) {
    return 0 <= i && i < n && 0 <= j && j < m && a[i][j] != '#';
}   
void bfs(char c, int t) {
    queue <pair <int, int> > q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dist[t][i][j] = INF;
        }   
    }   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == c) {
                dist[t][i][j] = 0;
                q.push({i, j});
            }   
        }   
    }   
    while (q.size()) {
        auto u = q.front(); q.pop();
        for (auto e : v) {
            int i = u.first + e.first, j = u.second + e.second;
            if (check(i, j) && dist[t][u.first][u.second] + 1 < dist[t][i][j]) {
                dist[t][i][j] = dist[t][u.first][u.second] + 1;
                q.push({i, j});
            }   
        }   
    }   
}   
int get(char c) {
    int ans = 0;
    for (char w = '1'; w <= '3'; ++w) {
        int nn = INF;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == c) {
                    nn = min(nn, dist[w - '1'][i][j]);        
                }
            }   
        }   
        ans += nn;
    }   
    return ans;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0); cout.precision(20);
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }   
    }   
    for (int i = 0; i < 3; ++i) {
        bfs('1' + i, i);
    }   
    for (int t = 0; t < 3; ++t) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (dist[t][i][j]) --dist[t][i][j];
            }   
        }   
    }   
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') continue;
            int nn = 0;
            for (int t = 0; t < 3; ++t) {
                nn += dist[t][i][j];
            }   
            ans = min(ans, nn + 1);
        }   
    }   
    for (int i = 0; i < 3; ++i) {
        ans = min(ans, get('1' + i));
    }   
    if (ans > N * N) {
        cout << "-1\n";
    }   
    else {
        cout << ans << '\n';
    }   
}