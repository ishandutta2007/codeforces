#include<bits/stdc++.h>
#define F(x) for(int x = 0; x < 2; x += 1)
using namespace std;
using LL = long long;
constexpr int maxn = 31;
int L[maxn], R[maxn];
LL dp[maxn][2][2][2][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    for(cin >> t; t; t -= 1){
        int l, r;
        cin >> l >> r;
        for(int i = 0; i < 30; i += 1) L[i] = (l >> i) & 1;
        for(int i = 0; i < 30; i += 1) R[i] = (r >> i) & 1;
        memset(dp, 0, sizeof dp);
        dp[30][0][0][0][0] = 1;
        for(int i = 30; i; i -= 1)
            F(a)F(b)F(c)F(d)F(u)F(v){
                if(u + v >= 2) continue;
                if(not a and u < L[i - 1]) continue;
                if(not b and u > R[i - 1]) continue;
                if(not c and v < L[i - 1]) continue;
                if(not d and v > R[i - 1]) continue;
                dp[i - 1][a or u > L[i - 1]][b or u < R[i - 1]][c or v > L[i - 1]][d or v < R[i - 1]] += dp[i][a][b][c][d];
            }
        LL ans = 0;
        F(a)F(b)F(c)F(d) ans += dp[0][a][b][c][d];
        cout << ans << "\n";
    }
    return 0;
}