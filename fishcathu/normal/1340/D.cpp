#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb emplace_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
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
vct to[N];
int du[N],k;
vector<pii>ans;
void dfs(int x,int f)
{
    static int now=0;
    ans.pb(mp(x,now));
    for(int t:to[x])
    {
        if(t==f)continue;
        if(now==k)ans.pb(mp(x,now=k-du[x]));
        int res=now++;
        dfs(t,x);
        if(now!=res)ans.pb(mp(t,now=res));
        ans.pb(mp(x,++now));
    }
}
int main()
{
    int n=read();
    for(int i=n;--i;)
    {
        int u=read(),v=read();
        to[u].pb(v);
        to[v].pb(u);
        ++du[u];
        ++du[v];
    }
    k=*max_element(du+1,du+1+n);
    dfs(1,0);
    write(ans.size(),'\n');
    for(pii x:ans)
    {
        write(x.fi,' ');
        write(x.se,'\n');
    }
}