#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main(void)
{
    int t, a[3], b[3];
    int i, o;

    scanf("%d", &t);
    while(t --)
    {
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        sort(a, a + 3);
        o = (a[1] - a[0]) + (a[2] - a[1]) + (a[2] - a[0]);
        for(i = 0; i < 27; i ++)
        {
            b[0] = a[0];
            b[1] = a[1];
            b[2] = a[2];
            if(i % 3 == 1)
                b[0] ++;
            else if(i % 3 == 2)
                b[0] --;
            if((i / 3) % 3 == 1)
                b[1] ++;
            else if((i / 3) % 3 == 2)
                b[1] --;
            if((i / 9) % 3 == 1)
                b[2] ++;
            else if((i / 9) % 3 == 2)
                b[2] --;

            sort(b, b + 3);
            o = min(o, (b[1] - b[0]) + (b[2] - b[1]) + (b[2] - b[0]));
        }
        printf("%d\n", o);
    }

    return 0;
}