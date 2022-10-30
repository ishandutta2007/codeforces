#include <bits/stdc++.h>

using namespace std;

int N, K;

int main()
{
    scanf("%d%d", &N, &K);
    int n, a;
    int ans=0, sum=0, chain=0;
    for(int i=0; i<K; i++)
    {
        scanf("%d", &n);
        int last=-1;
        bool flag=false;
        for(int j=0; j<n; j++)
        {
            scanf("%d", &a);
            if(a==1)
                flag=true;
            else if(flag && a!=last+1)
                chain=j, flag=false;
            last=a;
        }
        ans+=n-1;
        if(flag)
            chain=n;
    }
    ans-=chain-1;
    ans+=N-chain;
    printf("%d\n", ans);
    return 0;
}