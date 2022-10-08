#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

char arr1[1000001];
char arr2[1000001];
Int L1,L2;

int main()
{
    Int i;
    Int type1ones=0,type2ones=0;
    
    
    scanf("%s",arr1);
    scanf("%s",arr2);
    
    L1=strlen(arr1);
    L2=strlen(arr2);
    
    if (L1!=L2)
    {
        printf("NO\n");
        return 0;
    }
    
    for (i=0;i<L1;i++)
    {
        if (arr1[i]=='1')
        {
            type1ones++;
        }
    }
    
    for (i=0;i<L2;i++)
    {
        if (arr2[i]=='1')
        {
            type2ones++;
        }
    }
    
    if ( (type2ones>0 && type1ones>0) || (type2ones==0 && type1ones==0) )
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    
    return 0;
}