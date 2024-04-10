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
const int N=3E5+10;
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
int in[N],a[N],f[N];
set<pii>st;
vector<int>to[N],q;
int g(int x){return x<0?0:f[x];}
void dfs(int x,int d)
{
    if(to[x].size()>1||in[x]>1)return;
    if(to[x].empty())++a[d];
    else dfs(to[x][0],d+1);
}
int main()
{
    const int p=998244353;
    int n=read(),m=read(),s=read();
    while(n--)
    {
        for(int y=read(),l=read(),r;--y;l=r)
        {
            r=read();
            if(!st.count({l,r}))
            {
                to[l].pb(r);
                st.insert({l,r});
                ++in[r];
            }
        }
    }
    for(int i=1;i<=s;++i)if(!in[i])dfs(i,1);
    for(int i=1;i<=s;++i)if(a[i])q.pb(i);
    f[0]=1;
    for(int i=1;i<=m;++i)for(int x:q)f[i]=(f[i]+g(i-x)*1LL*a[x])%p;
    write(f[m],'\n');
}