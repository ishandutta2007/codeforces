#include <bits/stdc++.h>

using namespace std;

int N, X, Y;

int main()
{
    scanf("%d%d%d", &N, &X, &Y);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        long long lo=1, mid, hi=1000000001LL;
        while(lo<hi)
        {
            mid=(lo+hi+1)/2;
            if(mid+mid*Y/X>a)
                hi=mid-1;
            else
                lo=mid;
        }
        bool goodA=lo+lo*Y/X==a;
        lo=1, hi=1000000001LL;
        while(lo<hi)
        {
            mid=(lo+hi+1)/2;
            if(mid+mid*X/Y>a)
                hi=mid-1;
            else
                lo=mid;
        }
        bool goodB=lo+lo*X/Y==a;
        if(goodA^goodB)
        {
            if(goodA)
                puts("Vanya");
            else
                puts("Vova");
        }
        else
            puts("Both");
    }
    return 0;
}