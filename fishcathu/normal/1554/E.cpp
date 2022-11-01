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
const int N=1E5+10;
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
const int p=998244353;
int head[N],nex[N<<1],to[N<<1],cnt;
bool ans[N];
void add(int u,int v)
{
    nex[++cnt]=head[u];
    head[u]=cnt;
    to[cnt]=v;
}
int dfs(int x,int f,int k)
{
    int res=0;
    for(int i=head[x];i;i=nex[i])
    {
        int t=to[i];
        if(t==f)continue;
        int g=dfs(t,x,k);
        if(g<0)return -1;
        res+=!g;
    }
    if(!(res%k))return 0;
    if(!((res+1)%k))return 1;
    return -1;
}
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)head[i]=0;
    cnt=0;
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        add(u,v);
        add(v,u);
    }
    --n;
    int res=1;
    for(int i=n;i--;)res=res*2%p;
    for(int i=n;i>=2;--i)
    {
        ans[i]=0;
        if(n%i)continue;
        int tmp=i<<1;
        while(tmp<=n&&!ans[tmp])tmp+=i;
        if(tmp<=n)continue;
        ans[i]=!dfs(1,0,i);
        res-=ans[i];
    }
    write((res+p)%p,32);
    for(int i=2;i<=n;++i)putchar(ans[i]|48),putchar(32);
    putchar(48),putchar(10);
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}