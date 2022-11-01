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
const int N=50;
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
int a[N],s[N];
ll g[N][N],ans[N];
bool dfs(ll res,int i)
{
    if(!i)return res==ans[__builtin_popcountll(res)];
    int t=__builtin_popcountll(res&g[i][s[i]]);
    res&=~g[i][s[i]];
    for(int j=t+a[i];j>=t;--j)
    {
        if(!dfs(res^g[i][j],i-1))
        {
            return 0;
        }
    }
    return 1;
}
bool solve()
{
    int n=read(),m=read();
    if(n==1)return 1;
    ll res=(1LL<<n)-1;
    for(int i=m;i>=1;--i)
    {
        s[i]=read();
        for(int j=1;j<=s[i];++j)
        {
            g[i][j]=1LL<<read()-1;
            if(res&g[i][j])
            {
                ++a[i];
                res^=g[i][j];
            }
            g[i][j]^=g[i][j-1];
        }
    }
    if(res)return 0;
    for(int i=0;i<n;++i)ans[i+1]=ans[i]^1LL<<i;
    return dfs(0,m);
}
int main()
{
    puts(solve()?"ACCEPTED":"REJECTED");
}