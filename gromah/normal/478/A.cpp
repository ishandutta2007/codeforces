#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t, sum = 0;
    for (int i = 1; i <= 5; i ++)
    {
        scanf("%d", &t);
        sum += t;
    }
    if (sum == 0 || sum % 5) puts("-1");
        else printf("%d\n", sum / 5);
    return 0;
}