#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1E6+10;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
void cmin(auto &l,auto r){l=l<r?l:r;}
void cmax(auto &l,auto r){l=l>r?l:r;}
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
int a[N],b[N],c[N],q[N],s;
vector<int>to[N];
pii val[N<<2];
void push(int x){while(x)++q[x],x-=x&-x;}
int ask(int x){int res=0;while(x<=s)res+=q[x],x+=x&-x;return res;}
pii operator+(pii l,pii r){cmax(l[1],l[0]+r[1]),l[0]+=r[0];return l;}
void build(int i,int l,int r)
{
    if(l==r)val[i]={-1,0};
    else
    {
        int m=l+r>>1;
        build(ls,l,m);
        build(rs,m+1,r);
        val[i]=val[ls]+val[rs];
    }
}
void ass(int i,int l,int r,int x,int w)
{
    if(l==r)val[i]={w,w};
    else
    {
        int m=l+r>>1;
        if(x<=m)ass(ls,l,m,x,w);
        else ass(rs,m+1,r,x,w);
        val[i]=val[ls]+val[rs];
    }
}
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=c[i]=read();
    for(int i=1;i<=m;++i)b[i]=read();
    sort(c+1,c+1+n);
    s=unique(c+1,c+1+n)-c-1;
    c[s+1]=0;
    for(int i=1;i<=s;++i)q[i]=0,to[i].clear();
    ll res=0;
    for(int i=1;i<=n;++i)
    {
        int x=lower_bound(c+1,c+1+s,a[i])-c;
        push(x);
        res+=ask(x+1);
        to[x].pb(i);
    }
    build(1,1,n);
    sort(b+1,b+1+m);
    for(int i=1;i<=m;++i)
    {
        int l=lower_bound(c+1,c+1+s,b[i-1])-c;
        int r=lower_bound(c+1,c+1+s,b[i])-c;
        res+=n-ask(r);
        if(b[i]^b[i-1])
        {
            for(int j=l;j<r;++j)for(int x:to[j])ass(1,1,n,x,1);
            if(c[r]==b[i])for(int x:to[r])ass(1,1,n,x,0);
        }
        res-=val[1][1];
    }
    write(res,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}