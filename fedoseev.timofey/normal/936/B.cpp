#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

vector <int> g[N];
bool achive[N][2];
int p[N][2];
int used[N];

void try_win(int u, int t) {
    achive[u][t] = 1;
    for (auto v : g[u]) {
        if (!achive[v][t ^ 1]) {
            try_win(v, t ^ 1);
            p[v][t ^ 1] = u;
        }
    }
}

void dfs(int u) {
    used[u] = 1;
    for (auto v : g[u]) {
        if (used[v] == 1) {
            cout << "Draw" << endl;
            exit(0);
        }
        if (!used[v]) dfs(v);
    }
    used[u] = 2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; ++j) {
            int x;
            cin >> x;
            --x;
            g[i].push_back(x);
        }
    }
    int s;
    cin >> s;
    --s;
    p[s][0] = -1;
    try_win(s, 0);
    vector <int> ans;
    for (int i = 0; i < n; ++i) {
        int t = 1;
        if (g[i].empty() && achive[i][t]) {
            while (i != -1) {
                ans.push_back(i);
                i = p[i][t];
                t ^= 1;
            }
            reverse(ans.begin(), ans.end());
            cout << "Win" << endl;
            for (auto turn : ans) {
                cout << turn + 1 << " ";
            }
            return 0;
        }
    }
    dfs(s);
    cout << "Lose" << endl;
}