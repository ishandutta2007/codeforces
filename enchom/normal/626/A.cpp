#include <iostream>
#include <stdio.h>
using namespace std;

int n;
char ch[1011];

int main()
{
    int i,j;
    int x,y;
    int ans=0;

    scanf("%d",&n);

    scanf("%s",ch+1);

    for (i=1;i<=n;i++)
    {
        x=0;
        y=0;
        for (j=i;j<=n;j++)
        {
            if (ch[j]=='U')
            x++;
            if (ch[j]=='D')
            x--;
            if (ch[j]=='L')
            y--;
            if (ch[j]=='R')
            y++;

            if (x==0 && y==0)
            ans++;
        }
    }

    printf("%d\n",ans);

    return 0;
}