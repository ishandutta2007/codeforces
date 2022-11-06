#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5

int n, A[N], B[N], E[N];

inline void Add(int x)
{
    for (x ++; x <= n; x += (x & -x))
        E[x] ++;
}

inline int Calc(int x)
{
    int res = 0;
    for (x ++; x; x -= (x & -x))
        res += E[x];
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", A + i);
        Add(A[i]);
        A[i] -= Calc(A[i] - 1);
    }
    memset(E, 0, sizeof(E));
    for (int i = 1; i <= n; i ++)
    {
        scanf("%d", B + i);
        Add(B[i]);
        B[i] -= Calc(B[i] - 1);
        A[i] += B[i];
    }
    for (int j = n - 1; j; j --)
    {
        A[j - 1] += A[j] / (n - j + 1);
        A[j] %= n - j + 1;
    }
    memset(E, 0, sizeof(E));
    for (int i = 1; i <= n; i ++)
    {
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (mid - Calc(mid) >= A[i])
                r = mid;
            else l = mid + 1;
        }
        B[i] = l;
        Add(B[i]);
        printf("%d%c", B[i], i == n ? '\n' : ' ');
    }
    
    return 0;
}