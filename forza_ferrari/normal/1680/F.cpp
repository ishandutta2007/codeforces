#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,m,bin[2000001],s[2000001];
pair<int,int> e[1000001];
vector<int> v[1000001];
bool vis[1000001],tag[1000001];
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
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return anc(bin[k]);
}
inline pair<int,int> link(int x,int y)
{
    x=anc(x);
    y=anc(y);
    if(x==y)
        return {0,0};
    if(s[x]<s[y])
        x^=y^=x^=y;
    bin[y]=x;
    s[x]+=s[y];
    return {x,y};
}
inline void del(int x,int y)
{
    if(x&&y)
    {
        bin[y]=0;
        s[x]-=s[y];
    }
}
inline int solve(int l,int r)
{
    if(l==r)
        return l;
    int mid=(l+r)>>1;
    vector<pair<int,int> > tmp;
    bool flag=1;
    for(int i=l;i<=mid;++i)
    {
        if(anc(e[i].first)==anc(e[i].second)||anc(e[i].first+n)==anc(e[i].second+n))
        {
            flag=0;
            break;
        }
        tmp.emplace_back(link(e[i].first,e[i].second+n));
        tmp.emplace_back(link(e[i].first+n,e[i].second));
    }
    if(flag)
    {
        int w=solve(mid+1,r);
        if(w)
            return w;
    }
    reverse(tmp.begin(),tmp.end());
    for(auto i:tmp)
        del(i.first,i.second);
    tmp.clear();
    flag=1;
    for(int i=mid+1;i<=r;++i)
    {
        if(anc(e[i].first)==anc(e[i].second)||anc(e[i].first+n)==anc(e[i].second+n))
        {
            flag=0;
            break;
        }
        tmp.emplace_back(link(e[i].first,e[i].second+n));
        tmp.emplace_back(link(e[i].first+n,e[i].second));
    }
    if(flag)
    {
        int w=solve(l,mid);
        if(w)
            return w;
    }
    reverse(tmp.begin(),tmp.end());
    for(auto i:tmp)
        del(i.first,i.second);
    tmp.clear();
    return 0;
}
inline void dfs(int k,bool val)
{
    tag[k]=val;
    vis[k]=1;
    for(auto i:v[k])
        if(!vis[i])
            dfs(i,val^1);
}
int main()
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        for(int i=1;i<=n+n;++i)
        {
            bin[i]=0;
            s[i]=1;
        }
        for(int i=1;i<=n;++i)
        {
            v[i].clear();
            vis[i]=tag[i]=0;
        }
        for(int i=1;i<=m;++i)
            e[i].first=read(),e[i].second=read();
        int w=solve(1,m);
        if(!w)
        {
            cout<<"NO\n";
            continue;
        }
        for(int i=1;i<=m;++i)
            if(i^w)
            {
                v[e[i].first].emplace_back(e[i].second);
                v[e[i].second].emplace_back(e[i].first);
            }
        dfs(e[w].first,1);
        if(!vis[e[w].second])
            dfs(e[w].second,1);
        for(int i=1;i<=n;++i)
            if(!vis[i])
                dfs(i,1);
        cout<<"YES\n";
        for(int i=1;i<=n;++i)
            cout<<tag[i];
        cout<<'\n';
    }
    return 0;
}