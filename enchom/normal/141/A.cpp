#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long Int;

Int letters1[30];
Int letters2[30];

int main()
{
    string a;
    string b;
    string c;
    Int i,j;
    
    cin>>a>>b>>c;
        
    for (i=0;i<=29;i++)
    {
        letters1[i]=0;
        letters2[i]=0;
    }
    for (i=0;i<a.length();i++)
    {
        letters1[ a[i]-'A' ]++;
    }
    for (i=0;i<b.length();i++)
    {
        letters1[ b[i]-'A' ]++;
    }
    for (i=0;i<c.length();i++)
    {
        letters2[ c[i]-'A' ]++;
    }
    for (i=0;i<=29;i++)
    {
        if (letters1[i]!=letters2[i])
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}