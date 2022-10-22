#include <bits/stdc++.h>
#define N 200005
using namespace std;
int n,q,t=1,u,tree[4*N],s[N],e[N];
bool lazy[4*N];string ss;
vector<int>child[N];
void dfs(int v)
{
    s[v]=t++;
    for(auto &it : child[v])
        dfs(it);
    e[v]=t-1;
}
void propagate(int nd,int s,int e)
{
    if(lazy[nd]){
        int m=(s+e)/2;
        if(s<=m&&s!=e)
            lazy[nd*2]=!lazy[nd*2];
        if(m<e)
            lazy[nd*2+1]=!lazy[nd*2+1];
        lazy[nd]=false;
        tree[nd]=(e-s+1)-tree[nd];
    }
}
void update(int nd,int s,int e,int l,int r)
{
    propagate(nd,s,e);
    if(r<s||e<l)return;
    if(l<=s&&e<=r){
        lazy[nd]=!lazy[nd];
        propagate(nd,s,e);
        return;
    }
    int m=(s+e)/2;
    update(nd*2,s,m,l,r);
    update(nd*2+1,m+1,e,l,r);
    tree[nd]=tree[nd*2]+tree[nd*2+1];
}
int query(int nd,int s,int e,int l,int r)
{
    propagate(nd,s,e);
    if(r<s||e<l)return 0;
    if(l<=s&&e<=r)
        return tree[nd];
    int m=(s+e)/2;
    return query(nd*2,s,m,l,r)+query(nd*2+1,m+1,e,l,r);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=2;i<=n;i++){
        int c;
        cin>>c;
        child[c].push_back(i);
    }
    dfs(1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x)
            update(1,s[1],e[1],s[i],s[i]);
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>ss>>u;
        if(ss=="get")
            cout<<query(1,s[1],e[1],s[u],e[u])<<'\n';
        else
            update(1,s[1],e[1],s[u],e[u]);
    }
    return 0;
}