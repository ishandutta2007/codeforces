#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cassert>

using namespace std;

typedef long long ll;

const int N = 1e5 + 7;

vector <int> g[N];

ll dp[N];
int cnt[N];

void dfs(int u, int h) {
    ++cnt[h];
    for (auto v : g[u]) {
        dfs(v, h + 1);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        g[x].push_back(i);
    }
    int ans = 0;
    dfs(0, 0);
    for (int i = 0; i < N; ++i) {
        ans += cnt[i] % 2;
    }
    cout << ans << endl;
}