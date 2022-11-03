#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 1e9 + 7;
const int N = 500 + 13;
const int INF = 1e9 + 13;

int di[] = {0, -1, 0, 1};
int dj[] = {-1, 0, 1, 0};

int n, m;

bool isin(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

int get(int i, int j) {
    return j + i * m;
}

int lvl(char c) {
    return (c == '.' ? 0 : 1);
}

vector<pii> g[N * N][3];
bool used[N * N][3];

void dfs(int v, int k, int u) {
    used[v][k] = true;

//    cout << v / m << ' ' << v % m << ' ' << k << endl;

    for(auto p : g[v][k]) {
        if(!used[p.f][p.s])
            dfs(p.f, p.s, u);
        else if(p.f == u) {
            used[p.f][2] = true;
        }
    }
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    cin >> n >> m;

    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int v = get(i, j);
            for(int l = 0; l < 4; l++) {
                int i1 = i + di[l];
                int j1 = j + dj[l];

                if(!isin(i1, j1))
                    continue;
//g[v][lvl(s[i][j])].emplace_back(get(i1, j1), lvl(s[i1][j1]) + 1);
                g[v][0].emplace_back(get(i1, j1), lvl(s[i1][j1]) + 1);
                g[v][1].emplace_back(get(i1, j1), lvl(s[i1][j1]) + 1);
            }
        }
    }

    int i1, j1, i2, j2;
    cin >> i1 >> j1 >> i2 >> j2;

    i1--;
    j1--;
    i2--;
    j2--;

    dfs(get(i1, j1), lvl(s[i1][j1]), get(i2, j2));

    cout << (used[get(i2, j2)][2] ? "YES" : "NO");
}