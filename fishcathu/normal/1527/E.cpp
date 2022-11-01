#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=35001,M=101;
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
int pre[N],las[N],dp[N][M];
int L[N<<2],R[N<<2],mn[N<<2],laz[N<<2];
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
void init(int i,int k)
{
    laz[i]=0;
    if(L[i]==R[i])mn[i]=dp[L[i]][k];
    else
    {
        init(ls,k);
        init(rs,k);
        mn[i]=min(mn[ls],mn[rs]);
    }
}
void work(int i,int val)
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
    if(L[i]>x)return;
    if(R[i]<=x)work(i,val);
    else
    {
        push_down(i);
        add(ls,x,val);
        add(rs,x,val);
        mn[i]=min(mn[ls],mn[rs]);
    }
}
int getmn(int i,int x)
{
    if(L[i]>x)return inf;
    if(R[i]<=x)return mn[i];
    push_down(i);
    return min(getmn(ls,x),getmn(rs,x));
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        int x=read();
        pre[i]=las[x]?las[x]:i;
        las[x]=i;
    }
    for(int i=1;i<=n;++i)dp[i][1]=dp[i-1][1]+i-pre[i];
    build(1,1,n);
    for(int i=2;i<=m;++i)
    {
        init(1,i-1);
        for(int j=i;j<=n;++j)
        {
            add(1,pre[j]-1,j-pre[j]);
            dp[j][i]=getmn(1,j-1);
        }
    }
    write(dp[n][m],'\n');
}