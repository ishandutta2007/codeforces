#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
    int x,y,w,id;
}e[300001];
vector<pair<int,int> > v[300001<<2];
int n,m,pos,ans[300001],bin[300001],s[300001],cnt;
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
    if(s[x]<s[y])
        x^=y^=x^=y;
    if(x^y)
    {
        bin[y]=x;
        cnt-=(s[x]&1)+(s[y]&1);
        s[x]+=s[y];
        cnt+=s[x]&1;
        return {x,y};
    }
    return {0,0};
}
inline void del(int x,int y)
{
    if(!x||!y)
        return;
    bin[y]=0;
    cnt-=s[x]&1;
    s[x]-=s[y];
    cnt+=(s[x]&1)+(s[y]&1);
}
inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
inline void update(int nl,int nr,int l,int r,int k,pair<int,int> p)
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
inline void query(int l,int r,int k)
{
    vector<pair<int,int> > tmp;
    for(auto i:v[k])
        tmp.emplace_back(link(i.first,i.second));
    if(l==r)
    {
        for(;pos<=m&&cnt;++pos)
        {
            if(e[pos].id>l)
                continue;
            tmp.emplace_back(link(e[pos].x,e[pos].y));
            update(e[pos].id,l-1,1,m,1,{e[pos].x,e[pos].y});
        }
        if(!cnt)
            ans[l]=e[pos-1].w;
        reverse(tmp.begin(),tmp.end());
        for(auto i:tmp)
            del(i.first,i.second);
        return;
    }
    int mid=(l+r)>>1;
    query(mid+1,r,rs(k));
    query(l,mid,ls(k));
    reverse(tmp.begin(),tmp.end());
    for(auto i:tmp)
        del(i.first,i.second);
}
int main()
{
    cnt=n=read(),m=read();
    pos=1;
    for(int i=1;i<=n;++i)
        s[i]=1;
    for(int i=1;i<=m;++i)
    {
        e[i].x=read(),e[i].y=read(),e[i].w=read(),e[i].id=i;
        ans[i]=-1;
    }
    sort(e+1,e+m+1,[&](edge x,edge y){return x.w<y.w;});
    query(1,m,1);
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
    return 0;
}