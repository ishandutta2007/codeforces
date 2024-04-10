#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void)
{
    int t, a, b;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}