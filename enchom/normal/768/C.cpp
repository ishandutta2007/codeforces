#include <iostream>
#include <stdio.h>
using namespace std;

int n,k,x;
int ctr[2][2111];

int main()
{
    int i,j;
    int a;
    int cur,op;
    bool dofirst;

    scanf("%d %d %d",&n,&k,&x);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a);

        ctr[1][a]++;
    }

    op=1;

    for (i=1;i<=k;i++)
    {
        cur=i%2;
        op=cur^1;

        dofirst=true;
        for (j=0;j<=1024;j++)
        {
            if (ctr[cur][j]==0)
            continue;

            if (ctr[cur][j]%2==0)
            {
                ctr[op][ j^x ]+=ctr[cur][j]/2;
                ctr[op][ j ]+=ctr[cur][j]/2;
            }
            else
            {
                if (dofirst)
                {
                    ctr[op][ j ]+=ctr[cur][j]/2;
                    ctr[op][ j^x ]+=(ctr[cur][j]-ctr[cur][j]/2);
                }
                else
                {
                    ctr[op][ j^x ]+=ctr[cur][j]/2;
                    ctr[op][ j ]+=(ctr[cur][j]-ctr[cur][j]/2);
                }

                dofirst=!dofirst;
            }

            ctr[cur][j]=0;
        }
    }

    for (i=1024;i>=0;i--)
    {
        if (ctr[op][i]>0)
        {
            printf("%d ",i);
            break;
        }
    }

    for (i=0;i<=1024;i++)
    {
        if (ctr[op][i]>0)
        {
            printf("%d\n",i);
            break;
        }
    }



    return 0;
}