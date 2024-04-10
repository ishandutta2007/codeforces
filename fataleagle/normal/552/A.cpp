#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    long long ans=0;
    scanf("%d", &N);
    while(N--)
    {
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        ans+=(c-a+1)*(d-b+1);
    }
    printf("%lld\n", ans);
    return 0;
}