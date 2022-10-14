// Codeforces Beta Round #10
// Problem B -- Cinema Cashier
#include <cstdio>
#include <cstring>
#include <climits>

#define maxK 100

#define INF 100000

#define ABS(x) ((x) > 0? (x): -(x))

using namespace std;

int n, k;
bool v[maxK][maxK];

inline int rem(int x, int y)
{
    return ABS(x - ((k + 1) >> 1)) + ABS(y - ((k + 1) >> 1));
}

int main()
{
    scanf("%d%d", &n, &k);
    memset(v, 0, sizeof(v));
    for(; n != 0; -- n)
    {
        int m;
        scanf("%d", &m);
        int opt = INF, x, yl, yr;
        for(int i = 1; i <= k; ++ i)
        {
            int tmp = 0;
            for(int j = 1; j <= k; ++ j)
            {
                tmp += v[i][j]? INF: rem(i, j);
                if(j >= m)
                {
                    if(tmp < opt)
                        opt = tmp, x = i, yl = j - m + 1, yr = j;
                    tmp -= v[i][j - m + 1]? INF: rem(i, j - m + 1);
                }
            }
        }
        if(opt == INF)
            printf("-1\n");
        else
        {
            printf("%d %d %d\n", x, yl, yr);
            for(int j = yl; j <= yr; ++ j)
                v[x][j] = true;
        }
    }
    return 0;
}