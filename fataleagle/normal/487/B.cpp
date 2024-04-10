#include <bits/stdc++.h>

using namespace std;

int N, S, L;
int A[100002];
int reach[100002];
int dp[100002];
vector<int> event[200002];
multiset<pair<int, int>> X, Y;
pair<int, int> seg[262144];

void init(int idx, int begin, int end)
{
    if(begin==end)
        seg[idx]=make_pair(A[begin], A[begin]);
    else
    {
        int mid=(begin+end)/2;
        init(idx*2, begin, mid);
        init(idx*2+1, mid+1, end);
        seg[idx].first=min(seg[idx*2].first, seg[idx*2+1].first);
        seg[idx].second=max(seg[idx*2].second, seg[idx*2+1].second);
    }
}

pair<int, int> query(int idx, int begin, int end, int i, int j)
{
    if(j<begin || end<i)
        return make_pair(0x3f3f3f3f, -0x3f3f3f3f);
    if(i<=begin && end<=j)
        return seg[idx];
    int mid=(begin+end)/2;
    pair<int, int> r1=query(idx*2, begin, mid, i, j);
    pair<int, int> r2=query(idx*2+1, mid+1, end, i, j);
    return make_pair(min(r1.first, r2.first), max(r1.second, r2.second));
}

int main()
{
    scanf("%d%d%d", &N, &S, &L);
    if(L>N)
    {
        printf("-1\n");
        return 0;
    }
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    init(1, 1, N);
    for(int i=1; i<=N; i++)
    {
        int lo=0, mid, hi=i;
        while(lo<hi)
        {
            mid=(lo+hi)/2;
            pair<int, int> t=query(1, 1, N, mid, i);
            if(t.second-t.first>S)
                lo=mid+1;
            else
                hi=mid;
        }
        reach[i]=lo;
    }
    X.insert(make_pair(0, 0));
    Y.insert(make_pair(0, 0));
    for(int i=1; i<=N+1; i++)
    {
        for(auto& it: event[i])
        {
            X.insert(make_pair(dp[it-1], it));
            Y.insert(make_pair(it, dp[it-1]));
        }
        while(!Y.empty() && Y.begin()->first<reach[i])
        {
            pair<int, int> p=*Y.begin();
            Y.erase(Y.begin());
            X.erase(X.find(make_pair(p.second, p.first)));
        }
        if(X.empty())
            dp[i]=0x3f3f3f3f;
        else
            dp[i]=X.begin()->first+1;
        event[i+L-1].push_back(i);
    }
    if(L==1)
        dp[N]=min(dp[N], N);
    printf("%d\n", dp[N]>=0x3f3f3f3f?-1:dp[N]);
    return 0;
}