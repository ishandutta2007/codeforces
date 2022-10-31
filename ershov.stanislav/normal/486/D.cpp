#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

const int N = 2222;
const int MOD = 1e9+7;

int n, d, a[N], mn=0, used[N];
long long ans;

vector<int> g[N];

long long dfs(int v, int par) {
    long long res = 1;
    if (a[v] < mn || a[v] > mn + d || (a[v] == mn+d && used[v])) {
        return 0;
    } else {
        for (int i = 0; i < g[v].size(); i++) {
            if (g[v][i]!=par) {
                res = (res*(dfs(g[v][i], v) + 1))%MOD;
            }
        }
        return res;
    }
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    cin >> d >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n-1; i++) {
        int x, y;
        cin >> x >> y;
        g[y].push_back(x);
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) {
        mn = a[i]-d;
        ans = (ans + dfs(i, 0))%MOD;
        used[i] = true;
    }
    cout << ans;
    return 0;
}