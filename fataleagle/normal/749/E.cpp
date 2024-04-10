#include <bits/stdc++.h>

using namespace std;

int N;
int A[100000];
pair<int, long long> bit[100001];

void add(int x, pair<int, long long> v)
{
    for(; x<=N; x+=x&-x)
        bit[x].first+=v.first, bit[x].second+=v.second;
}

pair<int, long long> sum(int x)
{
    pair<int, long long> ret=make_pair(0, 0LL);
    for(; x>0; x-=x&-x)
        ret.first+=bit[x].first, ret.second+=bit[x].second;
    return ret;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    long long all=1LL*N*(N+1)/2;
    double ans=0.0;
    for(int i=N-1; i>=0; i--)
    {
        auto p=sum(A[i]);
        ans+=all*p.first-1LL*(i+1)*(1LL*N*p.first-p.second);
        add(A[i], {1, i});
    }
    for(int i=1; i<=N; i++)
        ans+=1LL*i*(i-1)*(N-i+1)/4.0;
    printf("%.9f\n", ans/all);
    return 0;
}