#include <stdio.h>
#include <stdlib.h>

int getInt()
{
    int n;
    scanf("%d", &n);
    return n;
}

inline int* getVectorInt(int n)
{
    int *v = new int[n];
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    return v;
}

long long getSum(int* v, int n)
{
    long long sum = 0;
    for (int i = 0; i < n; i++) sum += v[i];
    return sum;
}

int n = getInt(), k = getInt();
int* v = getVectorInt(n);
long long sum = getSum(v, n);

long long getAll()
{
    int mid = sum / n, rst = sum % n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += llabs(v[i] - mid - (i < rst));
    return ans / 2;
}

long long getMaxVal(int maxV)
{
    long long ans = 0;
    for (int i = 0; i < n; i++)
        if (v[i] > maxV) ans += v[i] - maxV;
    return ans;
}

long long getMinVal(int minV)
{
    long long ans = 0;
    for (int i = 0; i < n; i++)
        if (v[i] < minV) ans += minV - v[i];
    return ans;
}

int findMinVal(int l = 0, int r = 1e9)
{
    while (l < r)
    {
        int m = (l + r + 1) / 2;
        if (getMinVal(m) > k) r = m - 1; else l = m;
    }
    return l;
}

int findMaxVal(int l = 0, int r = 1e9)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (getMaxVal(m) > k) l = m + 1; else r = m;
    }
    return l;
}

int main()
{
    if (getAll() <= k) putchar('0' + bool(sum % n));
        else printf("%d", findMaxVal() - findMinVal());
    return 0;
}