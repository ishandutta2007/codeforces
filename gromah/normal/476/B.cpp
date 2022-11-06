#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100 + 5

int len, pos, cnt, sum;
char s[N], t[N];

int main()
{
    scanf("%s", s);
    scanf("%s", t);
    len = strlen(s);
    for (int i = 0; i < len; i ++)
    {
        pos += s[i] == '+' ? 1 : -1;
        
        if (t[i] == '?')
            cnt ++;
        else sum += t[i] == '+' ? 1 : -1;
    }
    if (abs(pos - sum) > cnt)
        puts("0.0000000000");
    else
    {
        int t = (cnt - abs(pos - sum)) >> 1;
        int fz = 1, fm = 1;
        for (int i = 1; i <= cnt; i ++)
            fm *= i;
        for (int i = 1; i <= t; i ++)
            fz *= i;
        for (int i = 1; i <= cnt - t; i ++)
            fz *= i;
        fz = fm / fz;
        fm = 1;
        for (int i = 1; i <= cnt; i ++)
            fm *= 2;
        printf("%.9lf\n", (double) fz / fm);
    }
    return 0;
}