#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const LL INF=1e18;
const LL MAXV=3e5+10;
vector<LL>adj[MAXV];
LL MAX,C;
LL A[MAXV],B[MAXV];
void dfs1(LL X,LL P)
{
    for(LL i=0;i<adj[X].size();i++)
    {
        LL x=adj[X][i];
        if(x==P)
            continue;
        dfs1(x,X);
        if(B[x]>0)
            B[X]+=B[x];
    }
    MAX=max(MAX,B[X]);
    return;
}
void dfs2(LL X,LL P)
{
    for(LL i=0;i<adj[X].size();i++)
    {
        LL x=adj[X][i];
        if(x==P)
            continue;
        dfs2(x,X);
        if(A[x]>0)
            A[X]+=A[x];
    }
    if(A[X]>=MAX)
    {
        A[X]=0;
        C++;
    }
    return;
}
LL N,i;
LL maxi,s,e;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    maxi=-INF;
    for(i=0;i<N;i++)
    {
        cin>>A[i];
        B[i]=A[i];
        maxi=max(maxi,A[i]);
    }
    if(maxi<=0)
    {
        for(i=0;i<N;i++)
            if(A[i]==maxi)
                C++;
        cout<<C*maxi<<' '<<C<<endl;
        return 0;
    }
    for(i=1;i<N;i++)
    {
        cin>>s>>e;
        adj[--s].push_back(--e);
        adj[e].push_back(s);
    }
    dfs1(0,-1);
    dfs2(0,-1);
    cout<<C*MAX<<' '<<C<<endl;
    return 0;
}