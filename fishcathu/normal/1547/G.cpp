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
const int N=4E5+10;
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
bitset<N>b;
int in[N],ans[N],q[N];
void solve()
{
    int n=read(),s=0;
    for(int i=1;i<=n;++i)
    {
        to[i].clear();
        in[i]=ans[i]=b[i]=0;
    }
    for(int i=read();i--;)to[read()].pb(read());
    
    b[q[++s]=1]=1;
    while(s)
    {
        int x=q[s--];
        for(int t:to[x])
        {
            if(!b[t])
            {
                b[q[++s]=t]=1;
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(!b[i])continue;
        for(int x:to[i])++in[x];
    }
    if(!in[1])s=q[1]=ans[1]=1;
    while(s)
    {
        int x=q[s--];
        for(int t:to[x])
        {
            ans[t]=min(ans[t]+ans[x],2);
            if(!--in[t])q[++s]=t;
        }
    }
    for(int i=1;i<=n;++i)
    {
        if(b[i]&&in[i])write(-1,' ');
        else write(ans[i],' ');
    }
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}