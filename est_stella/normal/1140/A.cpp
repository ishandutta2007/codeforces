#include<bits/stdc++.h>

int n, a, Max, cnt;

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d", &a);

        if(a>Max) Max=a;

        if(i==Max) cnt++, Max=0;
    }

    printf("%d", cnt);
}