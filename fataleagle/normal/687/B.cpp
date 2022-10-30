#include <bits/stdc++.h>

using namespace std;

int N, K;
int lp[1000001];
int lcm[1000001];
int tar[1000001];

vector<pair<int, int>> factorize(int x)
{
    vector<pair<int, int>> ret;
    while(x!=1)
    {
        if(ret.empty() || ret.back().first!=lp[x])
            ret.push_back({lp[x], 1});
        else
            ret.back().second++;
        x/=lp[x];
    }
    return ret;
}

int main()
{
    for(int i=2; i<=1000000; i++) if(lp[i]==0)
    {
        for(int j=i; j<=1000000; j+=i) if(lp[j]==0)
            lp[j]=i;
    }
    scanf("%d%d", &N, &K);
    if(K==1)
    {
        printf("Yes\n");
        return 0;
    }
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        if(a%K==0)
        {
            printf("Yes\n");
            return 0;
        }
        if(a==1)
            continue;
        auto v=factorize(a);
        for(auto& it: v)
            lcm[it.first]=max(lcm[it.first], it.second);
    }
    auto v=factorize(K);
    for(auto& it: v)
    {
        if(lcm[it.first]<it.second)
        {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}