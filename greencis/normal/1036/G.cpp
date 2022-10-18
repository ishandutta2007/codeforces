#pragma GCC optimize("Ofast")
#pragma GCC target("mmx,popcnt,sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,avx512f,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, degin[1001005];
vector<int> gg[1001005];
vector<int> source, target;
int p[20], g[20], ses, k, u[1001005];

void dfs(int v) {
    if (u[v] == ses) return;
    u[v] = ses;
    for (int to : gg[v])
        dfs(to);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        gg[x].push_back(y);
        ++degin[y];
    }
    for (int i = 1; i <= n; ++i) {
        if (degin[i] == 0)
            source.push_back(i);
        if (gg[i].size() == 0)
            target.push_back(i);
    }
    k = source.size();
    if (k != target.size())
        throw;
    for (int i = 0; i < k; ++i) {
        ++ses;
        dfs(source[i]);
        for (int j = 0; j < k; ++j)
            if (u[target[j]] == ses)
                g[i] |= (1 << j);
    }

    for (int mask = (1 << k) - 1; --mask; ) {
        int cur = 0;
        for (int i = 0; i < k; ++i)
            if ((mask >> i) & 1)
                cur |= g[i];
        if (__builtin_popcount(cur) == __builtin_popcount(mask)) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    cout << "YES" << endl;
}