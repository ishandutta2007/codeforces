#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void)
{
    int n;

    scanf("%*c%d", &n);
    printf("%d\n", n & 1);

    return 0;
}