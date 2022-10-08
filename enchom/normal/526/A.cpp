#include <iostream>
#include <stdio.h>
using namespace std;

int n;
char level[1001];

int MakeJumps(int x,int len)
{
    if (level[x]!='*')
    return 0;

    int ans=0;

    x+=len;

    if (x>n)
    return 0;

    while(level[x]=='*')
    {
        ans++;

        x+=len;

        if (x>n)
        break;
    }

    return ans;
}

int main()
{
    int i,j;
    int jumps;

    scanf("%d",&n);
    scanf("%s",level+1);

    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++)
        {
            jumps=MakeJumps(j,i);

            if (jumps>=4)
            {
                printf("yes\n");
                return 0;
            }
        }
    }

    printf("no\n");

    return 0;
}