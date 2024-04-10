#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=8E5+10;
const int inf=1<<30;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
struct node{int fl,fr,gl,gr,len;ll ans;}a[N];
node merge(node x,node y)
{
    if(x.fr<=y.fl)
    {
        x.ans+=x.gr*1LL*y.gl;
        if(x.gl==x.len)x.gl+=y.gl;
        if(y.gr==y.len)y.gr+=x.gr;
    }
    return {x.fl,y.fr,x.gl,y.gr,x.len+y.len,x.ans+y.ans};
}
void build(int i,int l,int r)
{
    if(l==r)
    {
        int t=read();
        a[i]={t,t,1,1,1,1};
    }
    else
    {
        int m=l+r>>1;
        build(ls,l,m);
        build(rs,m+1,r);
        a[i]=merge(a[ls],a[rs]);
    }
}
void ass(int i,int l,int r,int w,int v)
{
    if(l==r)a[i].fl=a[i].fr=v;
    else
    {
        int m=l+r>>1;
        if(w<=m)ass(ls,l,m,w,v);
        else ass(rs,m+1,r,w,v);
        a[i]=merge(a[ls],a[rs]);
    }
}
node ask(int i,int l,int r,int x,int y)
{
    if(l>=x&&r<=y)return a[i];
    int m=l+r>>1;
    if(y<=m)return ask(ls,l,m,x,y);
    if(x>m)return ask(rs,m+1,r,x,y);
    return merge(ask(ls,l,m,x,y),ask(rs,m+1,r,x,y));
}
int main()
{
    int n=read(),m=read();
    build(1,1,n);
    while(m--)
    {
        int k=read(),u=read();
        if(k==1)ass(1,1,n,u,read());
        else write(ask(1,1,n,u,read()).ans,'\n');
    }
}