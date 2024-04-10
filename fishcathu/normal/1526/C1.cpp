#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb emplace_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=2E5+10;
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
vector<pii>a;
int L[N<<2],R[N<<2];
ll mn[N<<2],laz[N<<2];
void build(int i,int l,int r)
{
    L[i]=l;
    R[i]=r;
    if(l!=r)
    {
        int m=l+r>>1;
        build(ls,l,m);
        build(rs,m+1,r);
    }
}
void work(int i,ll val)
{
    mn[i]+=val;
    laz[i]+=val;
}
void push_down(int i)
{
    if(!laz[i])return;
    work(ls,laz[i]);
    work(rs,laz[i]);
    laz[i]=0;
}
void add(int i,int x,int val)
{
    if(R[i]<x)return;
    if(L[i]>=x)work(i,val);
    else
    {
        push_down(i);
        add(ls,x,val);
        add(rs,x,val);
        mn[i]=min(mn[ls],mn[rs]);
    }
}
ll ask(int i,int x)
{
    if(R[i]<x)return inf;
    if(L[i]>=x)return mn[i];
    push_down(i);
    return min(ask(ls,x),ask(rs,x));
}
int main()
{
    int n=read(),ans=0;
    build(1,1,n);
    for(int i=1;i<=n;++i)
    {
        int x=read();
        if(x>=0)
        {
            add(1,i,x);
            ++ans;
        }
        else a.pb(mp(-x,i));
    }
    sort(a.begin(),a.end());
    for(pii x:a)
    {
        if(x.fi<=ask(1,x.se))
        {
            add(1,x.se,-x.fi);
            ++ans;
        }
    }
    write(ans,'\n');
}