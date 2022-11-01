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
const int N=3E5+10;
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
ll a[N];
int k;
vector<pii>to[N];
vct ans;
bitset<N>b;
void dfs(int x)
{
    b[x]=1;
    for(pii t:to[x])
    {
        if(b[t.fi])continue;
        dfs(t.fi);
        if(a[x]+a[t.fi]>=k)
        {
            a[x]+=a[t.fi]-k;
            write(t.se,'\n');
        }
        else ans.pb(t.se);
    }
}
int main()
{
    int n=read(),m=read();
    k=read();
    ll s=0;
    for(int i=1;i<=n;++i)s+=a[i]=read();
    if(s<(n-1)*1LL*k)
    {
        puts("NO");
        return 0;
    }
    for(int i=1;i<=m;++i)
    {
        int u=read(),v=read();
        to[u].pb(mp(v,i));
        to[v].pb(mp(u,i));
    }
    puts("YES");
    dfs(1);
    for(int i=ans.size();i--;)write(ans[i],'\n');
}