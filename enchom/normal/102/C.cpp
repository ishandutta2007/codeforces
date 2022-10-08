#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long Int;

char str[100001];
Int sL;
Int letters[27][100001];
Int L[27];
bool TFO[100001];

int main()
{
    Int k;
    Int i,j;
    string s;
    Int minlet;
    Int mlet;
    Int difdigits;
    
    cin>>s;
    scanf("%I64d",&k);
    
    for (i=0;i<s.length();i++)
    {
        str[i+1]=s[i];
    }
    sL=s.length();
    for (i=0;i<=26;i++)
    L[i]=0;
    
    for (i=1;i<=sL;i++)
    {
        L[ str[i]-'a' ]++;
        letters[ str[i]-'a' ][ L[ str[i]-'a' ] ]=i;
    }
    
    if (k>=sL)
    {
        printf("0\n\n");
        return 0;
    }
    
    for (i=0;i<=100000;i++)
    TFO[i]=false;
    
    difdigits=0;
    
    for (i=0;i<=26;i++)
    {
        if (L[i]>0)
        difdigits++;
    }
    
    while(k>0)
    {
        minlet=999999999;
        for (i=0;i<=26;i++)
        {
            if (L[i]<minlet && L[i]>0)
            {
                minlet=L[i];
                mlet=i;
            }
        }
        if (k<minlet)
        {
            k=0;
            continue;
        }
        else
        {
            k-=minlet;
            difdigits--;
        }
        for (i=1;i<=L[mlet];i++)
        {
            TFO[ letters[mlet][i] ]=true;
        }
        L[mlet]=0;
    }
    
    printf("%I64d\n",difdigits);
    for (i=1;i<=sL;i++)
    {
        if (!TFO[i])
        printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}