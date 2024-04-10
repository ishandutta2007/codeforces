# include <iostream>
# include <vector>
# include <set>
# include <algorithm>
# include <queue>

using namespace std;

int n, m, k;

vector <set <int>> row;
vector <set <int>> col;

bool correct(int x, int y, const vector <vector <char>> &map) {
    if (map[x][y] == '.') return true;
    return false;
}

void del(int x, int y) {
    row[x].erase(y);
    col[y].erase(x);
}

int main() {
    cin >> n >> m >> k;
    row.resize(n + 2);
    col.resize(m + 2);
    vector <vector <char>> map(n + 2, vector<char>(m + 2, '#'));
    for (int i = 1; i < n + 1; ++i)
        for (int j = 1; j < m + 1; ++j)
            cin >> map[i][j];
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector <vector <int>> dist(n + 2, vector <int>(m + 2, -1));
    for (int i = 1; i <= n; ++i)
        for (int k = 1; k <= m; ++k)
            row[i].insert(k);
    for (int i = 1; i <= m; ++i)
        for (int k = 1; k <= n; ++k)
            col[i].insert(k);
    dist[x1][y1] = 0;
    row[x1].erase(y1);
    col[y1].erase(x1);
    queue <pair <int, int>> q;
    q.push({x1, y1});
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        while (true) {
            auto it = row[x].lower_bound(y);
            if (it == row[x].end()) break;
            int goy = *it;
            if (goy - y > k) break;
            if (!correct(x, goy, map)) break;
            del(x, goy);
            if (dist[x][goy] == -1) {
                dist[x][goy] = dist[x][y] + 1;
                q.push({x, goy});
            }
        }
        while (true) {
            auto it = row[x].lower_bound(y);
            if (it == row[x].begin()) break;
            it--;
            int goy = *it;
            if (y - goy > k) break;
            if (!correct(x, goy, map)) break;
            del(x, goy);
            if (dist[x][goy] == -1) {
                dist[x][goy] = dist[x][y] + 1;
                q.push({x, goy});
            }
        }
        while (true) {
            auto it = col[y].lower_bound(x);
            if (it == col[y].end()) break;
            int gox = *it;
            if (gox - x > k) break;
            if (!correct(gox, y, map)) break;
            del(gox, y);
            if (dist[gox][y] == -1) {
                dist[gox][y] = dist[x][y] + 1;
                q.push({gox, y});
            }
        }
        while (true) {
            auto it = col[y].lower_bound(x);
            if (it == col[y].begin()) break;
            it--;
            int gox = *it;
            if (x - gox > k) break;
            if (!correct(gox, y, map)) break;
            del(gox, y);
            if (dist[gox][y] == -1) {
                dist[gox][y] = dist[x][y] + 1;
                q.push({gox, y});
            }
        }
    }
    cout << dist[x2][y2] << endl;
}