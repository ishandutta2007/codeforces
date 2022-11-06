#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 3000;
constexpr int mod = 998244353;
char s[maxn + 2], t[maxn + 2];
int dp[maxn + 1][maxn + 1];
void add(int& x, const int& y){
    x += y;
    if(x >= mod) x -= mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> (s + 1) >> (t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= n; j += 1) if(s[i] == t[j] or j > m)
            if(i == 1) dp[j][j] = 2;
            else{
                if(j + i - 1 <= n) add(dp[j][j + i - 1], dp[j + 1][j + i - 1]);
                if(j - i + 1 >= 1) add(dp[j - i + 1][j], dp[j - i + 1][j - 1]);
            }
    int ans = 0;
    for(int i = m; i <= n; i += 1) add(ans, dp[1][i]);
    cout << ans;
    return 0;
}