#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int canreach[51][51];
bool table[51][51];
char inp;
Int Key=1;
Int n,m;

void Check(Int dir,Int x,Int y,bool turned)
{
    if (x<1 || x>n || y<1 || y>m)
    return;
    if (!table[x][y])
    return;
    
    canreach[x][y]=Key;
    
    Int newx=x,newy=y;
    
    if (dir==1)
    newy++;
    if (dir==2)
    newx++;
    if (dir==3)
    newy--;
    if (dir==4)
    newx--;
    
    Check(dir,newx,newy,turned);
    
    if (!turned)
    {
        Int i;
        for (i=1;i<=4;i++)
        {
            if (i!=dir)
            {
                Check(i,x,y,true);
            }
        }
    }
}

int main()
{
    Int i,j,in,ja;
    
    for (i=0;i<=50;i++)
    {
        for (j=0;j<=50;j++)
        {
            table[i][j]=false;
            canreach[i][j]=0;
        }
    }
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            scanf("%c",&inp);
            
            if (inp!='W' && inp!='B')
            {
                j--;
                continue;
            }
            if (inp=='W')
            table[i][j]=false;
            else
            table[i][j]=true;
        }
    }
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (!table[i][j])
            continue;
            
            for (in=1;in<=n;in++)
            {
                for (ja=1;ja<=m;ja++)
                {
                    if (!table[in][ja])
                    {
                        canreach[in][ja]=Key;
                    }
                }
            }
            Check(1,i,j,false);
            Check(2,i,j,false);
            Check(3,i,j,false);
            Check(4,i,j,false);
            for (in=1;in<=n;in++)
            {
                for (ja=1;ja<=m;ja++)
                {
                    if (canreach[in][ja]!=Key)
                    {
                        printf("NO\n");
                        return 0;
                    }
                }
            }
            Key++;
        }
    }
    printf("YES\n");
    return 0;
}