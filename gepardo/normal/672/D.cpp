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

long long getAll(int* v, int n)
{
    long long sum = getSum(v, n);
    int mid = sum / n, rst = sum % n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += llabs(v[i] - mid - (i < rst));
    return ans / 2;
}

long long getMaxVal(int* v, int n, int maxV)
{
    long long ans = 0;
    for (int i = 0; i < n; i++)
        if (v[i] > maxV) ans += v[i] - maxV;
    return ans;
}

long long getMinVal(int* v, int n, int minV)
{
    long long ans = 0;
    for (int i = 0; i < n; i++)
        if (v[i] < minV) ans += minV - v[i];
    return ans;
}

int findMinVal(int* v, int n, int k, int l = 0, int r = 1e9)
{
    while (l < r)
    {
        int m = (l + r + 1) / 2;
        if (getMinVal(v, n, m) > k) r = m - 1; else l = m;
    }
    return l;
}

int findMaxVal(int* v, int n, int k, int l = 0, int r = 1e9)
{
    while (l < r)
    {
        int m = (l + r) / 2;
        if (getMaxVal(v, n, m) > k) l = m + 1; else r = m;
    }
    return l;
}

int main()
{
    int n = getInt(), k = getInt();
    int* v = getVectorInt(n);
    if (getAll(v, n) <= k)
        putchar('0' + bool(getSum(v, n) % n));
    else
        printf("%d", findMaxVal(v, n, k) - findMinVal(v, n, k));
    delete[] v;
    return 0;
}