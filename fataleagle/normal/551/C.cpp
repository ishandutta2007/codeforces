#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100000];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    long long lo=1, mid, hi=1000000000000000LL;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        bool ok=true;
        long long credit=0;
        long long tot=0;
        for(int i=N-1; i>=0; i--)
        {
            long long tmp=A[i];
            long long v=min(credit, tmp);
            credit-=v;
            tmp-=v;
            long long removable=mid-i-1;
            if(removable<=0 && tmp>0)
            {
                ok=false;
                break;
            }
            else if(tmp>0)
            {
                long long need=(tmp+removable-1)/removable;
                credit+=need*removable-tmp;
                tot+=need;
            }
        }
        ok&=tot<=M;
        if(ok)
            hi=mid;
        else
            lo=mid+1;
    }
    printf("%lld\n", lo);
    return 0;
}