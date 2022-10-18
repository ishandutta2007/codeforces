#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
#define int long long
struct element
{
    int l,r;
    mutable int val;
    element(int l_,int r_,int val_):
        l(l_),r(r_),val(val_){}
    element(int l_):
        l(l_){}
    bool operator <(const element &other) const
    {
        return l<other.l;
    }
};
set<element> s;
int n,m,ans[100001<<2],tag[100001<<2];
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
    ans[k]=ans[ls(k)]+ans[rs(k)];
}
inline void push_down(int k,int l,int r)
{
    if(tag[k])
    {
        int mid=(l+r)>>1;
        ans[ls(k)]+=tag[k]*(mid-l+1);
        ans[rs(k)]+=tag[k]*(r-mid);
        tag[ls(k)]+=tag[k];
        tag[rs(k)]+=tag[k];
        tag[k]=0;
    }
}
void update(int nl,int nr,int l,int r,int k,int p)
{
    if(l>=nl&&r<=nr)
    {
        ans[k]+=p*(r-l+1);
        tag[k]+=p;
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
int query(int nl,int nr,int l,int r,int k)
{
    if(l>=nl&&r<=nr)
        return ans[k];
    push_down(k,l,r);
    int mid=(l+r)>>1,res=0;
    if(nl<=mid)
        res+=query(nl,nr,l,mid,ls(k));
    if(nr>mid)
        res+=query(nl,nr,mid+1,r,rs(k));
    return res;
}
inline set<element>::iterator split(int pos)
{
    set<element>::iterator it=s.lower_bound(element(pos));
    if(it!=s.end()&&it->l==pos)
        return it;
    --it;
    int l=it->l,r=it->r,val=it->val;
    s.erase(it);
    s.insert(element(l,pos-1,val));
    return s.insert(element(pos,r,val)).first;
}
inline void assign(int l,int r,int val)
{
    set<element>::iterator it2=split(r+1),it1=split(l);
    s.erase(it1,it2);
    s.insert(element(l,r,val));
}
inline void update(int l,int r,int val)
{
    set<element>::iterator it2=split(r+1),it1=split(l);
    for(set<element>::iterator it=it1;it!=it2;++it)
        update(it->l,it->r,1,n,1,abs(it->val-val));
    assign(l,r,val);
}
signed main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        s.insert(element(i,i,i));
    while(m--)
    {
        int opt=read(),l=read(),r=read();
        if(opt==1)
        {
            int val=read();
            update(l,r,val);
        }
        if(opt==2)
            printf("%lld\n",query(l,r,1,n,1));
    }
    return 0;
}