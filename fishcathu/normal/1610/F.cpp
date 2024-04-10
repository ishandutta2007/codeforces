#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=3E5+10;
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
vector<array<int,3>>to[N<<1];
bitset<N>b[2];
int ans[N<<1];
void add(int u,int v,int id){to[u].pb({v,id,1}),to[v].pb({u,id,2});}
void dfs(int x)
{
    while(!to[x].empty())
    {
        auto [t,id,w]=to[x].back();
        to[x].pop_back();
        if(!ans[id])return ans[id]=w,dfs(t);
    }
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=m;++i)
    {
        int u=read(),v=read(),w=read()-1;
        b[w].flip(u);
        b[w].flip(v);
        if(w)add(u+n,v+n,i);
        else add(u,v,i);
    }
    write(b[0].count(),'\n');
    for(int i=1,j=m;i<=n;++i)
    {
        if(b[0][i]&b[1][i])add(i,i+n,++j);
        else if(b[0][i])add(i,0,++j);
        else if(b[1][i])add(i+n,0,++j);
    }
    for(int i=n<<1;i>=1;--i)dfs(i);
    for(int i=1;i<=m;++i)putchar(ans[i]|48);
}