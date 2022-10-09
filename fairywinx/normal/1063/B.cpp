#include <bits/stdc++.h>

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};

const int N = 2e3 + 228;
const int INF = 1e9 + 228;

int A[N][N];

int n, m;

struct node {
    pair<int, int> d;
    int x, y;
    node() {}
    node(pair<int, int> _d, int _x, int _y) {
        d = _d, x = _x, y = _y;
    }
};

bool operator<(node a, node b) {
    return tuple(a.d, a.x, a.y) < tuple(b.d, b.x, b.y);
}

bool operator>(node a, node b) {
    return tuple(a.d, a.x, a.y) > tuple(b.d, b.x, b.y);
}

vector<vector<pair<int, int>>> dist(int a, int b, int type) {
    priority_queue<node, vector<node>, greater<node>> q;
    vector d(n, vector(m, make_pair(INF, INF)));
    d[a][b] = {0, 0};
    q.push({d[a][b], a, b});
    vector used(n, vector<int> (m));
    while (q.size()) {
        auto tmp = q.top();
        q.pop();
        int x = tmp.x, y = tmp.y;
        if (used[x][y])
            continue;
        used[x][y] = 1;

        for (int k = 0; k < 4; ++k) {
            int i = x + mx[k], j = y + my[k];
            if (i >= 0 && j >= 0 && i < n && j < m && A[i][j]) {
                pair<int, int> cost = d[x][y];
                if (k == 0) {
                    if (type == 0)
                        cost.first += 1;
                    else
                        cost.second += 1;
                } else if (k == 1) {
                    if (type == 1)
                        cost.first += 1;
                    else
                        cost.second += 1;
                }
                if (cost < d[i][j]) {
                    d[i][j] = cost;
                    q.push({d[i][j], i, j});
                }
            }
        }
    }
    return d;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int x, y;
    cin >> x >> y;
    --x, --y;
    int c1, c2;
    cin >> c1 >> c2;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            A[i][j] = (s[j] == '.' ? 1 : 0);
        }
    }
    auto z1 = dist(x, y, 1);
    auto z2 = dist(x, y, 0);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // cout << z1[i][j].first << ':' << z1[i][j].second << ' ';
            if (z1[i][j].first <= c1 && z1[i][j].second <= c2) {
                ++ans;
            } else if (z2[i][j].first <= c2 && z2[i][j].second <= c1) {
                ++ans;
            }
        }
        // cout << '\n';
    }
    cout << ans << '\n';
}