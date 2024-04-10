#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int a[101][101];
Int b[101][101];

int main()
{
    Int na,nb,ma,mb;
    char ch;
    Int i,j,in,ja;
    Int bestvalue=-1;
    Int bestx,besty;
    Int cursum;
    
    scanf("%I64d %I64d",&na,&ma);
    
    for (i=1;i<=na;i++)
    {
        for (j=1;j<=ma;j++)
        {
            scanf("%c",&ch);
            
            if (ch==10 || ch==' ')
            {
                j--;
                continue;
            }
            if (ch=='1')
            a[i][j]=1;
            else
            a[i][j]=0;
        }
    }
    
    scanf("%I64d %I64d",&nb,&mb);
    
    for (i=1;i<=nb;i++)
    {
        for (j=1;j<=mb;j++)
        {
            scanf("%c",&ch);
            
            if (ch==10 || ch==' ')
            {
                j--;
                continue;
            }
            if (ch=='1')
            b[i][j]=1;
            else
            b[i][j]=0;
        }
    }
    
    for (i=-50;i<=50;i++)
    {
        for (j=-50;j<=50;j++)
        {
            cursum=0;
            for (in=1;in<=na;in++)
            {
                if (in+i<1 || in+i>nb)
                {
                    continue;
                }
                for (ja=1;ja<=ma;ja++)
                {
                    if (j+ja<1 || j+ja>mb || in+i<1 || in+i>nb)
                    continue;
                    
                    cursum=cursum+a[in][ja]*b[in+i][ja+j];
                }
            }
            if (cursum>bestvalue)
            {
                bestvalue=cursum;
                bestx=i;
                besty=j;
            }
        }
    }
    cout<<bestx<<" "<<besty<<endl;
    return 0;
}