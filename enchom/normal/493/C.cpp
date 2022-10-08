#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n;
int a[300001];

int m;
int b[300001];

pair<int,bool> shots[500001];
int L=0;

bool SS(pair<int,bool> a,pair<int,bool> b)
{
    return a.first>b.first;
}

int main()
{
    int i;
    int k;
    int maxa,maxb;
    int cura,curb;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&k);

        L++;
        shots[L].first=k;
        shots[L].second=true;
    }

    scanf("%d",&m);

    for (i=1;i<=m;i++)
    {
        scanf("%d",&k);

        L++;
        shots[L].first=k;
        shots[L].second=false;
    }

    sort(shots+1,shots+1+L,SS);

    maxa=n*2;
    maxb=m*2;

    cura=n*2;
    curb=m*2;

    i=1;
    while(i<=L)
    {
        if (shots[i].second)
        cura++;
        else
        curb++;

        if (i!=L)
        {
            if (shots[i+1].first==shots[i].first)
            {
                i++;
                continue;
            }
        }

        if (cura-curb>maxa-maxb)
        {
            maxa=cura;
            maxb=curb;
        }
        else if (cura-curb==maxa-maxb && cura>maxa)
        {
            maxa=cura;
            maxb=curb;
        }

        i++;
    }

    printf("%d:%d\n",maxa,maxb);

    return 0;
}