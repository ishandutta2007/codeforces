#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long Int;
typedef long double Double;

struct point
{
    Int x,y;
};

point pts[100111];
int n;

Int gcd(Int a,Int b)
{
    if (a<0)
    a=-a;
    if (b<0)
    b=-b;

    Int r;

    while(b!=0)
    {
        r=a%b;
        a=b;
        b=r;
    }

    return a;
}

Double GetProb(int k)
{
    Double ans;

    if (n<100)
    {
        ans=(Double)( pow(2.0,n-k-1)-1.0 )/(Double)( pow(2.0,n)-1.0-(Double)n-(Double)( ((Int)n*((Int)n-1LL))/2LL ) );
    }
    else
    {
        ans=(Double)pow(0.5,k+1);
    }

    return ans;
}

Int ABS(Int a)
{
    if (a<0)
    return -a;
    else
    return a;
}

Double RemProb[101];

int main()
{
    //freopen("test.txt","r",stdin);

    int i,k;
    int nxt,prv;
    Int inside,border=0;
    Int Area=0;
    Double prob;
    Int CurArea,CurBorder;
    Int TheArea,SpecBorder,TheInside;
    Double answer=0.0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%lld %lld",&pts[i].x,&pts[i].y);
    }

    for (i=1;i<n;i++)
    {
        border=border+gcd( pts[i+1].x-pts[i].x,pts[i+1].y-pts[i].y );

        Area=Area+pts[i].x*pts[i+1].y-pts[i+1].x*pts[i].y;
    }

    border=border+gcd( pts[1].x-pts[n].x,pts[1].y-pts[n].y );

    Area=Area+pts[n].x*pts[1].y-pts[1].x*pts[n].y;

    Area/=2;

    if (Area<0)
    Area=-Area;

    inside=Area-border/2+1;

    for (k=1;k<=60;k++)
    {
        RemProb[k]=GetProb(k);
    }

    //

    for (i=1;i<=n;i++)
    {
        CurArea=0;
        CurBorder=0;
        for (k=1;k<=60 && k<=n-1;k++)
        {
            nxt=i+k;
            if (nxt>n)
            nxt-=n;

            prv=nxt-1;
            if (prv<1)
            prv+=n;

            prob=RemProb[k];

            CurArea=CurArea+(pts[prv].x*pts[nxt].y-pts[nxt].x*pts[prv].y);
            CurBorder=CurBorder+gcd(pts[nxt].x-pts[prv].x,pts[nxt].y-pts[prv].y);

            TheArea=CurArea+(pts[nxt].x*pts[i].y-pts[i].x*pts[nxt].y);

            SpecBorder=gcd(pts[i].x-pts[nxt].x,pts[i].y-pts[nxt].y);

            TheInside=ABS(TheArea/2)-(CurBorder+SpecBorder)/2+1;
            TheInside+=SpecBorder-1;

            answer+=prob*(Double)TheInside;

            //cout<<"Analzying segment "<<i<<"~"<<nxt<<endl;
            //cout<<"Inside we have "<<TheInside<<endl;
            //cout<<"Probability of kill is "<<prob<<endl;
            //cout<<"Area is "<<TheArea<<", we have border "<<CurBorder<<" and special border "<<SpecBorder<<endl;
            //cout<<endl;
        }
    }

    answer=(Double)inside-answer;

    printf("%.10f\n",(double)answer);

    return 0;
}