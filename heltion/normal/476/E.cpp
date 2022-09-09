#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 2400;
char s[maxn], p[maxn];
int a[maxn], dp[maxn][maxn];
int main(){
    scanf("%s %s", s + 1, p + 1);
    int n = strlen(s + 1), m = strlen(p + 1);
    for(int i = 1, j; i <= n; i += 1){
        for(a[i] = i, j = m; j and a[i]; a[i] -= 1)
            if(s[a[i]] == p[j]) j -= 1;
        if(j) a[i] = -1;
    }
    for(int i = 1; i <= n; i += 1)
        for(int j = 0; j <= i; j += 1){
            dp[i][j] = dp[i - 1][j];
            if(j and dp[i - 1][j] > dp[i][j]) dp[i][j] = dp[i - 1][j];
            if(~a[i] and j >= (i - a[i] - m)
                and dp[a[i]][j - (i - a[i] - m)] + 1 > dp[i][j]
                and j - (i - a[i] - m) <= a[i])
                dp[i][j] = dp[a[i]][j - (i - a[i] - m)] + 1;
            //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
        }
    for(int i = 0; i <= n; i += 1)
        printf("%d ", dp[n][i]);
}