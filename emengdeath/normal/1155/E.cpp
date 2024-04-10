#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;
const int mod = 1e6 + 3;
long long f[50][12], a[12];
void build(int x, int ans){
    f[x][0] =  1;
    for (int i = 1; i <= 10; i ++)
        f[x][i] = f[x][i - 1] * x;
    f[x][11] = ans;
}
int ask(int x)
{
    printf("? %d\n", x);
    fflush(stdout);
    scanf("%d", &x);
    return x;
}
long long calc(long long x, long long y)
{
    x %= mod;
    long long z = 1;
    while (y)
    {
        if (y & 1) (z *= x) %= mod;
        (x *= x) %= mod, y /= 2;
    }
    return z;
}
void gauss()
{
    for (int i = 0; i <= 10; i ++) {
        if (!f[i][i])
            for (int j = i + 1; j < 50; j++)
                if (f[j][i]) {
                    for (int k = i; k <= 11; k++)
                        swap(f[j][k], f[i][k]);
                    break;
                }
        if (f[i][i])
        {
            long long v = calc(f[i][i], mod - 2);
            for (int j = i + 1; j < 50; j ++)
            {
                long long u = v * f[j][i];
                for (int k = i; k <= 11; k ++)
                    f[j][k] = (f[j][k] - u * f[i][k] % mod + mod) % mod;
            }
        }
    }
    for (int i = 10; i >= 0; i --)
        if (f[i][i])
        {
            for (int j = 10; j > i; j --)
                f[i][11] = (f[i][11] - a[j] * f[i][j] % mod) % mod;
            a[i] = f[i][11] * calc(f[i][i], mod - 2) % mod;
        }
}
int get(long long x)
{
    long long v = 1, all = 0;
    for (int i = 0; i <= 10; i ++)
        all = (all + v * a[i]) % mod, (v *= x) %= mod;
    return all;
}
int main(){
    for (int i = 0; i < 50; i ++)
        build(i, ask(i));
    gauss();
    for (int i = 0; i < mod; i ++)
        if (!get(i)){
            printf("! %d\n", i);
            fflush(stdout);
            return 0;
        }
    printf("! -1\n");
    fflush(stdout);
    return 0;
}