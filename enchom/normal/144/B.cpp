#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

struct radiator
{
    Int x,y,r;
};

radiator rads[1001];

int main()
{
    Int xa,xb,ya,yb;
    Int d;
    Int n;
    Int X,Y;
    Int distanceusq;
    bool covered;
    Int counter=0;
    Int i,j;

    scanf("%I64d %I64d %I64d %I64d",&xa,&ya,&xb,&yb);

    if (xa>xb)
    {
        d=xa;
        xa=xb;
        xb=d;
    }
    if (ya>yb)
    {
        d=ya;
        ya=yb;
        yb=d;
    }

    scanf("%I64d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d %I64d",&rads[i].x,&rads[i].y,&rads[i].r);
    }

    for (i=xa;i<=xb;i++)
    {
        ///Bottom line
        X=i;
        Y=ya;
        covered=false;
        for (j=1;j<=n;j++)
        {
            distanceusq=(X-rads[j].x)*(X-rads[j].x) + (Y-rads[j].y)*(Y-rads[j].y);

            if (distanceusq<=rads[j].r*rads[j].r)
            {
                covered=true;
                break;
            }
        }
        if (!covered)
        {
            counter++;
        }

        ///Top line
        X=i;
        Y=yb;
        covered=false;
        for (j=1;j<=n;j++)
        {
            distanceusq=(X-rads[j].x)*(X-rads[j].x) + (Y-rads[j].y)*(Y-rads[j].y);

            if (distanceusq<=rads[j].r*rads[j].r)
            {
                covered=true;
                break;
            }
        }
        if (!covered)
        {
            counter++;
        }
    }

    for (i=ya+1;i<=yb-1;i++)
    {
        ///Left line
        X=xa;
        Y=i;
        covered=false;
        for (j=1;j<=n;j++)
        {
            distanceusq=(X-rads[j].x)*(X-rads[j].x) + (Y-rads[j].y)*(Y-rads[j].y);

            if (distanceusq<=rads[j].r*rads[j].r)
            {
                covered=true;
                break;
            }
        }
        if (!covered)
        {
            counter++;
        }

        ///Right line
        X=xb;
        Y=i;
        covered=false;
        for (j=1;j<=n;j++)
        {
            distanceusq=(X-rads[j].x)*(X-rads[j].x) + (Y-rads[j].y)*(Y-rads[j].y);

            if (distanceusq<=rads[j].r*rads[j].r)
            {
                covered=true;
                break;
            }
        }
        if (!covered)
        {
            counter++;
        }
    }

    printf("%I64d\n",counter);

    return 0;
}