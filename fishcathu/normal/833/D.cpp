#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1E5+10;
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
const int p=1E9+7;
vector<array<int,3>>to[N];
int sum,mn,root;
int siz[N],pre[N];
bool vis[N];
pii q1[N],q2[N];
int cnt,ans=1;
int qpow(int x,int n){int res=1;while(n){if(n&1)res=res*1LL*x%p;x=x*1LL*x%p,n>>=1;}return res;}
void getroot(int x,int f)
{
    siz[x]=1;
    int mx=0;
    for(auto [t,w,k]:to[x])
    {
        if(t==f||vis[t])continue;
        getroot(t,x);
        siz[x]+=siz[t];
        cmax(mx,siz[t]);
    }
    cmax(mx,sum-siz[x]);
    if(mx<mn)root=x,mn=mx;
}
void getdis(int x,int f,int a,int b,int z)
{
    q1[++cnt]={a-b*2,z},q2[cnt]={b-a*2,z};
    for(auto [t,w,k]:to[x])
    {
        if(t==f||vis[t])continue;
        getdis(t,x,a+!k,b+k,z*1LL*w%p);
    }
}
int calc()
{
    sort(q1+1,q1+1+cnt),sort(q2+1,q2+1+cnt);
    int y=1,z=1;
    for(int i=1;i<=cnt;++i)pre[i]=pre[i-1]*1LL*q1[i][1]%p,y=y*1LL*q1[i][1]%p;
    y=qpow(y,cnt-1);
    for(int l=1,r=cnt;l<r;)
    {
        if(q1[l][0]+q1[r][0]>0)z=z*1LL*pre[r-1]%p*qpow(q1[r][1],r-l)%p,y=y*1LL*pre[l-1]%p,--r;
        else ++l;
    }
    for(int i=1;i<=cnt;++i)pre[i]=pre[i-1]*1LL*q2[i][1]%p;
    for(int l=1,r=cnt;l<r;)
    {
        if(q2[l][0]+q2[r][0]>0)z=z*1LL*pre[r-1]%p*qpow(q2[r][1],r-l)%p,y=y*1LL*pre[l-1]%p,--r;
        else ++l;
    }
    return y*1LL*qpow(z,p-2)%p;
}
void cdq(int x,int n)
{
    sum=mn=n;
    getroot(x,0);
    x=root;
    vis[x]=1;
    cnt=0;
    getdis(x,0,0,0,1);
    ans=ans*1LL*calc()%p;
    for(auto [t,w,k]:to[x])
    {
        if(vis[t])continue;
        cnt=0;
        getdis(t,x,!k,k,w);
        ans=ans*1LL*qpow(calc(),p-2)%p;
        cdq(t,siz[t]<siz[x]?siz[t]:n-siz[x]);
    }
}
int main()
{
    int n=read();
    for(int i=n;--i;)
    {
        int u=read(),v=read(),w=read(),k=read();
        to[u].pb({v,w,k});
        to[v].pb({u,w,k});
    }
    pre[0]=1;
    cdq(1,n);
    write(ans,'\n');
}