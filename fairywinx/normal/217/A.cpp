#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

#define all(x) x.begin(), x.end()
#define pb emplace_back
#define mp make_pair

using namespace std;

void setup() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif

    srand(time(NULL));
}

const int N = 100;

vector<int> g[N];

void dfs(int v, vector<int> &used) {
    used[v] = 1;
    for(auto u: g[v]) {
        if (!used[u])
            dfs(u, used);
    }
}

signed main() {
    setup();

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if (a[i].first == a[j].first || a[i].second == a[j].second) {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }
    int ans = 0;
    vector<int> used(n);
    for(int i = 0; i < n; ++i) {
        if (!used[i]) {
            ++ans;
            dfs(i, used);
        }
    }
    cout << ans - 1;
}