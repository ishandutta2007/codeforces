#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
typedef long long Int;

struct cell
{
    Int x,y;
};

char table[31][31];
cell shifts[1001];
Int shf=0;
double closest[26];
bool exists[26];

double ABS(double a)
{
    if (a<0.0)
    return a*-1.0;
    else
    return a;
}

double Distance(Int x1,Int y1,Int x2,Int y2)
{
    double a=(double)x1,b=(double)y1,c=(double)x2,d=(double)y2;
    double ans;
    
    ans=sqrt( ( ABS(x1-x2)*ABS(x1-x2) )+( ABS(y1-y2)*ABS(y1-y2) ) );
    
    return ans;
}

int main()
{
    double x;
    Int n,m,q;
    Int i,j,in;
    Int hand=0;
    char ch;
    double dist;
    
    scanf("%I64d %I64d %lf",&n,&m,&x);
    
    for (i=0;i<=25;i++)
    {
        closest[i]=-1.0;
        exists[i]=false;
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            cin>>table[i][j];
            if (table[i][j]=='S')
            {
                shf++;
                shifts[shf].x=i;
                shifts[shf].y=j;
            }
            else
            {
                exists[ table[i][j]-'a' ]=true;
            }
        }
    }
    
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (table[i][j]!='S')
            {
                for (in=1;in<=shf;in++)
                {
                    dist=Distance(i,j,shifts[in].x,shifts[in].y);
                    if (dist<closest[ table[i][j]-'a' ] || closest[ table[i][j]-'a' ]==-1)
                    {
                        closest[ table[i][j]-'a' ]=dist;
                    }
                }
            }
        }
    }
    
    scanf("%I64d",&q);
    scanf("%c",&ch);
    
    for (i=1;i<=q;i++)
    {
        scanf("%c",&ch);
        if (ch<='z' && ch>='a')
        {
            if ( !exists[ch-'a'] )
            {
                printf("-1\n");
                return 0;
            }
        }
        else
        {
            ch=ch+('a'-'A');
            if ( !exists[ch-'a'] || closest[ch-'a']==-1 )
            {
                printf("-1\n");
                return 0;
            }
            
            if ( closest[ch-'a']>x )
            hand++;
        }
    }
    
    printf("%I64d\n",hand);
    return 0;
}