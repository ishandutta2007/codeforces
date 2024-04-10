#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;
typedef long double Double;

int homeX,homeY;
int uniX,uniY;
int n;

Double CP(Double x1,Double y1,Double x2,Double y2)
{
    return x1*y2-x2*y1;
}

bool Intersects(int a,int b,int c)
{
    Double X,Y;
    Double CP1,CP2;
    Double RX,RY;

    if (b==0)
    {
        X=(Double)(-c) / (Double)(a);
        Y=0.0;

        RX=X;
        RY=1.0;
    }
    else
    {
        X=0.0;
        Y=( (Double)(-c)-X*(Double)(a) )/(Double)(b);

        RX=1.0;
        RY=( (Double)(-c)-RX*(Double)(a) )/(Double)(b);
    }

    CP1=CP(RX-X,RY-Y,(Double)homeX-X,(Double)homeY-Y);
    CP2=CP(RX-X,RY-Y,(Double)uniX-X,(Double)uniY-Y);

    if (CP1<0.0 && CP2<0.0)
    return false;
    else if (CP1>0.0 && CP2>0.0)
    return false;
    else
    return true;
}

int main()
{
    int i;
    int ans=0;
    int c;
    int lineA,lineB,lineC;

    scanf("%d %d",&homeX,&homeY);
    scanf("%d %d",&uniX,&uniY);

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d %d",&lineA,&lineB,&lineC);

        if (Intersects(lineA,lineB,lineC))
        ans++;
    }

    printf("%d\n",ans);

    return 0;
}