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

const int N = 1e6 + 7;
const int K = 21;

vector <int> g[N];
int go[K][N];
bool grab[N];

void dfs(int u, int p) {
    go[0][u] = p;
    for (int i = 1; i < K; ++i) {
        go[i][u] = go[i - 1][go[i - 1][u]];
    }
    for (auto v : g[u]) {
        if (v != p) dfs(v, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(n - 1, n - 1);
    k = n - k;
    for (int i = n - 1; i >= 0; --i) {
        if (grab[i]) continue;
        int cur = i;
        int len = 1;
        for (int j = K - 1; j >= 0; --j) {
            if (go[j][cur] == cur) continue;
            if (!grab[go[j][cur]]) {
                cur = go[j][cur];
                len += 1 << j;
            }
        }
        if (len <= k) {
            cur = i;
            while (!grab[cur]) {
                grab[cur] = 1;
                cur = go[0][cur];
            }
            k -= len;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!grab[i]) {
            cout << i + 1 << ' ';
        }
    }
}