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
const int N=1010;
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
int a[N],fa[N],cnt;
vector<int>to[N];
void dfs(int x)
{
    a[++cnt]=x;
    for(int t:to[x])
    {
        if(t==fa[x])continue;
        fa[t]=x;
        dfs(t);
    }
}
int ask(int n)
{
    printf("? %d ",n);
    for(int i=1;i<=n;++i)write(a[i],' ');
    putchar('\n');
    fflush(stdout);
    return read();
}
int main()
{
    for(int n=read();--n;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    dfs(1);
    int y=ask(cnt),l=2,r=cnt;
    while(l^r)
    {
        int m=l+r>>1;
        ask(m)^y?l=m+1:r=m;
    }
    printf("! %d %d\n",fa[a[l]],a[l]);
}