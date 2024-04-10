#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long Int;

char names[17][11];
bool hates[17][17];
Int nL[17];
char arr[11],arrL;
Int took[17],tL=0;
Int n,m;
Int maxtL=-1,maxtook[17];

void Batrak(Int k)
{
    Int i,j;
    if (k>n)
    {
        for (i=1;i<=tL;i++)
        {
            for (j=i+1;j<=tL;j++)
            {
                if ( hates[took[i]][took[j]] )
                {
                    return;
                }
            }
        }
        if (tL>maxtL)
        {
            maxtL=tL;
            for (i=1;i<=maxtL;i++)
            {
                maxtook[i]=took[i];
            }
        }
        return;
    }
    
    tL++;
    took[tL]=k;
    Batrak(k+1);
    tL--;
    
    Batrak(k+1);
}

bool Same(char a[],Int L1,char b[],Int L2)
{
    Int i;
    if (L1!=L2)
    return false;
    
    for (i=1;i<=L1;i++)
    {
        if (a[i]!=b[i])
        return false;
    }
    return true;
}

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

bool Less(char a[],Int L1,char b[],Int L2)
{
    Int i;
    for (i=1;i<=MIN(L1,L2);i++)
    {
        if (a[i]<b[i])
        return true;
        
        else if (b[i]<a[i])
        return false;
    }
    if (L1<L2)
    return true;
    else
    return false;
}

int main()
{
    Int i,j,in;
    Int first;
    Int second;
    string s,s2;
    bool TFO[17];
    Int element;
    char themin[11],themL=0;
    
    scanf("%I64d",&n);
    scanf("%I64d",&m);
    
    for (i=0;i<=16;i++)
    {
        nL[i]=0;
    }
    for (i=0;i<=16;i++)
    {
        for (j=0;j<=16;j++)
        {
            hates[i][j]=false;
        }
    }
    for (i=1;i<=n;i++)
    {
        cin>>s;
        nL[i]=s.length();
        
        for (j=0;j<s.length();j++)
        {
            names[i][j+1]=s[j];
        }
    }
    for (i=1;i<=m;i++)
    {
        cin>>s>>s2;
        for (j=0;j<s.length();j++)
        {
            arr[j+1]=s[j];
        }
        arrL=s.length();
        
        for (j=1;j<=n;j++)
        {
            if ( Same(names[j],nL[j],arr,arrL) )
            {
                first=j;
                break;
            }
        }
        
        for (j=0;j<s2.length();j++)
        {
            arr[j+1]=s2[j];
        }
        arrL=s2.length();
        
        for (j=1;j<=n;j++)
        {
            if ( Same(names[j],nL[j],arr,arrL) )
            {
                second=j;
                break;
            }
        }
        
        hates[first][second]=true;
        hates[second][first]=true;
    }
    Batrak(1);
    printf("%I64d\n",maxtL);
    
    for (i=0;i<=16;i++)
    {
        TFO[i]=false;
    }
    
    for (i=1;i<=maxtL;i++)
    {
        themL=1;
        themin[1]='z'+1;
        element=-1;
        for (j=1;j<=maxtL;j++)
        {
            if (TFO[j])
            continue;
            
            if ( Less( names[maxtook[j]],nL[maxtook[j]],themin,themL ) )
            {
                themL=nL[ maxtook[j] ];
                element=j;
                for (in=1;in<=themL;in++)
                {
                    themin[in]=names[ maxtook[j] ][in];
                }
            }
        }
        for (j=1;j<=themL;j++)
        {
            printf("%c",themin[j]);
        }
        printf("\n");
        TFO[element]=true;
    }
    return 0;
}