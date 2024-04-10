#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void)
{
    int t, a[2], b[2];
    int i, j;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d %d %d", &a[0], &a[1], &b[0], &b[1]);
        for(i = 0; i < 2; i ++)
        {
            for(j = 0; j < 2; j ++)
                if(a[i] == b[j] && a[!i] + b[!j] == a[i])
                    break;
            if(j < 2)
                break;
        }
        printf("%s\n", i < 2 ? "yEs" : "nO");
    }

    return 0;
}