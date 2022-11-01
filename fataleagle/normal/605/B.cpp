#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, pair<int, int>>> ans;

int main()
{
    scanf("%d%d", &N, &M);
    vector<pair<pair<int, int>, int>> edges;
    for(int i=0; i<M; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        edges.push_back({{a, -b}, i});
    }
    sort(edges.begin(), edges.end());
    int ptr1=1, ptr2=1, lim=1;
    for(int i=0; i<M; i++)
    {
        int w=edges[i].first.first;
        int mst=edges[i].first.second;
        int idx=edges[i].second;
        if(mst)
        {
            ans.push_back({idx, {lim, lim+1}});
            lim++;
        }
        else
        {
            if(ptr2+1<ptr1)
                ans.push_back({idx, {ptr2++, ptr1}});
            else
            {
                if(ptr1==lim)
                {
                    printf("-1\n");
                    return 0;
                }
                ptr1++;
                ptr2=1;
                if(ptr2==1 && ptr1==2)
                {
                    if(ptr1==lim)
                    {
                        printf("-1\n");
                        return 0;
                    }
                    ptr1++;
                }
                ans.push_back({idx, {ptr2++, ptr1}});
            }
        }
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<M; i++)
        printf("%d %d\n", ans[i].second.first, ans[i].second.second);
    return 0;
}