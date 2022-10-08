#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

struct edge
{
    Int c1,c2;
};

Int coolcolorshit[100001];
Int c[100001];
edge edges[100001];
Int eL=0;
bool exists[100001];

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}
Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b;
}

bool SrtEdges(edge a,edge b)
{
    if (a.c1<b.c1)
    return true;
    else if (a.c1>b.c1)
    return false;
    else
    {
        return (a.c2<b.c2);
    }
}

int main()
{
    Int n,m;
    Int i;
    Int a,b;
    Int getmax=0;
    
    for (i=0;i<=100000;i++)
    {
        coolcolorshit[i]=0;
        c[i]=0;
        exists[i]=false;
    }
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&c[i]);
        exists[ c[i] ]=true;
    }
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        
        if (c[a]==c[b])
        continue;
        
        eL++;
        edges[eL].c1=MIN(c[a],c[b]);
        edges[eL].c2=MAX(c[a],c[b]);
    }
    
    sort(edges+1,edges+1+eL,SrtEdges);
    
    for (i=1;i<=eL;i++)
    {
        if (i==1 || edges[i].c1!=edges[i-1].c1 || edges[i].c2!=edges[i-1].c2 )
        {
            coolcolorshit[ edges[i].c1 ]++;
            coolcolorshit[ edges[i].c2 ]++;
        }
    }
    for (i=1;i<=100000;i++)
    {
        if (!exists[i])
        continue;
        
        if (coolcolorshit[i]>getmax)
        getmax=coolcolorshit[i];
    }
    for (i=1;i<=100000;i++)
    {
        if (!exists[i])
        continue;
        
        if (coolcolorshit[i]==getmax)
        {
            printf("%I64d\n",i);
            break;
        }
    }
    
    return 0;
}