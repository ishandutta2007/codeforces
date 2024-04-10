#include <iostream>
#include <cstdio>

using namespace std;

int C, VA, WA, VB, WB;

int main()
{
    scanf("%d%d%d%d%d", &C, &VA, &VB, &WA, &WB);
    if(WA<WB)
        swap(WA, WB), swap(VA, VB);
    long long ans=0;
    if(WA>=1000)
    {
        for(int i=0; i<=C/WA; i++)
            ans=max(ans, 1LL*VA*i+1LL*VB*((C-1LL*i*WA)/WB));
    }
    else
    {
        for(int i=0; i<=WB; i++) if(1LL*i*WA<=C)
            ans=max(ans, 1LL*VA*i+1LL*VB*((C-1LL*i*WA)/WB));
        for(int i=0; i<=WA; i++) if(1LL*i*WB<=C)
            ans=max(ans, 1LL*VB*i+1LL*VA*((C-1LL*i*WB)/WA));
    }
    printf("%lld\n", ans);
    return 0;
}