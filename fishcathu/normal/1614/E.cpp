#include<bits/stdc++.h>
#define ls lc[i]
#define rs rc[i]
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=4E5+10;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
bool cmin(auto &l,auto r){return l>r?l=r,1:0;}
bool cmax(auto &l,auto r){return l<r?l=r,1:0;}
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
const int p=1E9+1;
mt19937 mtrand(time(0));
int mn[N],mx[N],laz[N],key[N];
int lc[N],rc[N],siz[N];
int cnt,root,u,v;
void push(int i)
{
    if(!laz[i])return;
    mn[i]+=laz[i];
    mx[i]+=laz[i];
    laz[ls]+=laz[i];
    laz[rs]+=laz[i];
    laz[i]=0;
}
void split(int i,int &x,int &y,int k)
{
    if(!i)return void(x=y=0);
    push(i);
    if(k>=mx[i])
    {
        x=i;
        siz[i]-=siz[rs];
        split(rs,rs,y,k);
        siz[i]+=siz[rs];
    }
    else if(k<mn[i])
    {
        y=i;
        siz[i]-=siz[ls];
        split(ls,x,ls,k);
        siz[i]+=siz[ls];
    }
    else
    {
        x=i,y=++cnt;
        mn[y]=k+1;
        mx[y]=mx[i];
        rc[y]=rs;
        siz[y]=mx[i]-k+siz[rs];
        key[y]=mtrand();
        mx[i]=k;
        rs=0;
        siz[i]-=siz[y];
    }
}
int merge(int x,int y)
{
    if(!x||!y)return x|y;
    if(key[x]<key[y])
    {
        push(x);
        siz[x]+=siz[y];
        rc[x]=merge(rc[x],y);
        return x;
    }
    push(y);
    siz[y]+=siz[x];
    lc[y]=merge(x,lc[y]);
    return y;
}
int ask(int k)
{
    for(int i=root;1;)
    {
        push(i);
        int y=k-siz[ls],z=k-siz[i]+siz[rs];
        if(y>0&&z<=0)return mn[i]+y-1;
        if(y<=0)i=ls;
        else k=z,i=rs;
    }
}
int main()
{
    root=++cnt;
    mn[root]=0;
    mx[root]=p-1;
    siz[root]=p;
    key[root]=mtrand();
    for(int n=read(),las=0;n--;)
    {
        int x=read();
        split(root,root,u,x-1);
        split(u,u,v,x);
        ++laz[root];
        --laz[v];
        root=merge(root,merge(u,v));
        for(int m=read();m--;)write(las=ask((read()+las)%p+1),'\n');
    }
}