#include <bits/stdc++.h>

using namespace std;

int N;
set<pair<int, int>> vertices;
int deg[1<<16];
int sum[1<<16];

int main()
{
    scanf("%d", &N);
    int a, b;
    int ans=0;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        deg[i]=a;
        sum[i]=b;
        ans+=a;
        vertices.insert(make_pair(a, i));
    }
    printf("%d\n", ans/2);
    while(!vertices.empty())
    {
        int d=vertices.begin()->first;
        int idx=vertices.begin()->second;
        vertices.erase(vertices.begin());
        if(d==1)
        {
            printf("%d %d\n", idx, sum[idx]);
            vertices.erase(vertices.find(make_pair(deg[sum[idx]], sum[idx])));
            deg[sum[idx]]--;
            sum[sum[idx]]^=idx;
            vertices.insert(make_pair(deg[sum[idx]], sum[idx]));
        }
    }
    return 0;
}