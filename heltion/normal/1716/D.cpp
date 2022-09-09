#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int mod = 998244353;
void add(int& x, int y) {
    if ((x += y) >= mod) x -= mod;
}
void sub(int& x, int y) {
    if ((x -= y) < 0) x += mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> ans(n + 1), f(n + 1);
    f[0] = 1;
    for (int i = 0; ; i += 1) {
        auto g = f;
        for (int j = 0; j <= n; j += 1)
            if (j >= k + i)
                add(g[j], g[j - k - i]);
        for (int j = 0; j <= n; j += 1)
            sub(g[j], f[j]);
        f.swap(g);
        int done = 1;
        for (int j = 0; j <= n; j += 1) {
            if (f[j]) done = 0;
            add(ans[j], f[j]);
        }
        if (done) break;
    }
    for (int i = 1; i <= n; i += 1)
        cout << ans[i] << " ";
    return 0;
}