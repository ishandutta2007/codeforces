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
const int mod=1000000007;
int n,m,seed,maxn;
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
void print(int x)
{
    if(x>=10)
        print(x/10);
    putchar(x%10+'0');
}
inline int pw(int a,int b,int p)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res=res*a%p;
        b>>=1;
        a=a*a%p;
    }
    return res;
}
inline int rnd()
{
    int ret=seed;
    seed=(seed*7+13)%mod;
    return ret;
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
inline void add(int l,int r,int val)
{
    set<element>::iterator it2=split(r+1),it1=split(l);
    for(set<element>::iterator it=it1;it!=it2;++it)
        it->val+=val;
}
inline int kth(int l,int r,int k)
{
    set<element>::iterator it2=split(r+1),it1=split(l);
    multiset<pair<int,int> > tmp;
    for(set<element>::iterator it=it1;it!=it2;++it)
        tmp.insert({it->val,it->r-it->l+1});
    for(auto i:tmp)
    {
        k-=i.second;
        if(k<=0)
            return i.first;
    }
    return -1;
}
inline int query(int l,int r,int x,int y)
{
    set<element>::iterator it2=split(r+1),it1=split(l);
    int res=0;
    for(set<element>::iterator it=it1;it!=it2;++it)
        res=(res+(it->r-it->l+1)*pw(it->val%y,x,y)%y)%y;
    return res;
}
signed main()
{
    n=read(),m=read(),seed=read(),maxn=read();
    for(int i=1;i<=n;++i)
        s.insert(element(i,i,rnd()%maxn+1));
    s.insert(element(n+1,n+1,0));
    while(m--)
    {
        int opt=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x,y;
        if(l>r)
            l^=r^=l^=r;
        if(opt==3)
            x=rnd()%(r-l+1)+1;
        else
            x=rnd()%maxn+1;
        if(opt==4)
            y=rnd()%maxn+1;
        if(opt==1)
            add(l,r,x);
        if(opt==2)
            assign(l,r,x);
        if(opt==3)
        {
            print(kth(l,r,x));
            putchar('\n');
        }
        if(opt==4)
        {
            print(query(l,r,x,y));
            putchar('\n');
        }
    }
    return 0;
}