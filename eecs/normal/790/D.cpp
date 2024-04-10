#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

typedef long long ll;
const int maxn = 300010;
int n, f[maxn], mx[2][maxn], lst[2][maxn];
ll a[2][maxn];
unordered_map<int, int> g[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }
    for (int k : {0, 1}) {
        map<ll, int> mp;
        ll s = 0;
        mp[0] = 0, lst[k][0] = -1;
        for (int i = 1; i <= n; i++) {
            s += a[k][i];
            lst[k][i] = mp.count(s) ? mp[s] + 1 : -1, mp[s] = i;
            lst[k][i] = max(lst[k][i], lst[k][i - 1]);
        }
    }
    function<int(int, int)> solve = [&](int l, int r) {
        if (l < 0 || r < 0) return -n;
        if (g[l].find(r) != g[l].end()) return g[l][r];
        if (lst[0][l] > r) return g[l][r] = max(f[min(l, r)], solve(lst[0][l] - 1, r) + 1);
        if (lst[1][r] > l) return g[l][r] = max(f[min(l, r)], solve(l, lst[1][r] - 1) + 1);
        return g[l][r] = max(f[min(l, r)], max(solve(lst[0][l] - 1, r), solve(l, lst[1][r] - 1)) + 1);
    };
    map<ll, int> mp;
    ll cur = mp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cur += a[0][i] + a[1][i], f[i] = f[i - 1];
        if (mp.count(cur)) f[i] = max(f[i], f[mp[cur]] + 1);
        f[i] = max(f[i], solve(i, i)), mp[cur] = i;
    }
    printf("%d\n", solve(n, n));
    return 0;
}