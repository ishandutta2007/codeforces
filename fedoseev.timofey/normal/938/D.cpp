#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

const int N = 2e5 + 7;

vector <pair<int, ll>> g[N];
ll a[N];
ll ans[N];
bool used[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ll w;
        cin >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 0; i < n; ++i) cin >> a[i];
    multiset <pair <ll, int>> q;
    for (int i = 0; i < n; ++i) {
        q.insert({a[i], i});
    }
    for (int i = 0; i < n; ++i) {
        ans[i] = a[i];
    }
    while (!q.empty()) {
        auto p = *q.begin();
        q.erase(q.begin());
        ll w = p.first;
        int u = p.second;
        if (ans[u] < w) continue;
        for (auto v : g[u]) {
            if (w + 2 * v.second < ans[v.first]) {
                ans[v.first] = w + 2 * v.second;
                q.insert({ans[v.first], v.first});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
}