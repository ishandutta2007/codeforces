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
const int N=3E5+10,M=8E6+10;
const int inf=1<<30;
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
struct st
{
    int u,v,w;
    bool operator<(const st m)const
    {
        return w<m.w;
    }
}a[N];
int f[M],g[M];
void add(int i,int l,int r,int x,int y,int z)
{
    if(l>y||r<x)return;
    if(l>=x&&r<=y)f[i]+=z;
    else
    {
        int m=l+r>>1;
        add(ls,l,m,x,y,z);
        add(rs,m+1,r,x,y,z);
    }
    g[i]=f[i]?r-l+1:g[ls]+g[rs];
}
int main()
{
    int n=read(),m=read()-1;
    for(int i=1;i<=n;++i)
    {
        a[i].u=read();
        a[i].v=read()-1;
        a[i].w=read();
    }
    sort(a+1,a+1+n);
    int ans=inf;
    for(int l=0,r=1;r<=n;++r)
    {
        add(1,1,m,a[r].u,a[r].v,1);
        while(g[1]==m)
        {
            ++l;
            add(1,1,m,a[l].u,a[l].v,-1);
        }
        if(l)ans=min(ans,a[r].w-a[l].w);
    }
    write(ans,'\n');
}