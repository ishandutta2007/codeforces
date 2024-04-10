#include <iostream>
#include <stdio.h>
using namespace std;

struct rect
{
    int x1,y1,x2,y2;
};

int n;
const int INF = 1000000001;
rect rects[500111];

int MIN(int a,int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int MAX(int a,int b)
{
    if (a > b)
        return a;
    else
        return b;
}

bool zeroMerge(int a,int b)
{
    int X1 = MAX(rects[a].x1, rects[b].x1);
    int Y1 = MAX(rects[a].y1, rects[b].y1);
    int X2 = MIN(rects[a].x2, rects[b].x2);
    int Y2 = MIN(rects[a].y2, rects[b].y2);

    return (X1 > X2 || Y1 > Y2);
}

bool tryWithout(int k)
{
    int X1 = -INF;
    int Y1 = -INF;
    int X2 = INF;
    int Y2 = INF;
    int i;

    for (i=1;i<=n;i++)
    {
        if (i == k)
            continue;

        X1 = MAX(X1, rects[i].x1);
        Y1 = MAX(Y1, rects[i].y1);
        X2 = MIN(X2, rects[i].x2);
        Y2 = MIN(Y2, rects[i].y2);

        if (X1 > X2 || Y1 > Y2)
        {
            return false;
        }
    }

    printf("%d %d\n",X1,Y1);

    return true;
}

void solveConflict(int k)
{
    int i;

    for (i=1;i<k;i++)
    {
        if (zeroMerge(i,k))
        {
            if (!tryWithout(i))
            {
                tryWithout(k);
            }

            break;
        }
    }

    return;
}

int main()
{
    int i;
    int X1,Y1,X2,Y2;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&rects[i].x1,&rects[i].y1,&rects[i].x2,&rects[i].y2);
    }

    X1 = rects[1].x1;
    Y1 = rects[1].y1;
    X2 = rects[1].x2;
    Y2 = rects[1].y2;

    for (i=2;i<=n-1;i++)
    {
        X1 = MAX(X1, rects[i].x1);
        Y1 = MAX(Y1, rects[i].y1);
        X2 = MIN(X2, rects[i].x2);
        Y2 = MIN(Y2, rects[i].y2);

        if (X1 > X2 || Y1 > Y2)
        {
            solveConflict(i);
            return 0;
        }
    }

    printf("%d %d\n",X1,Y1);

    return 0;
}