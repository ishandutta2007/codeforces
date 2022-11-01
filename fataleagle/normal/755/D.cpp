#include <bits/stdc++.h>

using namespace std;

int N, K;
int bit[1000001];

void add(int x, int v)
{
    for(x++; x<=N; x+=x&-x)
        bit[x]+=v;
}

int sum(int x)
{
    int ret=0;
    for(x++; x>0; x-=x&-x)
        ret+=bit[x];
    return ret;
}

int main()
{
    scanf("%d%d", &N, &K);
    K=min(K, N-K);
    long long ans=1;
    int x=0;
    for(int i=0; i<N; i++)
    {
        int y=x+K-1;
        if(y>=N)
            y-=N;
        if(x<=y)
            ans+=sum(y)-sum(x)+1;
        else
            ans+=2*i+sum(y)-sum(x)+1;
        add(x, 1);
        x=y+1;
        if(x>=N)
            x-=N;
        add(x, 1);
        printf("%lld ", ans);
    }
    printf("\n");
    return 0;
}