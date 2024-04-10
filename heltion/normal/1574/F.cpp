#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
void no(){
    cout << "0";
    exit(0);
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<set<int>> G(k + 1), H(k + 1);
    for (int i = 0; i < n; i += 1) {
        int c;
        cin >> c;
        vector<int> A(c);
        for (int& x : A) cin >> x;
        for (int j = 1; j < c; j += 1) {
            G[A[j - 1]].insert(A[j]);
            H[A[j]].insert(A[j - 1]);
        }
    }
    //for (int i = 1; i <= k; i += 1) cout << G[i] << " ";
    //cout << "\n";
    //for (int i = 1; i <= k; i += 1) cout << H[i] << " ";
    map<int, int> mp;
    for (int i = 1; i <= k; i += 1)
        if (H[i].empty()) {
            int x = 0;
            for (int j = i; j;) {
                x += 1;
                if (H[j].size() > 1) {
                    x = -1;
                    break;
                }
                if (G[j].empty()) break;
                if (G[j].size() > 1) {
                    x = -1;
                    break;
                }
                j = *G[j].begin();
            }
            if (x != -1) mp[x] += 1;
        }
    vector<LL> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i <= m; i += 1) for (auto [x, y] : mp)
        if (i >= x) dp[i] = (dp[i] + dp[i - x] * y) % mod;
    cout << dp[m];
    return 0;
}