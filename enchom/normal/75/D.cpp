#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

struct help
{
    Int largestprefix,largestsuffix,largestnum,largestsum,totalsum;
};
struct dp
{
    Int maxwithend,regularmax;
};

dp F[250001];
Int arrs[51][5001];
Int Len[51];
help statistics[51];

Int MAX(Int a,Int b)
{
    if (a>b)
    return a;
    else
    return b; 
}

int main()
{
    Int n,m;
    Int L;
    Int i,j;
    Int maxnum=-999999999;
    Int maxsum,maxmax;
    Int maxix;
    Int k;
    Int maxatall;
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&L);
        
        Len[i]=L;
        
        for (j=1;j<=L;j++)
        {
            scanf("%I64d",&arrs[i][j]);
        }
    }
    
    for (i=1;i<=n;i++)
    {
        maxnum=-999999999;
        for (j=1;j<=Len[i];j++)
        {
            if (arrs[i][j]>maxnum)
            maxnum=arrs[i][j];
        }
        statistics[i].largestnum=maxnum;
        
        maxsum=0;
        maxmax=0;
        for (j=1;j<=Len[i];j++)
        {
            maxsum+=arrs[i][j];
            if (maxsum<0)
            maxsum=0;
            
            if (maxsum>maxmax)
            maxmax=maxsum;
        }
        if (maxmax==0)
        maxmax=maxnum;
        
        statistics[i].largestsum=maxmax;
        
        
        maxix=0;
        maxmax=-999999999;
        for (j=1;j<=Len[i];j++)
        {
            maxix+=arrs[i][j];
            
            if (maxix>maxmax)
            maxmax=maxix;
        }
        statistics[i].largestprefix=maxmax;
        
        maxix=0;
        maxmax=-999999999;
        for (j=Len[i];j>=1;j--)
        {
            maxix+=arrs[i][j];
            
            if (maxix>maxmax)
            maxmax=maxix;
        }
        statistics[i].totalsum=maxix;
        statistics[i].largestsuffix=maxmax;
    }
    
    scanf("%I64d",&k);
    F[1].maxwithend=statistics[k].largestsuffix;
    F[1].regularmax=statistics[k].largestsum;
    maxatall=MAX(F[1].maxwithend,F[1].regularmax);
    for (i=2;i<=m;i++)
    {
        scanf("%I64d",&k);
        
        F[i].maxwithend=MAX( statistics[k].totalsum+F[i-1].maxwithend,statistics[k].largestsuffix );
        F[i].regularmax=MAX( statistics[k].largestsum,statistics[k].largestprefix+F[i-1].maxwithend );
        
        if (maxatall<MAX(F[i].maxwithend,F[i].regularmax))
        {
            maxatall=MAX(F[i].maxwithend,F[i].regularmax);
        }
    }
    printf("%I64d\n",maxatall);
    return 0;
}