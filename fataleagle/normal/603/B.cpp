#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int P, K;
bool seen[1000001];
int pre[1000001];

int main()
{
    scanf("%d%d", &P, &K);
    if(K==0)
    {
        int ans=1;
        for(int i=1; i<P; i++)
            ans=1LL*ans*P%MOD;
        printf("%d\n", ans);
        return 0;
    }
    int ans=1;
    for(int i=0; i<P; i++) if(!seen[i])
    {
        int u=i;
        do
        {
            seen[u]=true;
            int v=1LL*K*u%P;
            pre[v]=u;
            u=v;
        }
        while(!seen[u]);
        int x=1;
        int v=u;
        do
        {
            x=1LL*x*K%P;
            u=pre[u];
        }
        while(u!=v);
        if(x==1)
            ans=1LL*ans*P%MOD;
    }
    printf("%d\n", ans);
    return 0;
}