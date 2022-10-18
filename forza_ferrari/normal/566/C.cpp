#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int n,w[200001],maxn[200001],s[200001],dep[200001],pos,root;
bool vis[200001];
double ans,sum,val[200001];
vector<pair<int,int> > v[200001];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void calc(int k,int f,int rt,int deep)
{
    dep[k]=deep;
    val[rt]+=1.5*w[k]*sqrt(dep[k]);
    sum+=sqrt(dep[k])*dep[k]*w[k];
    for(auto i:v[k])
    {
        if(i.first==f)
            continue;
        calc(i.first,k,rt,deep+i.second);
    }
}
inline void find(int k,int f,int tot)
{
    s[k]=1;
    maxn[k]=0;
    for(auto i:v[k])
    {
        if(i.first==f||vis[i.first])
            continue;
        find(i.first,k,tot);
        s[k]+=s[i.first];
        maxn[k]=max(maxn[k],s[i.first]);
    }
    maxn[k]=max(maxn[k],tot-s[k]);
    if(maxn[k]<maxn[root])
        root=k;
}
inline void dfs(int k)
{
    vis[k]=1;
    sum=0.0000;
    double res=0.0000;
    for(auto i:v[k])
    {
        val[i.first]=0;
        calc(i.first,k,i.first,i.second);
        res+=val[i.first];
    }
    if(sum<ans)
    {
        ans=sum;
        pos=k;
    }
    for(auto i:v[k])
        if(res-2*val[i.first]<0)
        {
            if(vis[i.first])
                return;
            root=0;
            find(i.first,k,s[i.first]);
            dfs(root);
            return;
        }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
        w[i]=read();
    for(int i=1;i<n;++i)
    {
        int x=read(),y=read(),w=read();
        v[x].emplace_back(y,w);
        v[y].emplace_back(x,w);
    }
    maxn[0]=1<<30;
    ans=1e20;
    find(1,0,n);
    dfs(root);
    printf("%d %.10lf\n",pos,ans);
    return 0;
}