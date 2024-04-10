#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    scanf("%d", &N);
    int ans=25;
    for(int i=0; i<N; i++)
    {
        int a;
        scanf("%d", &a);
        ans=max(ans, a);
    }
    printf("%d\n", ans-25);
    return 0;
}