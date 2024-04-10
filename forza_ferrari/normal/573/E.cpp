#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<deque>
using namespace std;
#define int long long
int n,block,pos[100001],p[100001],val[100001][2],tag[1001][2],ans;
deque<int> q[1001];
bool vis[100001];
inline int read()
{
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline double slope(int x,int y)
{
    return val[x][0]==val[y][0]? (val[x][1]==val[y][1]? 1:val[x][1]<val[y][1]? 1e18:-1e18):1.0*(val[y][1]-val[x][1])/(val[y][0]-val[x][0]);
}
inline void rebuild(int k)
{
    int l=(k-1)*block+1,r=min(n,k*block);
    for(int i=l;i<=r;++i)
        val[p[i]][1]+=tag[k][0]*val[p[i]][0]+tag[k][1];
    tag[k][0]=tag[k][1]=0;
    q[k].clear();
    for(int i=l;i<=r;++i)
    {
        if(vis[p[i]])
            continue;
        while(q[k].size()>1&&slope(q[k][(int)q[k].size()-2],q[k].back())<slope(q[k].back(),p[i]))
            q[k].pop_back();
        q[k].emplace_back(p[i]);
    }
}
inline pair<int,int> query(int k)
{
    while(q[k].size()>1&&slope(q[k][0],q[k][1])>=-tag[k][0])
        q[k].pop_front();
    if(q[k].empty())
        return {-1e18,0};
    return {val[q[k][0]][0]*tag[k][0]+val[q[k][0]][1]+tag[k][1],q[k][0]};
}
signed main()
{
    block=sqrt(n=read());
    for(int i=1;i<=n;++i)
    {
        val[i][0]=val[i][1]=read();
        pos[i]=(i-1)/block+1;
        p[i]=i;
    }
    for(int i=1;i<=pos[n];++i)
    {
        sort(p+(i-1)*block+1,p+min(n,i*block)+1,[&](int x,int y){return val[x][0]<val[y][0];});
        rebuild(i);
    }
    for(int i=1;i<=n;++i)
    {
        pair<int,int> tmp={-1e18,0};
        for(int j=1;j<=pos[n];++j)
            tmp=max(tmp,query(j));
        if(tmp.first<0)
            break;
        ans+=tmp.first;
        vis[tmp.second]=1;
        for(int j=1;j<pos[tmp.second];++j)
            tag[j][1]+=val[tmp.second][0];
        for(int j=pos[tmp.second]+1;j<=pos[n];++j)
            ++tag[j][0];
        for(int j=(pos[tmp.second]-1)*block+1;j<tmp.second;++j)
            val[j][1]+=val[tmp.second][0];
        for(int j=tmp.second+1;j<=min(n,pos[tmp.second]*block);++j)
            val[j][1]+=val[j][0];
        rebuild(pos[tmp.second]);
    }
    cout<<ans<<'\n';
    return 0;
}