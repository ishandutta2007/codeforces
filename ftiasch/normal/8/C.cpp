// Codeforces Beta Round #8
// Problem C -- Looking for Order
#include <cstdio>

#define maxN 25
#define maxM 1 << 24

#define BIT(s, k) ((s) & (1 << ((k) - 1)))
#define SQR(x) ((x) * (x))
#define DIS(i, j) (SQR(x[i] - x[j]) + SQR(y[i] - y[j]))

using namespace std;

int n, x[maxN], y[maxN], f[maxM], g[maxM];


int main()
{

    scanf("%d%d%d", x, y, &n);
    for(int i = 1; i <= n; ++ i)
        scanf("%d%d", x + i, y + i);
    f[0] = 0;
    for(int i = 0, j = 1; j < (1 << n); ++ j)
    {
        if(BIT(j, i + 1))
            i ++;
        f[j] = f[j - BIT(j, i)] + 2 * DIS(0, i);
        g[j] = i;
        for(int k = 1; k < i; ++ k)
            if(BIT(j, k))
            {
                int temp = f[j - BIT(j, k) - BIT(j, i)] + DIS(0, i) + DIS(i, k) + DIS(k, 0);
                if(temp < f[j])
                    f[j] = temp, g[j] = k;
            }
    }
    printf("%d\n", f[(1 << n) - 1]);
    for(int i = n, j = (1 << n) - 1; j > 0;)
    {
        while(!BIT(j, i))
            i --;
        int k = j;
        printf("%d %d ", 0, i);
        k -= BIT(k, i);
        if(g[j] != i)
        {
            printf("%d ", g[j]);
            k -= BIT(k, g[j]);
        }
        j = k;
    }
    printf("0\n");
    return 0;
}