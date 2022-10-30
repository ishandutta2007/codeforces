#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#define N 8020
using namespace std;

char o[N];

int main(void)
{
    int t, a, b, c;
    int i, k;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d %d", &a, &b, &c);
        k = 0;
        if(a)
            for(i = 0; i < a + 1; i ++)
                o[k ++] = '0';
        if(b)
        {
            if(!a)
                o[k ++] = '0';
            for(i = 0; i < b; i ++)
                o[k ++] = i & 1 ? '0' : '1';
        }
        if(c)
        {
            if(b % 2)
                for(i = 0; i < c; i ++)
                    o[k ++] = '1';
            else if(!b)
                for(i = 0; i < c + 1; i ++)
                    o[k ++] = '1';
            else
            {
                k --;
                for(i = 0; i < c; i ++)
                    o[k ++] = '1';
                o[k ++] = '0';
            }
        }
        o[k] = 0;
        puts(o);
    }

    return 0;
}