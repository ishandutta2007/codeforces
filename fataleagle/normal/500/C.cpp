#include <bits/stdc++.h>

using namespace std;

int N, M;
int W[501];
vector<int> between[501];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        scanf("%d", W+i);
    int a;
    long long ans=0;
    for(int i=1; i<=M; i++)
    {
        scanf("%d", &a);
        for(int j=1; j<=N; j++)
            if(j!=a)
                between[j].push_back(a);
        sort(between[a].begin(), between[a].end());
        between[a].resize(unique(between[a].begin(), between[a].end())-between[a].begin());
        for(auto& it: between[a])
            ans+=W[it];
        between[a].clear();
    }
    printf("%lld\n", ans);
    return 0;
}