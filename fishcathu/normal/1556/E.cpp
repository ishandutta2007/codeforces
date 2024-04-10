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
const int N=4E5+10;
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
int a[N>>2];
struct node{ll sum,mx,mn;}b[N];
node merge(node l,node r){return {l.sum+r.sum,max(l.mx,l.sum+r.mx),min(l.mn,l.sum+r.mn)};}
void build(int i,int l,int r)
{
    if(l==r)b[i]={a[l],a[l],a[l]};
    else
    {
        int m=l+r>>1;
        build(ls,l,m);
        build(rs,m+1,r);
        b[i]=merge(b[ls],b[rs]);
    }
}
node ask(int i,int l,int r,int x,int y)
{
    if(l>=x&&r<=y)return b[i];
    int m=l+r>>1;
    if(y<=m)return ask(ls,l,m,x,y);
    if(x>m)return ask(rs,m+1,r,x,y);
    return merge(ask(ls,l,m,x,y),ask(rs,m+1,r,x,y));
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]-=read();
    for(int i=1;i<=n;++i)a[i]+=read();
    build(1,1,n);
    while(m--)
    {
        int l=read(),r=read();
        node x=ask(1,1,n,l,r);
        if(x.sum||x.mn<0)puts("-1");
        else write(x.mx,'\n');
    }
}