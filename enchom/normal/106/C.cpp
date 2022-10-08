#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int a[11],b[11],c[11],d[11];
Int F[1001][11];

int main()
{
    Int i,j,in;
    Int n,m;
    Int themaxmoney;
    Int currmoney;
    
    scanf("%I64d %I64d %I64d %I64d",&n,&m,&c[0],&d[0]);
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d %I64d %I64d",&a[i],&b[i],&c[i],&d[i]);
    }
    a[0]=1;
    b[0]=0;
    
    for (i=0;i<=n;i++)
    {
        F[i][0]=(i/(c[0]))*d[0];
        ///cout<<"F["<<i<<"][0]="<<F[i][0]<<endl;
    }
    for (i=1;i<=m;i++)
    {
        for (j=0;j<=n;j++)
        {
            themaxmoney=0;
            for (in=0;in<=a[i]/b[i];in++)
            {
                if ( c[i]*in<=j )
                {
                    currmoney=d[i]*in+F[ j-c[i]*in ][i-1];
                    if (currmoney>themaxmoney)
                    themaxmoney=currmoney;
                }
                else
                break;
            }
            F[j][i]=themaxmoney;
            ///cout<<"F["<<j<<"]["<<i<<"]="<<themaxmoney<<endl;
        }
    }
    printf("%I64d\n",F[n][m]);
    return 0;
}