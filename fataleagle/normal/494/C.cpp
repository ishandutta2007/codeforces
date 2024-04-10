#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int N, Q;
int A[100002];
int L[5002], R[5002];
double P[5002];
int order[5002];
vector<int> adj[5002];
vector<int> S;
int maxi[5002];
double dp[5002][5002];

bool cmp(int a, int b)
{
    if(L[a]!=L[b])
        return L[a]<L[b];
    if(R[a]!=R[b])
        return R[a]>R[b];
    return a>b;
}

void solve(int u)
{
    int last=L[u];
    for(auto& v: adj[u])
    {
        solve(v);
        for(int i=last; i<L[v]; i++)
            maxi[u]=max(maxi[u], A[i]);
        maxi[u]=max(maxi[u], maxi[v]);
        last=R[v]+1;
    }
    for(int i=last; i<=R[u]; i++)
        maxi[u]=max(maxi[u], A[i]);
    for(int i=0; i<=Q; i++)
    {
        double pa=P[u], pb=1.0-P[u];
        for(auto& v: adj[u])
        {
            if(maxi[u]-1-maxi[v]+i<0)
                pa=0.0;
            else if(maxi[u]-1-maxi[v]+i<=Q)
                pa*=dp[v][maxi[u]-1-maxi[v]+i];
            if(maxi[u]-maxi[v]+i<=Q)
                pb*=dp[v][maxi[u]-maxi[v]+i];
        }
        dp[u][i]=pa*(!!i)+pb;
    }
}

int main()
{
    scanf("%d%d", &N, &Q);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=1; i<=Q; i++)
        scanf("%d%d%lf", L+i, R+i, P+i);
    Q++;
    L[Q]=1;
    R[Q]=N;
    P[Q]=0.0;
    for(int i=1; i<=Q; i++)
        order[i]=i;
    sort(order+1, order+1+Q, cmp);
    int root=order[1];
    S.push_back(root);
    for(int i=2; i<=Q; i++)
    {
        while(L[S.back()]>L[order[i]] || R[order[i]]>R[S.back()])
            S.pop_back();
        adj[S.back()].push_back(order[i]);
        S.push_back(order[i]);
    }
    solve(root);
    double ans=dp[root][0]*maxi[root];
    for(int i=1; i<=Q; i++)
        ans+=(dp[root][i]-dp[root][i-1])*(maxi[root]+i);
    printf("%.10lf\n", ans);
    return 0;
}