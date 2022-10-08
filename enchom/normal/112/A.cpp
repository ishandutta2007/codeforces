#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long Int;

char str1[101],str2[101];
Int L1,L2;
int main()
{
    string a,b;
    Int i;
    
    cin>>a;
    cin>>b;
    
    L1=a.length();
    
    for (i=0;i<L1;i++)
    {
        str1[i+1]=a[i];
    }
    
    L2=b.length();
    
    for (i=0;i<L2;i++)
    {
        str2[i+1]=b[i];
    }
    
    for (i=1;i<=L1;i++)
    {
        if (str1[i]>='A' && str1[i]<='Z')
        {
            str1[i]=str1[i]+('a'-'A');
        }
    }
    
    for (i=1;i<=L2;i++)
    {
        if (str2[i]>='A' && str2[i]<='Z')
        {
            str2[i]=str2[i]+('a'-'A');
        }
    }
    
    for (i=1;i<=L1;i++)
    {
        if (str1[i]<str2[i])
        {
            printf("-1\n");
            return 0;
        }
        else if (str1[i]>str2[i])
        {
            printf("1\n");
            return 0;
        }
    }
    printf("0\n");
    return 0;
}