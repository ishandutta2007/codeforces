#include <bits/stdc++.h>

using namespace std;

int N, M, K;
int A[200001];
int B[2000001];
long long C[2000001];
int D[400001];
int req[200001];
int has[200001];
int ngood;

inline void modify(int x, int v)
{
    if(has[B[x]]==req[B[x]])
        ngood--;
    has[B[x]]+=v;
    if(has[B[x]]==req[B[x]])
        ngood++;
}

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    scanf("%d", &K);
    int a;
    for(int i=1; i<=K; i++)
    {
        scanf("%d", &a);
        req[a]++;
    }
    int M=0;
    int t=0;
    while(M<4*K)
    {
        for(int i=1; i<=N; i++)
        {
            if(i==1 && t!=0)
                continue;
            M++;
            B[M]=i;
            C[M]=C[M-1]+A[i]-A[i-1];
        }
        for(int i=N-1; i>=1; i--)
        {
            M++;
            B[M]=i;
            C[M]=C[M-1]+A[i+1]-A[i];
        }
        t=1;
    }
    for(int i=1; i<=N; i++) if(req[i]==0)
        ngood++;
    vector<long long> ans;
    for(int i=1; i<=M; i++)
    {
        modify(i, 1);
        if(i>K)
            modify(i-K, -1);
        if(i>=K && ngood==N)
            ans.push_back(C[i]-C[i-K+1]);
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end())-ans.begin());
    if(ans.size()==1)
        printf("%lld\n", ans[0]);
    else
        printf("-1\n");
    return 0;
}