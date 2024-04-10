#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long Int;

Int nums[4]={0,0,0,0};
char inp[101];
Int L;
Int NUMS[1001];
Int n=0;

int main()
{
    Int i,j;

    scanf("%s",inp);
    L=strlen(inp);

    for (i=0;i<L;i++)
    {
        if (inp[i]!='+')
        {
            nums[ inp[i]-'0' ]++;
        }
    }

    for (i=1;i<=3;i++)
    {
        for (j=1;j<=nums[i];j++)
        {
            n++;
            NUMS[n]=i;
        }
    }

    for (i=1;i<=n;i++)
    {
        printf("%I64d",NUMS[i]);
        if (i!=n)
        printf("+");
    }
    printf("\n");

    return 0;
}