#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=3E5+10;
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
vector<int>to[N];
int fa[N],l[N],r[N],du[N],dep[N];
void dfs(int x)
{
    for(int t:to[x])
    {
        if(dep[t])continue;
        fa[t]=x;
        dep[t]=dep[x]+1;
        dfs(t);
    }
}
int main()
{
    int n=read();
    for(int m=read();m--;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
    }
    int m=read();
    for(int i=1;i<=m;++i)++du[l[i]=read()],++du[r[i]=read()];
    int s=0;
    for(int i=1;i<=n;++i)s+=du[i]&1;
    if(s){printf("NO\n%d\n",s>>1);return 0;}
    puts("YES");
    dep[1]=1;
    dfs(1);
    for(int i=1;i<=m;++i)
    {
        vector<int>u(1,l[i]),v(1,r[i]);
        while(l[i]^r[i])
        {
            if(dep[l[i]]>dep[r[i]])u.pb(l[i]=fa[l[i]]);
            else v.pb(r[i]=fa[r[i]]);
        }
        u.pop_back();
        reverse(v.begin(),v.end());
        write(u.size()+v.size(),'\n');
        for(int x:u)write(x,' ');
        for(int x:v)write(x,' ');
        putchar('\n');
    }
}