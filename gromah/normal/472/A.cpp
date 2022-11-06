#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

inline bool Prime(int x)
{
    if (x < 2) return 1;
    int d = (int) sqrt(x + 0.5);
    for (int i = 2; i <= d; i ++)
        if (x % i == 0) return 0;
    return 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 4; i <= n; i ++)
        if (!Prime(i) && !Prime(n - i))
        {
            printf("%d %d\n", i, n - i);
            return 0;
        }
}