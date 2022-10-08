#include <iostream>
#include <stdio.h>
using namespace std;

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int n;
int males[411];
int females[411];

int main()
{
    int i,j;
    char ch[2];
    int L,R;
    int ans=0;

    scanf("%d",&n);

    for (i=1;i<=n;i++)
    {
        scanf("%s",ch);
        scanf("%d %d",&L,&R);

        for (j=L;j<=R;j++)
        {
            if (ch[0]=='M')
            males[j]++;
            else
            females[j]++;
        }
    }

    for (i=0;i<=400;i++)
    {
        if (MIN(males[i],females[i])>ans)
        ans=MIN(males[i],females[i]);
    }

    printf("%d\n",ans*2);

    return 0;
}