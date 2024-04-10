#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int MySet[21];
Int NewSet[21];
int n;
Int k;
Int BaseGrid[21][21];
Int MyGrid[21][21];
Int MyHelp[21][21];
const Int MOD=1000000007LL;

void PowerUp(Int p)
{
    int i,j,in;

    if (p==1)
    {
        for (i=1;i<=16;i++)
        {
            for (j=1;j<=16;j++)
            {
                MyGrid[i][j]=BaseGrid[i][j];
            }
        }

        return;
    }

    PowerUp(p/2);

    memset(MyHelp,0,sizeof(MyHelp));
    for (i=1;i<=16;i++)
    {
        for (j=1;j<=16;j++)
        {
            for (in=1;in<=16;in++)
            {
                MyHelp[i][j]+=MyGrid[i][in]*MyGrid[in][j];
                MyHelp[i][j]%=MOD;
            }
        }
    }

    if (p%2==1)
    {
        memset(MyGrid,0,sizeof(MyGrid));
        for (i=1;i<=16;i++)
        {
            for (j=1;j<=16;j++)
            {
                for (in=1;in<=16;in++)
                {
                    MyGrid[i][j]+=MyHelp[i][in]*BaseGrid[in][j];
                    MyGrid[i][j]%=MOD;
                }
            }
        }
    }
    else
    {
        for (i=1;i<=16;i++)
        {
            for (j=1;j<=16;j++)
            {
                MyGrid[i][j]=MyHelp[i][j];
            }
        }
    }

    return;
}

int main()
{
    int i,j,in;
    Int a,b;
    int c;

    MySet[1]=1;

    scanf("%d %lld",&n,&k);

    for (i=1;i<=n;i++)
    {
        scanf("%lld %lld %d",&a,&b,&c);
        c++;

        for (j=c+1;j<=16;j++)
        {
            MySet[j]=0;
        }

        if (i==n)
        {
            if (a==k)
            break;
            else
            b=k;
        }

        memset(BaseGrid,0,sizeof(BaseGrid));

        BaseGrid[1][1]=1;
        if (c>=2)
        BaseGrid[1][2]=1;
        for (j=2;j<=c-1;j++)
        {
            BaseGrid[j][j-1]=1;
            BaseGrid[j][j]=1;
            BaseGrid[j][j+1]=1;
        }
        BaseGrid[c][c]=1;
        if (c>=2)
        BaseGrid[c][c-1]=1;

        PowerUp(b-a);

        memset(NewSet,0,sizeof(NewSet));
        for (j=1;j<=c;j++)
        {
            for (in=1;in<=c;in++)
            {
                NewSet[in]+=MyGrid[j][in]*MySet[j];
                NewSet[in]%=MOD;
            }
        }

        for (j=1;j<=c;j++)
        {
            MySet[j]=NewSet[j];
        }
    }

    printf("%lld\n",MySet[1]);

    return 0;
}