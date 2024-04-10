#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

typedef long long Int;

char a[100001],b[100001];
Int aL=0,bL=0;

Int MIN(Int a,Int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int main()
{
    Int i;
    Int bad4=0,bad7=0;
    string k,c;
    Int kill;
    Int op=0;
    char ch;
    
    cin>>k;
    cin>>c;
    
    for (i=0;i<k.length();i++)
    {
        a[i+1]=k[i];
    }
    aL=k.length();
    
    for (i=0;i<c.length();i++)
    {
        b[i+1]=c[i];
    }
    bL=c.length();
    
    for (i=1;i<=aL;i++)
    {
        if (a[i]!=b[i])
        {
            if (a[i]=='7')
            bad7++;
            else if (a[i]=='4')
            bad4++;
        }
    }
    kill=MIN(bad4,bad7);
    
    op=op+kill;
    bad4=bad4-kill;
    bad7=bad7-kill;
    
    op=op+bad4;
    op=op+bad7;
    
    printf("%I64d\n",op);
    return 0;
}