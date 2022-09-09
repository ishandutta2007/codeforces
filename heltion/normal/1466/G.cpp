#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 1'000'000'007;
constexpr int maxn = 100000 + 10;
LL pw[maxn], kpw[maxn];
LL hs[maxn][26];
vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n);
    for(int i = 1, l = 0, r = 0; i < n; i += 1){
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i] += 1;
        if(i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i < maxn; i += 1) pw[i] = i ? pw[i - 1] * 2 % mod : 1;
    for(int i = 0; i < maxn; i += 1) kpw[i] = i ? kpw[i - 1] * (mod + 1) / 2 % mod : 1;
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    for(int i = 0; i < n; i += 1)
        hs[i][t[i] - 'a'] = pw[n - i - 1];
    for(int i = n - 1; i >= 0; i -= 1)
        for(int j = 0; j < 26; j += 1)
            (hs[i][j] += hs[i + 1][j]) %= mod;
    vector<int> k(q);
    vector<string> qs(q);
    vector<int> ans(q);
    for(int i = 0; i < q; i += 1) cin >> k[i] >> qs[i];
    vector<int> p(q);
    for(int i = 0; i < q; i += 1) p[i] = i;
    sort(p.begin(), p.end(), [&](int x, int y){
        return qs[x].size() < qs[y].size();
    });
    int m = 0, debug = 0;
    for(int i = 0; i < q; i += 1){
        int u = p[i];
        while(m < n and s.size() < qs[u].size()){
            s = s + t[m] + s;
            m += 1;
        }
        if(s.size() < qs[u].size()) continue;
        if(m > k[u]) continue;
        auto z = z_function(qs[u] + '#' + s), pz = z_function(s + '#' + qs[u]);
        int x = 0;
        for(int i = qs[u].size() + 1; i < z.size(); i += 1) x += z[i] >= qs[u].size();
        LL res = x * pw[k[u] - m] % mod;
        if(debug)cout << u << "!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
        for(int i = 0; i < qs[u].size(); i += 1){
            int ok = 1;
            if(i + 1 != qs[u].size()) ok &= pz[pz.size() - ((int)qs[u].size() - i - 1)] >= ((int)qs[u].size() - i - 1);
            if(i) ok &=  z[(int)z.size() - i] >= i;
            if(ok){
                if(debug)cout << i << "okokok\n";
                if(debug)cout << hs[m][qs[u][i] - 'a'] << " " << hs[k[u]][qs[u][i] - 'a'] << " " << kpw[n - k[u]] << "\n";
                res = (res + (hs[m][qs[u][i] - 'a'] - hs[k[u]][qs[u][i] - 'a'] + mod) * kpw[n - k[u]]) % mod;
            }
        }
        if(debug)cout << m << " " << s << "\n";
        if(debug)cout << k[u] << " " << qs[u] << " " << res << "\n";
        ans[u] = res;
    }
    for(int x : ans) cout << x << "\n";
    return 0;
}