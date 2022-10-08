#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

char str[200001];
char str2[200001];
Int sL=0;
Int sL2=0;

int main()
{
    string a;
    Int i;
    
    cin>>a;
    
    for (i=0;i<a.length();i++)
    {
        str[i+1]=a[i];
    }
    sL=a.length();
    
    str2[0]='-';
    
    for (i=1;i<=sL;i++)
    {
        sL2++;
        str2[sL2]=str[i];
        if (str2[sL2]==str2[sL2-1])
        {
            sL2=sL2-2;
        }
    }
    
    for (i=1;i<=sL2;i++)
    printf("%c",str2[i]);
    printf("\n");
    return 0;
}