#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long llong;

struct pt
{
    llong x, y;
};

int n;
pt pts[5111];
int p[5111];

bool obtuse(pt A, pt B, pt C)
{
    llong dp = (B.x - A.x) * (C.x - B.x) + (B.y - A.y) * (C.y - B.y);

    return dp >= 0;
}

int main()
{
    int i, j;

    scanf("%d", &n);

    for (i=1;i<=n;i++)
    {
        scanf("%lld %lld", &pts[i].x, &pts[i].y);
        p[i] = i;
    }

    bool change = true;
    while(change)
    {
        change = false;

        for (i=1;i<n-1;i++)
        {
            if (obtuse(pts[p[i]], pts[p[i+1]], pts[p[i+2]]))
            {
                swap(p[i+1], p[i+2]);
                change = true;
            }
        }
    }

    for (i=1;i<=n;i++)
    {
        printf("%d", p[i]);

        if (i != n)
            printf(" ");
    }
    printf("\n");

    return 0;
}