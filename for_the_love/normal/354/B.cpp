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
const int N = 22;
const int INF = 1e9 + 7;
char s[44][44];
int dp[44][1 << 20], mask[44][44];
int n;
int Dfs(int i, int j, int c, int p){
    if (dp[i][j] != INF) return dp[i][j];
    int ans = -INF;
    if (i == n + n - 2) ans = 0;
    else for (int next = 0; next < 26; next++){
        int t = (mask[i + 1][next] & (j | (j << 1)));
        if (t) ans = max(ans, -Dfs(i + 1, t, next, p ^ 1));
    }
    if (!p){
        if (!c) ans++; if (c == 1) ans--;
    }else{
        if (!c) ans--; if (c == 1) ans++;
    }
    return dp[i][j] = ans;
}


int main(){
    while (cin >> n){
        for (int i = 0; i < n; i++) scanf("%s", s[i]);
        memset(mask, 0, sizeof(mask));
        for (int i = 0; i < n * 2; i++)
        for (int j = 0; j < 26; j++)
        for (int k = 0; k < n; k++){
            int x = k;
            int y = i - x;
            if (y >= 0 && y < n && s[x][y] - 'a' == j) mask[i][j] |= (1 << k);
        }
        for (int i = 0; i < n + n; i++)
        for (int j = 0; j < 1 << n; j++)
            dp[i][j] = INF;
        int ans = Dfs(0, 1, s[0][0] - 'a', 1);
        if (!ans) puts("DRAW");
        if (ans > 0) puts("SECOND");
        if (ans < 0) puts("FIRST");
    }
}