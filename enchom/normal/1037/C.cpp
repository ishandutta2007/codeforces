#include <iostream>
#include <stdio.h>
using namespace std;

int n;
char a[1000111];
char b[1000111];

int main()
{
    int i,j;
    int cur;
    char swp;
    int ans = 0;

    scanf("%d",&n);

    scanf("%s",a+1);
    scanf("%s",b+1);

    cur = 1;
    while(cur < n)
    {
        if (a[cur] != b[cur] && a[cur+1] != b[cur+1] && a[cur] == b[cur+1] && a[cur+1] == b[cur])
        {
            swp = a[cur];
            a[cur] = a[cur+1];
            a[cur+1] = swp;
            ans++;

            cur += 2;
        }
        else
            cur++;
    }

    for (i=1;i<=n;i++)
    {
        if (a[i] != b[i])
            ans++;
    }

    printf("%d\n",ans);

    return 0;
}