#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

Int bc[1001][1001];
Int rc[1001];

Int bm[1001][1001];
Int rm[1001];

int main()
{
    Int n,m;
    Int a,b;
    Int i,j;
    Int beauty=0,total=0;
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=0;i<=1000;i++)
    {
        rc[i]=0;
        rm[i]=0;
        for (j=0;j<=1000;j++)
        {
            bm[i][j]=0;
            bc[i][j]=0;
        }
    }
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        bm[a][b]++;
        rm[b]++;
    }
    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        bc[a][b]++;
        rc[b]++;
    }
    
    for (i=1;i<=1000;i++)
    {
        for (j=1;j<=1000;j++)
        {
            if (bc[i][j]>bm[i][j])
            {
                rc[j]=rc[j]-bm[i][j];
                beauty=beauty+bm[i][j];
                bc[i][j]=bc[i][j]-bm[i][j];
                rm[j]=rm[j]-bm[i][j];
                bm[i][j]=0;
            }
            else if (bc[i][j]==bm[i][j])
            {
                rc[j]=rc[j]-bc[i][j];
                beauty=beauty+bc[i][j];
                rm[j]=rm[j]-bc[i][j];
                bc[i][j]=0;
                bm[i][j]=0;
            }
            else if (bc[i][j]<bm[i][j])
            {
                rc[j]=rc[j]-bc[i][j];
                beauty=beauty+bc[i][j];
                rm[j]=rm[j]-bc[i][j];
                bm[i][j]=bm[i][j]-bc[i][j];
                bc[i][j]=0;
            }
        }
    }
    total=beauty;
    for (i=1;i<=1000;i++)
    {
        if (rc[i]>rm[i])
        {
            total=total+rm[i];
        }
        else
        {
            total=total+rc[i];
        }
    }
    printf("%I64d %I64d",total,beauty);
    return 0;
}