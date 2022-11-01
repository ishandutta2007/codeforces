#include <bits/stdc++.h>

using namespace std;

int N, K, D;
int ans[1005][1005];

void getans(int k, int n)
{
    int pos=0;
    while(n)
    {
        ans[k][pos++]=n%K;
        n/=K;
    }
}

int main()
{
    scanf("%d%d%d", &N, &K, &D);
    long long ways=1;
    for(int i=0; i<D; i++)
    {
        ways*=K;
        if(ways>=N)
            break;
    }
    if(ways<N)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=0; i<N; i++)
        getans(i, i);
    for(int i=0; i<D; i++)
        for(int j=0; j<N; j++)
            printf("%d%c", ans[j][i]+1, j==N-1?'\n':' ');
    return 0;
}