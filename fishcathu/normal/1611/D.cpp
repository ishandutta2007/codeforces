#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E5+10;
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
int fa[N],dep[N],ans[N];
void solve()
{
    int n=read(),root;
    for(int i=1;i<=n;++i)
    {
        int x=read();
        if(x^i)fa[i]=x;
        else fa[i]=0,root=i;
    }
    for(int i=1;i<=n;++i)dep[i]=-1;
    bool flag=0;
    for(int i=0;i<n;++i)
    {
        int x=read();
        if(!~dep[fa[x]])flag=1;
        ans[x]=i-dep[fa[x]];
        dep[x]=i;
    }
    if(flag)puts("-1");
    else
    {
        for(int i=1;i<=n;++i)write(ans[i],' ');
        putchar('\n');
    }
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}