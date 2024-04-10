#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int ans=0x3f3f3f3f;
    for(int a=1; a<=N; a++)
    {
        int b=(N+a-1)/a;
        ans=min(ans, 2*(a+b));
    }
    printf("%d\n", ans);
    return 0;
}