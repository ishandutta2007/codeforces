#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 5000;
char s1[maxn + 2], s2[maxn + 2];
int dp1[maxn + 2][maxn + 2], u1[maxn + 1];
int dp2[maxn + 2][maxn + 2], u2[maxn + 1];
int dp[maxn + 2][maxn + 2];
void f(int n, char s[], int dp[][maxn + 2], int u[]){
    for(int i = n; i >= 1; i -= 1)
        for(int j = n; j >= 1; j -= 1)
            dp[i][j] = s[i] == s[j] ? dp[i + 1][j + 1] + 1 : 0;
    for(int i = 1; i <= n; i += 1)
        for(int j = 1; j <= n; j += 1)
            if(i != j) u[i] = max(u[i], dp[i][j]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> (s1 + 1) >> (s2 + 1);
    int n1 = strlen(s1 + 1), n2 = strlen(s2 + 1), ans = maxn + 1;
    f(n1, s1, dp1, u1);
    f(n2, s2, dp2, u2);
    for(int i = n1; i >= 1; i -= 1)
        for(int j = n2; j >= 1; j -= 1){
            dp[i][j] = s1[i] == s2[j] ? dp[i + 1][j + 1] + 1 : 0;
            int L = max(u1[i], u2[j]) + 1;
            if(L <= dp[i][j]) ans = min(ans, L);
            //cout << i << " " << j << " " << dp[i][j] << " " << u1[i] << " " << u2[j] << "\n";
        }
    cout << (ans > maxn ? -1 : ans);
    return 0;
}