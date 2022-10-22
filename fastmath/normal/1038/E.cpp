#include <bits/stdc++.h>

using namespace std;

const int MAXN = 107;
const int INF = 1e9 + 7;
const int N = 4;

multiset <int> g[N][N], ng[N][N];

int n;
int cost[MAXN];
pair <int, int> d[MAXN];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> d[i].first >> cost[i] >> d[i].second;
        --d[i].first; --d[i].second;
        if (d[i].second < d[i].first) swap(d[i].first, d[i].second);
        g[d[i].first][d[i].second].insert(cost[i]);
    }
}

void build(int mask) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            ng[i][j].clear();
        }
    }
    for (int i = 0; i < N; ++i) {
        ng[i][i] = g[i][i];
    }
    int num = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            auto it = g[i][j].begin();
            if ((mask >> num) & 1 && g[i][j].size()) ++it;
            while (it != g[i][j].end()) {
                ng[i][j].insert(*it);
                ng[j][i].insert(*it);
                ++it;
            }
            ++num;
        }   
    }
}
    
int nn = 0;
void dfs(int u) {
    while (ng[u][u].size()) {
        nn += *ng[u][u].begin();
        ng[u][u].erase(ng[u][u].begin());
    }
    for (int v = 0; v < N; ++v) {
        while (ng[u][v].size()) {
            int c = *ng[u][v].begin();
            nn += c;
            ng[u][v].erase(ng[u][v].find(c));
            ng[v][u].erase(ng[v][u].find(c));
            dfs(v);
        }
    }
}

bool used[N];
vector <int> l;
void kek(int u) {
    used[u] = 1;
    l.push_back(u);
    for (int v = 0; v < N; ++v) {
        if (used[v]) continue;
        if (ng[u][v].size()) kek(v);
    }
}

int pw[N];
int get(int mask) {
    build(mask);
    int ans = 0;

    for (int i = 0; i < N; ++i) {
        pw[i] = 0;
        for (int j = 0; j < N; ++j) {
            if (i != j) pw[i] += ng[i][j].size();
        }
    }

    memset(used, 0, sizeof used);
    for (int i = 0; i < N; ++i) {
        if (used[i]) continue;

        l.clear();
        kek(i);
        int np = 0;
        for (int v : l) {
            np += (pw[v] & 1);
        }
          
        if (np == 0 || np == 2) {
            nn = 0;
            dfs(i);
            ans = max(ans, nn);
        }
    }
    return ans;
}

int ans = 0;
void solve() {
    for (int mask = 0; mask < (1 << (N * (N - 1) / 2)); ++mask) {
        ans = max(ans, get(mask));
    }
}

void print() {
    cout << ans << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read();
    solve();
    print();

    return 0;
}