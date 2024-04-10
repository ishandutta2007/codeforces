#include <bits/stdc++.h>

using namespace std;

const int SZ=317;
int N;
int A[100000];
int B[100000];
vector<int> adj[100000];
int in[100000];
int out[100000];
int now;
int occ[100001];
int cnt[100001];
long long sum[100001];
map<pair<int, int>, long long> ans;
int ptr;

void dfs(int u, int p)
{
    B[now]=A[u];
    in[u]=now++;
    for(auto& v: adj[u]) if(v!=p)
        dfs(v, u);
    out[u]=now-1;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if(a.first/SZ==b.first/SZ)
        return a.first<b.first;
    return a.second<b.second;
}

void add(int x)
{
    sum[occ[x]]-=x;
    occ[x]++;
    sum[occ[x]]+=x;
    if(occ[x]>ptr)
        ptr=occ[x];
}

void rem(int x)
{
    sum[occ[x]]-=x;
    occ[x]--;
    sum[occ[x]]+=x;
    while(ptr>0 && sum[ptr]==0)
        ptr--;
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    int a, b;
    for(int i=0; i<N-1; i++)
    {
        scanf("%d%d", &a, &b);
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, 0);
    vector<pair<int, int>> q;
    for(int i=0; i<N; i++)
        q.push_back(make_pair(in[i], out[i]));
    sort(q.begin(), q.end(), cmp);
    int l=0, r=0;
    add(B[0]);
    for(int i=0; i<N; i++)
    {
        while(r>q[i].second)
        {
            rem(B[r]);
            r--;
        }
        while(r<q[i].second)
        {
            r++;
            add(B[r]);
        }
        while(l>q[i].first)
        {
            l--;
            add(B[l]);
        }
        while(l<q[i].first)
        {
            rem(B[l]);
            l++;
        }
        ans[q[i]]=sum[ptr];
    }
    for(int i=0; i<N; i++)
        printf("%lld ", ans[{in[i], out[i]}]);
    printf("\n");
    return 0;
}