#include <bits/stdc++.h>

using namespace std;

int N, M, K, S;
vector<pair<int, int>> ans;
int A[200001];
int B[200001];
int T[200001];
int C[200001];

bool solve(int day)
{
    int minA=0x3f3f3f3f;
    int minB=0x3f3f3f3f;
    int Aidx=-1, Bidx=-1;
    for(int i=1; i<=day; i++)
    {
        if(A[i]<minA)
        {
            minA=A[i];
            Aidx=i;
        }
        if(B[i]<minB)
        {
            minB=B[i];
            Bidx=i;
        }
    }
    vector<pair<long long, int>> v;
    for(int i=1; i<=M; i++)
    {
        if(T[i]==1)
            v.push_back({1LL*minA*C[i], i});
        else
            v.push_back({1LL*minB*C[i], i});
    }
    sort(v.begin(), v.end());
    long long cost=0;
    for(int i=0; i<K; i++)
        cost+=v[i].first;
    if(cost<=S)
    {
        ans.clear();
        for(int i=0; i<K; i++)
        {
            if(T[v[i].second]==1)
                ans.push_back({v[i].second, Aidx});
            else
                ans.push_back({v[i].second, Bidx});
        }
        return true;
    }
    return false;
}

int main()
{
    scanf("%d%d%d%d", &N, &M, &K, &S);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=1; i<=N; i++)
        scanf("%d", B+i);
    for(int i=1; i<=M; i++)
        scanf("%d%d", T+i, C+i);
    if(!solve(N))
    {
        printf("-1\n");
        return 0;
    }
    int lo=1, mid, hi=N;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        if(solve(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    solve(lo);
    printf("%d\n", lo);
    for(auto& it: ans)
        printf("%d %d\n", it.first, it.second);
    return 0;
}