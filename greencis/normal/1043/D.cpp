#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, a[101000];
vector<int> g[100105];
map<pii, int> mp;
ll ans = 0;
int u[100105], cnt;

void dfs(int v) {
    if (!u[v]++) {
        ++cnt;
        for (int to : g[v])
            dfs(to);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
            if (j > 0)
                ++mp[make_pair(a[j - 1], a[j])];
        }
    }

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second == m) {
            int x = it->first.first;
            int y = it->first.second;
            g[x].push_back(y);
            g[y].push_back(x);
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (!u[i]) {
            cnt = 0;
            dfs(i);
            ans += cnt * ll(cnt + 1) / 2;
        }
    }
    cout << ans << endl;
}