#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <random>
#include <time.h>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 7;

vector <int> g[MAXN];

bool can[MAXN][2];
int p[MAXN][2];

void bfs(int s) {
    queue <pair <int, int> > q;
    q.push({s, 0});
    can[s][0] = true;

    while (q.size()) {
        pair <int, int> u = q.front();
        q.pop();

        for (int v: g[u.first]) {
            if (!can[v][u.second ^ 1]) {
                can[v][u.second ^ 1] = true;
                p[v][u.second ^ 1] = u.first;
                q.push({v, u.second ^ 1});
            }
        }
    }

}

int color[MAXN];
bool dfs(int u) {
    color[u] = 1;
    for (int v: g[u]) {
        if (color[v] == 0) {
            if (dfs(v)) return true;
        }
        if (color[v] == 1) return true;
    }
    color[u] = 2;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            g[i].push_back(v - 1);
        }
    }

    int s;
    cin >> s;
    --s;
    bfs(s);

    for (int i = 0; i < n; ++i) {
        if ((int) g[i].size() == 0 && can[i][1]) {
            cout << "Win\n";

            vector <int> ans;
            int u = i;
            int t = 1;
            while (!(u == s && t == 0)) {
                ans.push_back(u);
                u = p[u][t];
                t ^= 1;
            }
            ans.push_back(s);
            reverse(ans.begin(), ans.end());

            for (int elem: ans) {
                cout << elem + 1 << ' ';
            }
            cout << '\n';

            return 0;
        }
    }   

    if (dfs(s)) {
        cout << "Draw\n";
    }
    else {
        cout << "Lose\n";
    }

    return 0;
}