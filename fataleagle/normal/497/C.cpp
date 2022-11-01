#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

int N, M;

struct part
{
    int l, r, i;
    bool operator< (const part& other) const
    {
        if(r!=other.r)
            return r>other.r;
        return l<other.l;
    }
} parts[100000];

struct actor
{
    int l, r, k, i;
    bool operator< (const actor& other) const
    {
        if(r!=other.r)
            return r>other.r;
        return l<other.l;
    }
} actors[100000];

multimap<int, pair<int, int>> active;
int ans[100000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", &parts[i].l, &parts[i].r), parts[i].i=i;
    scanf("%d", &M);
    for(int i=0; i<M; i++)
        scanf("%d%d%d", &actors[i].l, &actors[i].r, &actors[i].k), actors[i].i=i+1;
    sort(parts, parts+N);
    sort(actors, actors+M);
    int ptr=0;
    for(int i=0; i<N; i++)
    {
        while(ptr<M && parts[i].r<=actors[ptr].r)
        {
            active.insert(make_pair(actors[ptr].l, make_pair(actors[ptr].i, actors[ptr].k)));
            ptr++;
        }
        if(active.empty())
        {
            printf("NO\n");
            return 0;
        }
        auto it=active.lower_bound(parts[i].l+1);
        if(it==active.begin())
        {
            printf("NO\n");
            return 0;
        }
        --it;
        ans[parts[i].i]=it->second.first;
        it->second.second--;
        if(it->second.second==0)
            active.erase(it);
    }
    printf("YES\n");
    for(int i=0; i<N; i++)
        printf("%d%c", ans[i], " \n"[i==N-1]);
    return 0;
}