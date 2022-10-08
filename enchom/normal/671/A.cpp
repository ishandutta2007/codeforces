#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long double Double;
typedef long long Int;

Double Dist[100111];
Double D1[100111];
Double D2[100111];
pair<Double,int> W1[100111];
pair<Double,int> W2[100111];

int n;
pair<int,int> pts[100111];
int Ax,Ay,Bx,By,x,y;

Int Sq(Int a)
{
    return a*a;
}

Double GetDist(int x1,int y1,int x2,int y2)
{
    return sqrt( (Double)(Sq( (Int)x1-(Int)x2 )) + (Double)(Sq( (Int)y1-(Int)y2 )) );
}

Double MIN(Double a,Double b)
{
    if (a<b)
    return a;
    else
    return b;
}

int main()
{
    int i;
    Double maxwin;
    Double ans1,ans2,ans3;

    scanf("%d %d %d %d %d %d",&Ax,&Ay,&Bx,&By,&x,&y);

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d",&pts[i].first,&pts[i].second);

        Dist[i]=GetDist(pts[i].first,pts[i].second,x,y);

        D1[i]=GetDist(pts[i].first,pts[i].second,Ax,Ay)+GetDist(pts[i].first,pts[i].second,x,y);
        D2[i]=GetDist(pts[i].first,pts[i].second,Bx,By)+GetDist(pts[i].first,pts[i].second,x,y);

        W1[i].first=2.0*Dist[i]-D1[i];
        W2[i].first=2.0*Dist[i]-D2[i];

        W1[i].second=i;
        W2[i].second=i;
    }

    sort(W1+1,W1+1+n);
    reverse(W1+1,W1+1+n);

    sort(W2+1,W2+1+n);
    reverse(W2+1,W2+1+n);

    ///Use only first
    ans1=0;
    for (i=1;i<=n;i++)
    {
        ans1+=2.0*Dist[i];
    }
    ans1-=W1[1].first;

    ///Use second only
    ans2=0;
    for (i=1;i<=n;i++)
    {
        ans2+=2.0*Dist[i];
    }
    ans2-=W2[1].first;

    if (n==1)
    {
        printf("%.8f\n",(double)MIN(ans1,ans2));
        return 0;
    }

    ///Use both
    ans3=0.0;
    for (i=1;i<=n;i++)
    {
        ans3+=2.0*Dist[i];
    }

    if (W1[1].second!=W2[1].second)
    {
        ans3-=W1[1].first;
        ans3-=W2[1].first;
    }
    else if (W1[1].first+W2[2].first > W1[2].first+W2[1].first)
    {
        ans3-=W1[1].first;
        ans3-=W2[2].first;
    }
    else
    {
        ans3-=W1[2].first;
        ans3-=W2[1].first;
    }

    printf("%.8f\n",(double)MIN( MIN(ans1,ans2),ans3 ));

    return 0;
}