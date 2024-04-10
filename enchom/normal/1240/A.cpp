#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long llong;

llong k;
int q;
int n;
int p[200111];
llong presums[200111];

int x,a;
int y,b;
llong LCM;

llong gcd(llong A,llong B)
{
    llong R;
    while(B!=0)
    {
        R = A % B;
        A = B;
        B = R;
    }

    return A;
}

llong nok(llong A,llong B)
{
    return (A * B) / gcd(A,B);
}

llong getsum(int L,int R)
{
    return presums[R] - presums[L-1];
}

llong win(int tickets)
{
    llong doubles = (llong)tickets / LCM;
    llong singleA = (llong)tickets / (llong)a - doubles;
    llong singleB = (llong)tickets / (llong)b - doubles;

    llong totalsum = getsum(1, doubles) * (llong)(x + y);
    totalsum += getsum(doubles+1, doubles+singleA) * (llong)x;
    totalsum += getsum(doubles+singleA+1, doubles+singleA+singleB) * (llong)y;

    return totalsum;
}

int main()
{
    int i,j;
    int test;

    scanf("%d",&q);

    for (test=1;test<=q;test++)
    {
        scanf("%d",&n);

        for (i=1;i<=n;i++)
        {
            scanf("%d",&p[i]);
            p[i] /= 100;
        }

        sort(p+1,p+1+n);
        reverse(p+1,p+1+n);

        presums[0] = 0LL;
        for (i=1;i<=n;i++)
        {
            presums[i] = presums[i-1] + (llong)p[i];
        }

        scanf("%d %d",&x,&a);
        scanf("%d %d",&y,&b);

        if (x < y)
        {
            int swp = a;
            a = b;
            b = swp;

            swp = x;
            x = y;
            y = swp;
        }

        LCM = nok(a,b);

        scanf("%lld",&k);

        int l = 1, r = n, mid, best = -1;

        while(l <= r)
        {
            mid = (l + r) / 2;

            if (win(mid) >= k)
            {
                best = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        printf("%d\n",best);
    }

    return 0;
}