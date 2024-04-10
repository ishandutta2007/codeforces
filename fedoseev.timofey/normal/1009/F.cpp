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

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e6 + 7;

vector <int> g[N];

int ans[N];
int q[N];

vector <int> res[N];

int get(int u, int ind) {
    return res[u].size() - ind - 1;
}

void merge(int u, int v) {
    if (res[u].size() < res[v].size()) {
        swap(res[u], res[v]);
        swap(ans[u], ans[v]);
    }
    for (int i = 0; i < res[v].size(); ++i) {
        res[u][get(u, i)] += res[v][get(v, i)];
        if ((res[u][get(u, i)] > res[u][ans[u]]) || ((res[u][get(u, i)]) == res[u][ans[u]] && get(u, ans[u]) > i)) {
            ans[u] = get(u, i);
        }
    }
    res[v].clear();
    res[v].shrink_to_fit();
}

void dfs(int u, int p) {
    res[u].push_back(1);
    ans[u] = 0;
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        res[v].push_back(0);
        merge(u, v);
    }
    q[u] = get(u, ans[u]);
}

int main() {
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(0); cin.tie(0);
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i + 1 < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << q[i] << ' ';
    }
}