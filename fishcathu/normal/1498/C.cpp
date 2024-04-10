#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1010;
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
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int l[N],r[N],a[N],b[N];
const int p=1E9+7;
void solve()
{
    memset(l,0,sizeof l);
    memset(r,0,sizeof r);
    int n=read(),m=read();
    for(int i=2;i<=n;++i)r[i]=1;
    int ans=1+(m!=1);
    while(--m)
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        for(int i=n;--i;)
        {
            a[i]=(r[i+1]+a[i+1])%p;
        }
        for(int i=2;i<=n;++i)
        {
            b[i]=(l[i-1]+b[i-1])%p;
        }
        memcpy(l,a,sizeof l);
        memcpy(r,b,sizeof r);
        ans=(((ans+l[1])%p)+r[n])%p;
    }
    write(ans,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}