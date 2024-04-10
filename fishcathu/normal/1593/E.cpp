#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
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
vector<int>to[N];
int du[N];
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)to[i].clear(),du[i]=0;
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
        ++du[u];
        ++du[v];
    }
    vector<int>a;
    for(int i=1;i<=n;++i)if(du[i]<2)a.pb(i);
    while(m--&&n)
    {
        vector<int>b;
        for(int x:a)
        {
            --n;
            for(int t:to[x])
            {
                if(--du[t]==1)
                {
                    b.pb(t);
                }
            }
        }
        a=b;
    }
    write(n,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}