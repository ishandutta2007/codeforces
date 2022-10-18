#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

int n, a[200105], b[200105], u[200105];
vector<int> g[200105];

void dfs(int x) {
    if (!u[x]++)
        for (int to : g[x])
            dfs(to);
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b + n);
    int bi = unique(b, b + n) - b;
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(b, b + bi, a[i]) - b;
        if (i > 0)
            g[a[i]].push_back(a[i - 1]);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (!u[a[i]]) {
            ++cnt;
            dfs(a[i]);
        }
    }

    int ans = 1;
    while (--cnt)
        ans = ans * 2 % 998244353;
    cout << ans;
}