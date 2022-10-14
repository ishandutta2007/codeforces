// Codeforces Beta Round #17
// Problem C -- Balance
#include <cstdio>
#include <cstring>
#include <algorithm>

#define N 150
#define M 50
#define MOD 51123987

#define INC(x, a) x = (x + (a)) % MOD

using namespace std;

int n, m, dp[N][M + 2][M + 2][M + 2], next[N + 1][3];
char buffer[N + 1];

int main()
{
    scanf("%d%s", &n, buffer);
    m = (n + 2) / 3;
    next[n][0] = next[n][1] = next[n][2] = n;
    for(int i = n - 1; i != -1; -- i)
        for(int j = 0; j != 3; ++ j)
            next[i][j] = buffer[i] - 'a' == j? i: next[i + 1][j];
    int answer = 0;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    for(int i = 0; i != n; ++ i)
        for(int a = 0; a <= m; ++ a)
            for(int b = 0; b <= m; ++ b)
                for(int c = 0; c <= m; ++ c)
                {
                    if(a + b + c == n && abs(a - b) <= 1 && abs(b - c) <= 1 && abs(c - a) <= 1)
                        INC(answer, dp[i][a][b][c]);
                    if(next[i][0] != n)
                        INC(dp[next[i][0]][a + 1][b][c], dp[i][a][b][c]);
                    if(next[i][1] != n)
                        INC(dp[next[i][1]][a][b + 1][c], dp[i][a][b][c]);                   
                    if(next[i][2] != n)
                        INC(dp[next[i][2]][a][b][c + 1], dp[i][a][b][c]);
                }
    printf("%d\n", answer);
    return 0;
}