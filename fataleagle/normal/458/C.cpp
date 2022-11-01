#include <bits/stdc++.h>

using namespace std;

int N;
int A[100001], B[100001];
int base;
vector<int> people[100001];
int votes[100001];
pair<int, int> seg[32768];

struct cmp
{
    bool operator() (int a, int b)
    {
        if(people[a].size()!=people[b].size())
            return people[a].size()<people[b].size();
        return B[people[a].back()]>B[people[b].back()];
    }
};

priority_queue<int, vector<int>, cmp> pq;

bool cmp2(int a, int b)
{
    return B[a]>B[b];
}

void update(int idx, int begin, int end, int x, int v)
{
    if(x<begin || end<x)
        return;
    if(begin==end)
        seg[idx].first+=v, seg[idx].second+=v*x;
    else
    {
        int mid=(begin+end)/2;
        update(idx*2, begin, mid, x, v);
        update(idx*2+1, mid+1, end, x, v);
        seg[idx].first=seg[idx*2].first+seg[idx*2+1].first;
        seg[idx].second=seg[idx*2].second+seg[idx*2+1].second;
    }
}

int query(int idx, int begin, int end, int pos)
{
    if(pos<=0)
        return 0;
    if(begin==end)
        return begin*pos;
    int mid=(begin+end)/2;
    if(pos>=seg[idx*2].first)
        return seg[idx*2].second+query(idx*2+1, mid+1, end, pos-seg[idx*2].first);
    return query(idx*2, begin, mid, pos);
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d%d", A+i, B+i);
        if(B[i]==0)
            base++;
        else
        {
            people[A[i]].push_back(i);
            update(1, 1, 10000, B[i], 1);
        }
    }
    for(int i=1; i<=100000; i++)
        sort(people[i].begin(), people[i].end(), cmp2);
    int maxi=0;
    for(int i=1; i<=100000; i++)
        if(!people[i].empty())
        {
            maxi=max(maxi, (int)people[i].size());
            votes[people[i].size()]++;
            pq.push(i);
        }
    int cost=0, ans=query(1, 1, 10000, maxi+1-base);
    for(int i=base; i<N; i++)
    {
        int x=pq.top();
        pq.pop();
        int cur=people[x].back();
        int M=people[x].size();
        votes[M]--;
        people[x].pop_back();
        cost+=B[cur];
        votes[M-1]++;
        update(1, 1, 10000, B[cur], -1);
        if(votes[M]==0)
            ans=min(ans, cost+query(1, 1, 10000, M-(i+1)));
        else
            ans=min(ans, cost+query(1, 1, 10000, M-(i+1)+1));
        if(!people[x].empty())
            pq.push(x);
    }
    printf("%d\n", ans);
    return 0;
}