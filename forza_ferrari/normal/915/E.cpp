#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
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
int n,m,ans;
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
    for(set<element>::iterator it=it1;it!=it2;++it)
        ans+=(it->r-it->l+1)*(val^it->val)*(val? 1:-1);
    s.erase(it1,it2);
    s.insert(element(l,r,val));
}
int main()
{
    n=read(),m=read();
    s.insert(element(1,n,1));
    ans=n;
    while(m--)
    {
        int l=read(),r=read(),opt=read()-1;
        assign(l,r,opt);
        print(ans);
        putchar('\n');
    }
    return 0;
}