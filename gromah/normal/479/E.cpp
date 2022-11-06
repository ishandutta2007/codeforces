#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <int, int> Pii;
typedef pair <Pii, int> PPi;
#define x first
#define y second
#define mp make_pair
#define N 5000 + 5
#define Mod 1000000007

int n, a, b, k;
LL Dp[2][N], Sum[N];

int main()
{
    scanf("%d%d%d%d", &n, &a, &b, &k);
    Dp[0][a] = 1;
    for (int i = 1; i <= n; i ++)
        Sum[i] = Sum[i - 1] + Dp[0][i];
    
    for (int i = 1; i <= k; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if ((j - b) * (a - b) <= 0) continue ;
            if (j < b)
                Dp[1][j] = (Sum[b + j - 1 >> 1] + Mod - Dp[0][j]) % Mod;
            else Dp[1][j] = (Sum[n] - Sum[b + j >> 1] + Mod - Dp[0][j] + Mod) % Mod;
        }
        
        for (int j = 1; j <= n; j ++)
        {
            Sum[j] = (Sum[j - 1] + Dp[1][j]) % Mod;
            Dp[0][j] = Dp[1][j];
            Dp[1][j] = 0;
        }
    }
    
    cout << Sum[n] << endl;
    
    return 0;
}