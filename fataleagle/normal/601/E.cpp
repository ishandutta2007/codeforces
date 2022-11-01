#include <bits/stdc++.h>

using namespace std;

const int p=10000019, q=1000000007;

struct item
{
    int t, u, v, w;
};

int N, K, Q;
int X[30003], NX;
vector<int> queries;
int ans[30004];
vector<item> tree[65536];

struct knapsack_solver
{
    long long dp[1001];
    void upd(int v, int w)
    {
        for(int i=K; i>=w; i--)
            dp[i]=max(dp[i], dp[i-w]+v);
    }
};

vector<knapsack_solver> vds;

void add(int idx, int begin, int end, item it)
{
    if(it.u<begin || end<it.t)
        return;
    if(it.t<=begin && end<=it.u)
        tree[idx].push_back(it);
    else
    {
        int mid=(begin+end)/2;
        add(idx*2, begin, mid, it);
        add(idx*2+1, mid+1, end, it);
    }
}

void solve(int idx, int begin, int end)
{
    vds.push_back(vds.back());
    for(auto& it: tree[idx])
        vds.back().upd(it.v, it.w);
    if(begin==end)
    {
        int rans=0;
        for(int i=K; i>=1; i--)
            rans=(1LL*rans*p+vds.back().dp[i])%q;
        ans[begin]=rans;
    }
    else
    {
        int mid=(begin+end)/2;
        solve(idx*2, begin, mid);
        solve(idx*2+1, mid+1, end);
    }
    vds.pop_back();
}

int main()
{
    scanf("%d%d", &N, &K);
    X[NX++]=-2;
    X[NX++]=-1;
    X[NX++]=0x3f3f3f3f;
    vector<item> items;
    int a, b;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        items.push_back({-2, 0x3f3f3f3f, a, b});
    }
    scanf("%d", &Q);
    int last=-1;
    int op;
    for(int i=0; i<Q; i++)
    {
        scanf("%d", &op);
        if(op==1)
        {
            scanf("%d%d", &a, &b);
            items.push_back({i, 0x3f3f3f3f, a, b});
            X[NX++]=i;
            last=i;
        }
        else if(op==2)
        {
            scanf("%d", &a);
            items[a-1].u=last;
            X[NX++]=i;
            last=i;
        }
        else
            queries.push_back(last);
    }
    sort(X, X+NX);
    for(auto& it: items)
    {
        it.t=lower_bound(X, X+NX, it.t)-X+1;
        it.u=lower_bound(X, X+NX, it.u)-X+1;
        add(1, 1, NX, it);
    }
    for(auto& it: queries)
        it=lower_bound(X, X+NX, it)-X+1;
    vds.resize(1);
    memset(vds[0].dp, 0, sizeof vds[0].dp);
    solve(1, 1, NX);
    for(auto& it: queries)
        printf("%d\n", ans[it]);
    return 0;
}