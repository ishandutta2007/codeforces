#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;
 
/*
 * (00)
 * dp[i][j]xji
 * 0
 * dp[0][0~k]x + j0
 * ix + j0dp[i][j]
 * 1 - p+1, i + 1
 * dp[i + 1][j] += dp[i][j + 1]*(1 - p)//+1x+1
 * *2
 * dp[i + 1][j << 1] += (dp[i][j] + 1)*(1 - p)
 * *2x, *20+1
 * k+1dp[0][0~k]
 */
int x, k, p;
double dp[2][210];//
 
int main()
{
    scanf("%d %d %d", &x, &k, &p);
    double P = p/100.;
    for(int i = 0; i <= k; i++)
    {
        int tmp = x + i;
        while(!(tmp & 1))
            tmp >>= 1, dp[0][i] += 1.;
    }
    int now = 0;
    for(int i = 0; i < k; i++)
    {
        memset(dp[now^1], 0, sizeof(dp[now^1]));
        for(int j = 0; j <= k; j++)
        {
            dp[now^1][j << 1] += (dp[now][j] + 1)*P;
            dp[now^1][j] += dp[now][j + 1]*(1 - P);
        }
        now ^= 1;
    }
    printf("%.10f\n", dp[now][0]);
    return 0;
}