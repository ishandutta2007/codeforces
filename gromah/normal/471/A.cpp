#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int cnt[9];

int main()
{
    for (int i = 1; i <= 6; i ++)
    {
        int t;
        scanf("%d", &t);
        cnt[t] ++;
    }
    bool ok = 0;
    for (int i = 1; i <= 9 && !ok; i ++)
        if (cnt[i] >= 4) ok = 1, cnt[i] -= 4;
    if (!ok)
    {
        puts("Alien");
        return 0;
    }
    ok = 0;
    for (int i = 1; i <= 9 && !ok; i ++)
        if (cnt[i] == 2) ok = 1;
    if (ok) puts("Elephant");
        else puts("Bear");
    return 0;
}