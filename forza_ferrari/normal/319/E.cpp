#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct element
{
    int opt,x,y;
}q[100001];
int n,bin[100001],cnt,pos[100001][2],node[100001<<1],id;
vector<int> v[100001<<3];
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
inline int anc(int k)
{
    if(!bin[k])
        return k;
    return bin[k]=anc(bin[k]);
}
inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
inline void link(int node,int l,int r,int k,int p)
{
    if(!v[k].empty())
    {
        for(int i:v[k])
        {
            int f=anc(i);
            if(f==p)
                continue;
            bin[f]=p;
            pos[p][0]=min(pos[p][0],pos[f][0]);
            pos[p][1]=max(pos[p][1],pos[f][1]);
        }
        v[k].clear();
        v[k].emplace_back(p);
    }
    if(l==r)
        return;
    int mid=(l+r)>>1;
    if(node<=mid)
        link(node,l,mid,ls(k),p);
    else
        link(node,mid+1,r,rs(k),p);
}
inline void update(int nl,int nr,int l,int r,int k,int p)
{
    if(nl>nr)
        return;
    if(l>=nl&&r<=nr)
    {
        v[k].emplace_back(p);
        return;
    }
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        q[i].opt=read(),q[i].x=read(),q[i].y=read();
        if(q[i].opt==1)
        {
            node[++cnt]=q[i].x;
            node[++cnt]=q[i].y;
        }
    }
    sort(node+1,node+cnt+1);
    cnt=unique(node+1,node+cnt+1)-node-1;
    for(int i=1;i<=n;++i)
    {
        int opt=q[i].opt,x=q[i].x,y=q[i].y;
        if(opt==1)
        {
            x=lower_bound(node+1,node+cnt+1,x)-node;
            y=lower_bound(node+1,node+cnt+1,y)-node;
            pos[++id][0]=x;
            pos[id][1]=y;
            link(x,1,cnt,1,id);
            link(y,1,cnt,1,id);
            update(x+1,y-1,1,cnt,1,id);
        }
        if(opt==2)
        {
            x=anc(x),y=anc(y);
            if(x==y||(pos[y][0]<pos[x][0]&&pos[x][0]<pos[y][1])||(pos[y][0]<pos[x][1]&&pos[x][1]<pos[y][1]))
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}