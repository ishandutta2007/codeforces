#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 33 + 5
#define INF 0x7fffffff

int n, x, Max, A[N][N];
bool Flag[N][N];

inline int get(int u)
{
    return u == 1 ? -1 : 1;
}

inline int Calc()
{
    for (int i = x + 1; i <= n; i ++)
        Flag[i][x] = Flag[x][x] ^ Flag[i - x][x];
    int res = 0;
    for (int i = 1; i <= n; i ++)
        res += get(Flag[i][x]) * A[i][x];
    for (int i = 1; i < x; i ++)
    {
        int _Max = -INF, sum;
        for (int k = 0; k < 2; k ++)
        {
            Flag[x][i] = k;
            Flag[x][i + x] = Flag[x][i] ^ Flag[x][x];
            sum = get(Flag[x][i]) * A[x][i] + get(Flag[x][i + x]) * A[x][i + x];
            for (int j = 1; j < x; j ++)
            {
                int _res = -INF;
                for (int _k = 0; _k < 2; _k ++)
                {
                    Flag[j][i] = _k;
                    Flag[j][i + x] = Flag[j][i] ^ Flag[j][x];
                    Flag[j + x][i] = Flag[j][i] ^ Flag[x][i];
                    Flag[j + x][i + x] = Flag[j + x][i] ^ Flag[j + x][x];
                    int _sum = get(Flag[j][i]) * A[j][i] + get(Flag[j][i + x]) * A[j][i + x];
                    _sum += get(Flag[j + x][i]) * A[j + x][i] + get(Flag[j + x][i + x]) * A[j + x][i + x];
                    _res = max(_res, _sum);
                }
                sum += _res;
            }
            _Max = max(_Max, sum);
        }
        res += _Max;
    }
    return res;
}

inline void dfs(int z)
{
    if (z > x)
    {
        Max = max(Max, Calc());
        return ;
    }
    Flag[z][x] = 0;
    dfs(z + 1);
    Flag[z][x] = 1;
    dfs(z + 1);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("3901.in", "r", stdin);
        freopen("3901.out", "w", stdout);
    #endif
    
    scanf("%d", &n);
    x = n + 1 >> 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            scanf("%d", A[i] + j);
    dfs(1);
    printf("%d\n", Max);
    
    #ifndef ONLINE_JUDGE
        fclose(stdin);
        fclose(stdout);
    #endif
    return 0;
}