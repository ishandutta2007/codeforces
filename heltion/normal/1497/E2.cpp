#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxm = 10000000 + 1;
int np[maxm], p[maxm], f[maxm], pn;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    f[1] = 1;
    for(int i = 2; i < maxm; i += 1){
        if(not np[i]){
            f[i] = i;
            p[pn ++] = i;
        }
        for(int j = 0; j < pn; j += 1){
            int k = i * p[j];
            if(k >= maxm) break;
            np[k] = 1;
            if(f[i] % p[j]) f[k] = f[i] * p[j];
            else f[k] = f[i] / p[j];
            if(i % p[j] == 0) break;
        }
    }
    int T;
    for(cin >> T; T; T -= 1){
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i += 1){
            cin >> a[i];
            a[i] = f[a[i]];
        }
        vector<int> nxt(n + 1);
        vector<vector<int>> rm(n + 1);
        map<int, int> mp;
        for(int i = n; i >= 1; i -= 1){
            nxt[i] = mp[a[i]];
            rm[nxt[i]].push_back(i);
            mp[a[i]] = i;
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, n));
        dp[0][0] = 0;
        set<int, greater<int>> s;
        for(int i = 1; i <= n; i += 1){
            for(int j : rm[i]) s.insert(j);
            for(int j = 0; j <= k; j += 1) dp[i][j] = dp[i - 1][j] + 1;
            int c = 0;
            for(int x : s){
                if(c > k) break;
                for(int j = c; j <= k; j += 1) dp[i][j] = min(dp[i][j], dp[x][j - c] + 1);
                c += 1;
            }
            if((int)s.size() <= k) dp[i][s.size()] = 1;
        }
        cout << *min_element(dp[n].begin(), dp[n].end()) << "\n";
    }
    return 0;
}