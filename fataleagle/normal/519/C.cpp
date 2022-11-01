#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
    scanf("%d%d", &N, &M);
    int ans=0;
    for(int i=0; i<=N; i++) if(i*2<=M)
        ans=max(ans, i+min((N-i)/2, M-i*2));
    printf("%d\n", ans);
    return 0;
}