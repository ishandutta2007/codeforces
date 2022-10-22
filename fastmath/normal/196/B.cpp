#include <bits/stdc++.h>
using namespace std;
const int N = 1501;
const int V = N * N;
const int INF = 1e9 + 7;
int n, m;
char a[N][N];
pair <int, int> lol[N][N];
vector <pair <int, int> > vv = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(int x, int y) {
    int i = (x % n + n) % n, j = (y % m + m) % m;
    if (a[i][j] == '#') return;
    if (lol[i][j] == make_pair(x, y)) {
        return;
    }
    if (lol[i][j] == make_pair(INF, INF)) {
        lol[i][j] = {x, y};
        for (auto v : vv) dfs(x + v.first, y + v.second);   
    }
    else {
        cout << "Yes\n";
        exit(0);
    }   
}
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif    
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }   
    }   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            lol[i][j] = {INF, INF};
        }   
    }   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == 'S') {
                dfs(i, j);
                cout << "No\n";
                exit(0);
            }   
        }   
    }   
}