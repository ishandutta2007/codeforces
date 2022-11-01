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
const int N=2E5+10,M=4E5+10;
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
const int p=998244353;
mt19937 mtrand(time(0));
int fac[M],inv[M];
int val[N],lc[N],rc[N],key[N],laz[N];
int root,cnt;
void push(int i)
{
    if(!laz[i])return;
    val[i]+=laz[i];
    laz[lc[i]]+=laz[i];
    laz[rc[i]]+=laz[i];
    laz[i]=0;
}
void split(int i,int &x,int &y,int k)
{
    if(!i)x=y=0;
    else
    {
        push(i);
        if(val[i]<=k)
        {
            x=i;
            split(rc[i],rc[i],y,k);
        }
        else
        {
            y=i;
            split(lc[i],x,lc[i],k);
        }
    }
}
int merge(int x,int y)
{
    if(!x||!y)return x|y;
    if(key[x]<key[y])
    {
        push(x);
        rc[x]=merge(rc[x],y);
        return x;
    }
    push(y);
    lc[y]=merge(x,lc[y]);
    return y;
}
void solve()
{
    int n=read(),s=1;
    root=cnt=0;
    for(int m=read();m--;)
    {
        read();
        int x=read(),u,v;
        split(root,root,u,x-1);
        split(u,u,v,x);
        if(!u)
        {
            u=++cnt;
            val[u]=x;
            lc[u]=rc[u]=laz[u]=0;
            key[u]=mtrand();
            ++s;
        }
        laz[u=merge(u,v)]=1;
        root=merge(root,u);
    }
    write(fac[n*2-s]*1LL*inv[n]%p*inv[n-s]%p,'\n');
}
int main()
{
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<M;++i)inv[i]=(p-p/i)*1LL*inv[p%i]%p;
    for(int i=2;i<M;++i)
    {
        fac[i]=fac[i-1]*1LL*i%p;
        inv[i]=inv[i-1]*1LL*inv[i]%p;
    }
    for(int x=read();x--;)
    {
        solve();
    }
}