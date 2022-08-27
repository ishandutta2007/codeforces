#include<bits/stdc++.h>

using namespace std;

int n,m;

int query;

int main()
{
    scanf("%d",&query);while (query--)
    {
        scanf("%d",&n); bool f=false;
        for (int i=0;i<=100;i++)
            for (int j=0;j<=100;j++)
                if (i*3+j*7==n) f=true;
        if (f) puts("YES"); else puts("NO");
    }
    return 0;
}