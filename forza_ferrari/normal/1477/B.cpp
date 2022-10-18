#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,m,cnt[200001<<2][2],tag[200001<<2][2];
string a,b;
vector<pair<int,int> > v;
inline int ls(int k)
{
    return k<<1;
}
inline int rs(int k)
{
    return k<<1|1;
}
inline void push_up(int k)
{
    cnt[k][0]=cnt[ls(k)][0]+cnt[rs(k)][0];
    cnt[k][1]=cnt[ls(k)][1]+cnt[rs(k)][1];
}
inline void push_down(int k,int l,int r)
{
    int mid=(l+r)>>1;
    if(tag[k][0])
    {
        cnt[ls(k)][0]=mid-l+1;
        cnt[ls(k)][1]=0;
        cnt[rs(k)][0]=r-mid;
        cnt[rs(k)][1]=0;
        tag[ls(k)][0]=1;
        tag[ls(k)][1]=0;
        tag[rs(k)][0]=1;
        tag[rs(k)][1]=0;
        tag[k][0]=0;
    }
    if(tag[k][1])
    {
        cnt[ls(k)][0]=0;
        cnt[ls(k)][1]=mid-l+1;
        cnt[rs(k)][0]=0;
        cnt[rs(k)][1]=r-mid;
        tag[ls(k)][0]=0;
        tag[ls(k)][1]=1;
        tag[rs(k)][0]=0;
        tag[rs(k)][1]=1;
        tag[k][1]=0;
    }
}
inline void build(int k,int l,int r)
{
    cnt[k][0]=cnt[k][1]=tag[k][0]=tag[k][1]=0;
    if(l==r)
    {
        cnt[k][b[l]-'0']=1;
        return;
    }
    int mid=(l+r)>>1;
    build(ls(k),l,mid);
    build(rs(k),mid+1,r);
    push_up(k);
}
inline void update(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
    {
        cnt[k][p]=r-l+1;
        cnt[k][p^1]=0;
        tag[k][p]=1;
        tag[k][p^1]=0;
        return;
    }
    push_down(k,l,r);
    int mid=(l+r)>>1;
    if(nl<=mid)
        update(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        update(nl,nr,mid+1,r,rs(k),p);
    push_up(k);
}
inline int query(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
        return cnt[k][p];
    push_down(k,l,r);
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res+=query(nl,nr,l,mid,ls(k),p);
    if(nr>mid)
        res+=query(nl,nr,mid+1,r,rs(k),p);
    return res;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>a>>b;
        a=" "+a;
        b=" "+b;
        build(1,1,n);
        v.clear();
        for(int i=1;i<=m;++i)
        {
            int x,y;
            cin>>x>>y;
            v.push_back({x,y});
        }
        reverse(v.begin(),v.end());
        bool flag=1;
        for(auto i:v)
        {
            int c0=query(i.first,i.second,1,n,1,0),c1=query(i.first,i.second,1,n,1,1);
            if(c0==c1)
            {
                puts("NO");
                flag=0;
                break;
            }
            if(c0<c1)
                update(i.first,i.second,1,n,1,1);
            else
                update(i.first,i.second,1,n,1,0);
        }
        if(!flag)
            continue;
        for(int i=1;i<=n;++i)
            if(!query(i,i,1,n,1,a[i]-'0'))
            {
                puts("NO");
                flag=0;
                break;
            }
        if(flag)
            puts("YES");
    }
    return 0;
}