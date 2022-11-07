#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 400010
#define M 30
using namespace std;
int ch[N*M][2],cnt=0;
int lf[N*M],rf[N*M],root;
void insert(int v,int l,int &u=root,int d=M)
{
    if(!u) u=++cnt;
    lf[u]=min(lf[u],l);
    rf[u]=max(rf[u],l);
    if(d<0) return;
    int c=(v>>d)&1;
    insert(v,l,ch[u][c],d-1);
}
int answer(int v,int u=root,int d=M)
{
    if(d<0) return 0;
    int c=(v>>d)&1;
    if(ch[u][c]) return answer(v,ch[u][c],d-1);
    else return answer(v,ch[u][!c],d-1)+(1<<d);
}
int w[N];
ll dfs(int u=root,int d=M)
{
    if(d<0 || !rf[u]) return 0;
    ll res=0;
    if(rf[ch[u][0]] && rf[ch[u][1]])
    {
        int m=1<<30;
        int l=lf[ch[u][0]],r=rf[ch[u][0]];
        if(r-l>rf[ch[u][1]]-lf[ch[u][1]]) l=lf[ch[u][1]],r=rf[ch[u][1]];
        for(int i=l;i<=r;i++) m=min(m,answer(w[i],l==lf[ch[u][0]]?ch[u][1]:ch[u][0],d-1));
        res+=m+(1<<d);
    }
    return res+dfs(ch[u][0],d-1)+dfs(ch[u][1],d-1);
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    sort(w+1,w+n+1);
    memset(lf,60,sizeof(lf));
    for(int i=1;i<=n;i++) insert(w[i],i);
    printf("%lld\n",dfs());
    return 0;
}