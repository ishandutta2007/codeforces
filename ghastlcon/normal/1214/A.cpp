#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define INF 1000000007
using namespace std;

int main(void) // 1214A.cpp
{
    int n;
    int d;
    int e;
    int i;
    int o;

    scanf("%d", &n);
    scanf("%d", &d);
    scanf("%d", &e);

    for(i = 0, o = INF; i * 5 * e <= n; i ++)
        o = min(o, (n - i * 5 * e) % d);

    printf("%d\n", o);

    return 0;
}