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
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <cstring>

using namespace std;

typedef long long ll;
typedef long double ld;

const int L = 1e7 + 7;

int go[L][2];
int suf[L];
int supsuf[L];

int id[L];
int par[L];
bool vis[L];

int uk = 0;

void add(string s, int idx) {
    int cur = 0;
    for (auto c : s) {
        if (go[cur][c - 'a'] == -1) {
            go[cur][c - 'a'] = ++uk;
        }
        cur = go[cur][c - 'a'];
    }
    id[cur] = idx;
}

void bfs() {
    suf[0] = 0;
    supsuf[0] = -1;
    queue <int> q;
    for (int i = 0; i < 2; ++i) {
        if (go[0][i] == -1) {
            go[0][i] = 0;
        }
        else {
            suf[go[0][i]] = 0;
            supsuf[go[0][i]] = -1;
            q.push(go[0][i]);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < 2; ++i) {
            if (go[u][i] == -1) {
                go[u][i] = go[suf[u]][i];
            }
            else {
                int who = go[u][i];
                suf[who] = go[suf[u]][i];
                if (id[suf[who]] != -1) {
                    supsuf[who] = suf[who];
                }
                else {
                    supsuf[who] = supsuf[suf[who]];
                }
                q.push(go[u][i]);
            }
        }
    }
}

const int N = 757;

bool A[N][N];
vector <int> g[N];
int usedL[N];
int usedR[N];
int mtL[N];
int mtR[N];

int timer = 0;

bool kuhn(int u) {
    if (usedL[u] == timer) return false;
    usedL[u] = timer;
    for (auto v : g[u]) {
        if (mtR[v] == -1) {
            mtR[v] = u;
            return true;
        }
    }
    for (auto v : g[u]) {
        if (kuhn(mtR[v])) {
            mtR[v] = u;
            return true;
        }
    }
    return false;
}

void dfs(int u) {
    usedL[u] = 1;
    for (auto v : g[u]) {
        if (v != mtL[u] && !usedR[v]) {
            usedR[v] = 1;
            if (mtR[v] != -1 && !usedL[mtR[v]]) {
                dfs(mtR[v]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < 2; ++j) {
            go[i][j] = -1;
        }
        id[i] = -1;
    }
    map <string, int> last;
    int n;
    cin >> n;
    vector <string> a(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        add(s, i);
        a[i] = s;
    }
    bfs();
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 0; j < a[i].size(); ++j) {
            cur = go[cur][a[i][j] - 'a'];
            if (j != (int)a[i].size() - 1) {
                if (id[cur] != -1) {
                    A[i][id[cur]] = 1;
                }
            }
            if (supsuf[cur] != -1) {
                A[i][id[supsuf[cur]]] = 1;
            }
        }
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] |= A[i][k] & A[k][j];
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j]) g[i].push_back(j);
        }
    }
    for (int i = 0; i < N; ++i) {
        mtL[i] = mtR[i] = -1;
    }
    int mem = 0;
    for (int i = 0; i < n; ++i) {
        ++timer;
        kuhn(i);
    }
    for (int i = 0; i < n; ++i) {
        if (mtR[i] != -1) {
            mtL[mtR[i]] = i;
        }
    }
    for (int i = 0; i < N; ++i) {
        usedL[i] = usedR[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        if (mtL[i] == -1) {
            dfs(i);
        }
    }
    vector <int> ans;
    for (int i = 0; i < n; ++i) {
        if (usedL[i] && !usedR[i]) ans.push_back(i + 1);
    }
    cout << ans.size() << '\n';
    for (auto i : ans) {
        cout << i << ' ';
    }
}