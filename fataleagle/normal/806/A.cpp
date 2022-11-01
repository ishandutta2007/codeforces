#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int x, y, a, b;
        scanf("%d%d%d%d", &x, &y, &a, &b);
        if(a==0)
        {
            if(x==0)
                printf("0\n");
            else
                printf("-1\n");
        }
        else if(a==b)
        {
            if(x==y)
                printf("0\n");
            else
                printf("-1\n");
        }
        else
        {
            int g=__gcd(a, b);
            long long p=a/g;
            long long q=b/g;
            long long m=max((x+p-1)/p, (y+q-1)/q);
            long long d=p*m-x;
            long long e=q*m-y;
            if(d>e)
                m+=((d-e)+(q-p)-1)/(q-p);
            printf("%lld\n", q*m-y);
        }
    }
    return 0;
}