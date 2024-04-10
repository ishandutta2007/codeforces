#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


char s[55555], ans[1555], res;

int dp[2666][2666], cnt, c[255];



void Dfs(int i, int j){
    if (dp[i][j] != -1) return;
    if (i == j){
        dp[i][j] = 1;
        return;
    }
    dp[i][j] = 0;
    if (i > j) return;
    if (s[i] == s[j]){
        Dfs(i + 1, j - 1);
        dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
    }
    Dfs(i, j - 1);
    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
    Dfs(i + 1, j);
    dp[i][j] = max(dp[i][j], dp[i + 1][j]);
}
void solve(int i, int j, int t){
    if (cnt == 50) return;
    for (int l = i; l <= j; l++)
    for (int r = j; r >= i; r--)
    if (s[l] == s[r] && dp[l][r] == t){
        if (l == r){
            res = s[l];
            return;
        }
        ans[++cnt] = s[l];
        solve(l + 1, r - 1, t - 2);
        return;
    }
}
int main(){
    int n;
    scanf("%s", s + 1);
    n = strlen(s + 1);
    if (n == 1){
        printf("%s\n", s + 1);
        return 0;
    }
    for (int i = 1; i <= n; i++) c[s[i]]++;
    for (char ch = 'a'; ch <= 'z'; ch++)
    if (c[ch] >= 100){
        for (int i = 1; i <= 100; i++) putchar(ch);
        puts("");
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    Dfs(1, n);
    res = 0;
    if (s[1] == s[n]){
        ans[++cnt] = s[1];
        solve(2, n - 1, dp[1][n] - 2);
    }else solve(1, n, dp[1][n]);
    int len = 0;
    for (int i = 1; i <= cnt; i++) putchar(ans[i]);
    if (res) putchar(res);
    for (int i = cnt; i >= 1; i--) putchar(ans[i]);
    puts("");
}