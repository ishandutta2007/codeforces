#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<vector<int>> G(n + 1);
    for (int i = 2; i <= n; i += 1) {
        cin >> p[i];
        G[p[i]].push_back(i);
    }
    vector<LL> f(n + 1), g(n + 1), size(n + 1), ms(n + 1);
    for (int i = n; i >= 1; i -= 1) {
        size[i] += 1;
        f[i] += size[i];
        size[p[i]] += size[i];
        ms[p[i]] = max(ms[p[i]], size[i]);
        f[p[i]] += f[i];
        ms[i] = max(ms[i], n - size[i]);
    }
    for (int i = 1; i <= n; i += 1)
        for (int j : G[i])
            g[j] = f[i] - size[i] - f[j] + g[i] + n - size[j];
    //for (int i = 1; i <= n; i += 1) cout << size[i] << " "; cout << "\n";
    //for (int i = 1; i <= n; i += 1) cout << f[i] << " "; cout << "\n";
    //for (int i = 1; i <= n; i += 1) cout << g[i] << " "; cout << "\n";
    int r = min_element(ms.begin() + 1, ms.end()) - ms.begin();
    LL ans = g[r] + n;
    for (int v : G[r]) ans += f[v];
    LL res = 0;
    bitset<1000000> bs;
    bs.set(0);
    map<int, int> mp;
    for (int j : G[r]) mp[size[j]] += 1;
    if (r != 1) mp[n - size[r]] += 1;
    for (auto& [x, y] : mp) {
        if (y >= 3) {
            mp[x * 2] += (y - 1) / 2;
            y -= 2 * (y - 1) / 2;
        }
        while (y) {
            bs |= bs << x;
            y -= 1;
        }
    }
    for (int i = 0; i < n; i += 1)
        if (bs[i]) res = max(res, (LL)i * (n - 1 - i));

    ans += res;
    for (int i = 1; i <= n; i += 1) {
        LL pans = g[i] + n;
        for (int j : G[i]) pans += f[j];
        //cout << i << " " << pans << "\n";
        pans += (LL)(n - 1 - ms[i]) * ms[i];
        ans = max(ans, pans);
    }
    cout << ans;
}