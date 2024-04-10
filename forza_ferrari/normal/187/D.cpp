#include<iostream>
#include<cstdio>
#include<set>
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
int n,G,R,m,lst,len[200005],ans[200005];
set<element> s;
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
    s.erase(it1,it2);
    s.insert(element(l,r,val));
}
inline int query(int pos)
{
    set<element>::iterator it=s.lower_bound(element(pos));
    if(it!=s.end()&&it->l==pos)
        return it->val;
    --it;
    return it->val;
}
signed main()
{
    n=read(),G=read(),R=read();
    for(int i=1;i<=n+1;++i)
        len[i]=read()+len[i-1];
    s.insert(element(0,G+R-1,n+1));
    for(int i=n;i;--i)
    {
        int l=(G-len[i]%(R+G)+R+G)%(R+G),r=((R+G)-len[i]%(R+G))%(R+G),pos=query(r);
        if(pos==n+1)
            ans[i]=len[n+1]-len[i];
        else
            ans[i]=(len[pos]-len[i]+G+R-1)/(G+R)*(G+R)+ans[pos];
        if(l<r)
            assign(l,r,i);
        else
        {
            assign(0,r,i);
            assign(l,G+R-1,i);
        }
    }
    m=read();
    while(m--)
    {
        int t=read()^(lst%1);
        int pos=query(t%(G+R));
        if(pos==n+1)
            print(lst=t+len[n+1]);
        else
            print(lst=(t+len[pos]+G+R-1)/(G+R)*(G+R)+ans[pos]);
        putchar('\n');
    }
    return 0;
}