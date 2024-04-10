#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include <cstdio>
using namespace std;
const int N = 1e5 + 2;
const int mod =  1e9 + 7;
int f[N][13][1<<4];
long long  a[1000], b[1000][1000], c[1000][1000];
int n, k, m;
void update(int & a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
int turn(int x, int y)
{
    return (x << m) + y;
}
int main(){
    scanf("%d %d %d", &n, &k, &m);
    for (int cnt = 0; cnt <= k; cnt ++)
        for (int j = 0; j < (1 << m) ; j ++)
        {
            int x = turn(cnt, j);
            b[x][turn(cnt, (j << 1) % (1 << m))] ++;
            if (cnt != k)
            {
                for (int l = 0; l < m ; l ++)
                    if ((1 << l) & j)
                        b[x][turn(cnt + 1, (j << 1) % (1 << m) + 1)] ++;
                b[x][turn(cnt + 1, (j << 1) % (1 << m) + 1)] ++;
            }
        }
    a[turn(0, 0)] = 1;
    int all = turn(k, (1 << m) - 1);
    while (n)
    {
        if (n&1)
        {
            for (int i = 0; i <= all; i ++)
                for (int j = 0; j <= all; j ++)
                    (c[0][j] += a[i] * b[i][j] ) %= mod;
            for (int i = 0; i <= all ; i ++)
                a[i] = c[0][i], c[0][i] = 0;
        }
        for (int i = 0; i <= all ; i ++)
            for (int j = 0; j <= all; j ++)
                for (int k = 0; k <= all ; k ++)
                    (c[i][k] += b[i][j] * b[j][k] ) %= mod;
        for (int i = 0; i <= all; i ++)
            for (int j = 0; j <= all; j ++)
                b[i][j] = c[i][j], c[i][j] = 0;
        n /= 2;
    }
    int ans = 0;
    for (int i = 0; i < (1 << m);  i ++)
        update(ans, a[turn(k,i)]);
    printf("%d\n", ans);
    return 0;
}