#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
using namespace std;
int n,m,bin[100001<<1],s[100001<<1];
map<pair<int,int>,int> mp;
struct edge
{
    int x,y,k;
    edge(int x_,int y_,int k_):
        x(x_),y(y_),k(k_){}
};
vector<edge> sum[100001<<2],t;
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
int anc(int k)
{
    if(!bin[k])
        return k;
    return anc(bin[k]);
}
inline void link(int x,int y,int k)
{
    x=anc(x);
    y=anc(y);
    if(x^y)
        if(s[x]<s[y])
        {
            bin[x]=y;
            s[y]+=s[x];
            t.push_back(edge(x,y,k));
        }
        else
        {
            bin[y]=x;
            s[x]+=s[y];
            t.push_back(edge(y,x,k));
        }
}
inline void cut(int x,int y)
{
    bin[x]=0;
    s[y]-=s[x];
}
inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
void update(int nl,int nr,int l,int r,int k,edge p)
{
    if(l>=nl&&r<=nr)
    {
        sum[k].push_back(p);
        return;
    }
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
}
void query(int l,int r,int k)
{
    for(register int i=0;i<(int)sum[k].size();++i)
    {
        int x=sum[k][i].x,y=sum[k][i].y;
        int xs=anc(x),xd=anc(x+n),ys=anc(y),yd=anc(y+n);
        if(xs==ys||xd==yd)
        {
            for(register int j=l;j<=r;++j)
                puts("NO");
            while(!t.empty()&&t.back().k==k)
            {
                cut(t.back().x,t.back().y);
                t.pop_back();
            }
            return;
        }
        link(xs,yd,k);
        link(xd,ys,k);
    }
    if(l==r)
        puts("YES");
    else
    {
        int mid=(l+r)>>1;
        query(l,mid,ls(k));
        query(mid+1,r,rs(k));
    }
    while(!t.empty()&&t.back().k==k)
    {
        cut(t.back().x,t.back().y);
        t.pop_back();
    }
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n<<1;++i)
        s[i]=1;
    for(int i=1;i<=m;++i)
    {
        int l=read(),r=read();
        if(l>r)
            l^=r^=l^=r;
        if(mp.count({l,r}))
        {
            update(mp[{l,r}],i-1,1,m,1,{l,r,0});
            mp.erase({l,r});
        }
        else
            mp[{l,r}]=i;
    }
    for(pair<pair<int,int>,int> i:mp)
        update(i.second,m,1,m,1,{i.first.first,i.first.second,0});
    query(1,m,1);
    return 0;
}