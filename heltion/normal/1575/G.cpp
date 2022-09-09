#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
constexpr LL mod = 1'000'000'007;
vector<int> p[maxn], d[maxn];
int phi[maxn], a[maxn];
vector<int> mp[maxn];
int cnt[maxn];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 1; i < maxn; i += 1) {
        for (int j = i; j < maxn; j += i)
            d[j].push_back(i);
        if (d[i].size() == 2)
            for (int j = i; j < maxn; j += i) p[j].push_back(i);
    }
    phi[1] = 1;
    for (int i = 2; i < maxn; i += 1) {
        int x = p[i][0], j = i;
        phi[i] = 1;
        while (j % x == 0) {
            j /= x;
            phi[i] *= x;
        }
        phi[i] = phi[i] / x * (x - 1);
        phi[i] *= phi[j];
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i += 1) cin >> a[i];
    LL ans = 0;
    for (int x = 1; x <= n; x += 1) {
        for (int i = x; i <= n; i += x)
            for (int y : d[a[i]]) 
                cnt[y] += 1;
        for (int i = x; i <= n; i += x)
            for (int y : d[a[i]]) if (cnt[y]) {
                ans = ((LL)phi[x] * phi[y] % mod * cnt[y] % mod * cnt[y] + ans) % mod;
                cnt[y] = 0;
            }
    }
    cout << ans;
    return 0;
}