#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
using namespace std;
typedef long long Int;

char str[1000001];
Int H=0,Q=0;
char source[1000001];
Int sL=0;
char generated[2000001];
Int gL=-1;

int main()
{
    Int L;
    Int i,j;
    Int p,k;
    Int x;
    Int len;
    
    scanf("%s",str);
    
    L=strlen(str);
    
    for (i=0;i<L;i++)
    {
        if (str[i]=='H')
        H++;
        else
        Q++;
    }
    p=-1;
    for (i=0;i<=1000;i++)
    {
        if (i*i==Q)
        {
            p=i;
            break;
        }
    }
    
    if (p==-1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    
    if (H%(p+1)!=0)
    {
        cout<<"No"<<endl;
        return 0;
    }
    else
    {
        k=H/(p+1);
    }
    
    if (Q==0)
    {
        cout<<"Yes"<<endl;
        return 0;
    }
    
    
    for (i=0;i<L;i++)
    {
        if (str[i]=='Q')
        {
            x=i;
            break;
        }
    }
    
    if (x%2==1)
    {
        cout<<"No"<<endl;
        return 0;
    }
    
    
    
    for (i=1;i<=x/2;i++)
    {
        sL++;
        source[sL]='H';
    }
    sL++;
    source[sL]='Q';
    
    len=(p+k)-sL;
    
    for (i=x+1;i<=x+len;i++)
    {
        sL++;
        source[sL]=str[i];
    }
    
    for (i=1;i<=sL;i++)
    {
        if (source[i]=='H')
        {
            gL++;
            generated[gL]='H';
            
            if (gL>=L)
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
        else
        {
            for (j=1;j<=sL;j++)
            {
                gL++;
                generated[gL]=source[j];
                
                if (gL>=L)
                {
                    cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    
    if (gL+1!=L)
    {
        cout<<"No"<<endl;
        return 0;
    }
    else
    {
        for (i=0;i<L;i++)
        {
            if (generated[i]!=str[i])
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    
    cout<<"Yes"<<endl;
    
    return 0;
}