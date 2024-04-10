#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

char str[51];
Int sL=0;
Int maxseen=-1;
char best[51];
Int bL=-1;

bool Lucky(Int x,Int y)
{
    Int i;
    
    for (i=x;i<=y;i++)
    {
        if (str[i]!='4' && str[i]!='7')
        return false;
    }
    return true;
}

bool IsLower(Int x,Int y)
{
    Int i;
    for (i=x;i<=y;i++)
    {
        if (i-x+1>bL)
        break;
        
        if (str[i]<best[i-x+1])
        return true;
        else if (str[i]>best[i-x+1])
        return false;
    }
    if (y-x+1<bL)
    return true;
    else
    return false;
}

int main()
{
    string s;
    Int i,j,in,ja;
    Int seen;
    Int L;
    bool flag;
    
    cin>>s;
    
    sL=s.length();
    
    for (i=0;i<sL;i++)
    {
        str[i+1]=s[i];
    }
    
    for (i=1;i<=sL;i++)
    {
        for (j=i;j<=sL;j++)
        {
            if ( Lucky(i,j) )
            {
                L=j-i+1;
                seen=0;
                for (in=1;in<=sL;in++)
                {
                    flag=true;
                    for (ja=in;ja<=in+L-1;ja++)
                    {
                        if (str[ja]!=str[ (ja-in+1)+i-1 ])
                        {
                            flag=false;
                            break;
                        }
                    }
                    if (flag)
                    seen++;
                }
                if (seen>maxseen)
                {
                    maxseen=seen;
                    for (in=1;in<=L;in++)
                    {
                        best[in]=str[in+i-1];
                    }
                    bL=L;
                }
                else if (seen==maxseen)
                {
                    if (bL!=-1)
                    {
                        if ( IsLower(i,j) )
                        {
                            maxseen=seen;
                            for (in=1;in<=L;in++)
                            {
                                best[in]=str[in+i-1];
                            }
                            bL=L;
                        }
                    }
                    else
                    {
                        maxseen=seen;
                        for (in=1;in<=L;in++)
                        {
                            best[in]=str[in+i-1];
                        }
                        bL=L;
                    }
                }
            }
        }
    }
    if (bL==-1)
    printf("-1\n");
    else
    {
        for (i=1;i<=bL;i++)
        {
            printf("%c",best[i]);
        }
        printf("\n");
    }
    return 0;
}