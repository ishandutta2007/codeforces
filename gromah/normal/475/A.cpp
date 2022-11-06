#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d", &n);
    puts("+------------------------+");
    int t, _t = (n - 1) / 3, sum = 0;
    bool ok = 0;
    if ((n - 1) % 3 >= 1) ok = 1;
    t = n < 1 ? 0 : (n - 2) / 3 + 1;
    sum += t;
    for (int i = 1; i <= 11; i ++)
    {
        if (i == 1) printf("|");
            else printf(".");
        if (i <= t) printf("O");
            else printf("#");
    }
    puts(".|D|)");
    ok = ((n - 1) % 3 >= 2);
    t = n <= 1 ? 0 : (n - 3) / 3 + 1;
    sum += t;
    for (int i = 1; i <= 11; i ++)
    {
        if (i == 1) printf("|");
            else printf(".");
        if (i <= t) printf("O");
            else printf("#");
    }
    puts(".|.|");
    if (n >= 3)
        printf("|O"), sum ++;
    else printf("|#");
    puts(".......................|");
    t = (n - 1) / 3;
    for (int i = 1; i <= 11; i ++)
    {
        if (i == 1) printf("|");
            else printf(".");
        if (i <= t) printf("O");
            else printf("#");
    }
    puts(".|.|)");
    puts("+------------------------+");
    return 0;
}