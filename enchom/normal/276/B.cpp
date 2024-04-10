#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int amount[31];
char str[1001];

int main()
{
    Int i;
    Int L;
    Int ctr=0;
    
    scanf("%s",str);
    
    L=strlen(str);
    
    for (i=0;i<=30;i++)
    {
        amount[i]=0;
    }
    for (i=0;i<L;i++)
    {
        amount[ (Int)str[i]-(Int)'a' ]++;
    }
    
    for (i=0;i<=30;i++)
    {
        if (amount[i]%2==1)
        {
            ctr++;
        }
    }
    
    if (ctr==0)
    {
        printf("First\n");
        return 0;
    }
    
    if (ctr%2==1)
    {
        printf("First\n");
    }
    else
    {
        printf("Second\n");
    }
    
    return 0;
}