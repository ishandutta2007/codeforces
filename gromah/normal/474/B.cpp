#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000000 + 5

int n, m, A[N];

inline int find(int l, int r, int x)
{
    if (l >= r) return l;
    int mid = l + r + 1 >> 1;
    if (A[mid] > x)
        return find(l, mid - 1, x);
    else return find(mid, r, x);
}

int main()
{
    scanf("%d", &n);
    A[1] = 1;
    for (int i = 1; i <= n; i ++)
    {
        int t;
        scanf("%d", &t);
        A[i + 1] = A[i] + t;
    }
    scanf("%d", &m);
    while (m --)
    {
        int t;
        scanf("%d", &t);
        printf("%d\n", find(1, n, t));
    }
    return 0;
}