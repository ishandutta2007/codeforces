#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

long long int bio [1000000] [20];
int sat [20] [20];
int po [20];
int n, m, k;

long long int rek (int mask, int zad)
{
    if (bio [mask] [zad] != -1) return bio [mask] [zad];
    if (__builtin_popcount (mask) == m) return 0;
    long long int ret = 0;
    for (int j = 0; j < n; j++)
    {
        if (!(mask & (1 << j))) ret = max (ret, rek (mask | (1 << j), j) + po [j] + sat [zad] [j]);
    }
    return bio [mask] [zad] = ret;
}

int main()
{
    memset (bio, -1, sizeof bio);
    int x, y, c;
    scanf("%d%d%d", &n, &m, &k);
    for (int l = 0; l < n; l++)
    {
        scanf("%d", &po [l]);
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d%d", &x, &y, &c);
        x--; y--;
        sat [x] [y] = c;
    }
    printf("%lld", rek (0, 19));
    return 0;
}