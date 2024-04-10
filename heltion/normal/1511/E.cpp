#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> vs(n);
    for(auto& s : vs) cin >> s;
    int k = n * m;
    vector<LL> pw(k + 1), pv(k + 1), ans(k + 1);
    for(int i = 0; i <= k; i += 1) pw[i] = i ? pw[i - 1] * 2 % mod : 1;
    for(int i = 0; i <= k; i += 1) pv[i] = i ? pv[i - 1] * (mod + 1) / 2 % mod : 1;
    LL sum = 0;
    for(int i = 1; i <= k; i += 1){
        if(i >= 3 and i % 2) sum = (sum + pv[i]) % mod;
        ans[i] = (ans[i - 1] * 2 + pw[i] * sum + (i % 2 == 0)) % mod;
        //cout << i << " " << ans[i] << "\n";
    }
    int w = 0;
    for(auto s : vs) for(char c : s) w += c == 'o';
    LL res = 0;
    for(int i = 0; i < n; i += 1){
        int p = 0;
        for(int j = 0; j <= m; j += 1){
            if(j < m and vs[i][j] == 'o') p += 1;
            else{
                res = (res + ans[p] * pw[w - p]) % mod;
                p = 0;
            }
        }
    }
    for(int i = 0; i < m; i += 1){
        int p = 0;
        for(int j = 0; j <= n; j += 1){
            if(j < n and vs[j][i] == 'o') p += 1;
            else{
                res = (res + ans[p] * pw[w - p]) % mod;
                p = 0;
            }
        }
    }
    cout << res;
    return 0;
}