#include <bits/stdc++.h>

using namespace std;

long long N;

int main()
{
    scanf("%lld", &N);
    int ans=0;
    for(long long i=0, j=1, k=0; k<=N; ans++, i+=j, j++, k+=i);
    printf("%d\n", ans-1);
    return 0;
}