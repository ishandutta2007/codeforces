#include <iostream>
#include <stdio.h>
using namespace std;

int n,m;
char str[1111];

int main()
{
    int i;
    int ans=0;

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%s",str+1);
    }

    str[m+1]='.';
    m++;
    for (i=2;i<=m;i++)
    {
        if (str[i]=='.' && str[i-1]=='B')
        ans++;
    }

    printf("%d\n",ans);

    return 0;
}