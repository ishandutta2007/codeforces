#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long Int;

char str[100001];
Int sL;

int main()
{
    string s;
    Int i;
    Int n,k;
    
    scanf("%I64d %I64d",&n,&k);
    
    cin>>s;
    
    for (i=0;i<s.length();i++)
    {
        str[i+1]=s[i];
    }
    sL=s.length();
    for (i=1;i<=sL-1;i++)
    {
        if (k==0)
        break;
        
        if (str[i]!='4' || str[i+1]!='7')
        continue;
        
        if (i%2==1)
        {
            if (i!=sL-1)
            {
                if (str[i+2]=='7')
                {
                    k=k%2;
                    if (k==1)
                    {
                        str[i+1]='4';
                        k=0;
                    }
                }
                else
                {
                    str[i+1]='4';
                    k--;
                }
            }
            else
            {
                str[i+1]='4';
                k--;
            }
        }
        else
        {
            if (i!=1)
            {
                if (str[i-1]=='4')
                {
                    k=k%2;
                    if (k==1)
                    {
                        str[i]='7';
                        k=0;
                    }
                }
                else
                {
                    str[i]='7';
                    k--;
                }
            }
            else
            {
                str[i]='7';
                k--;
            }
        }
    }
    if (k>0)
    k=0;
    
    for (i=1;i<=sL;i++)
    {
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}