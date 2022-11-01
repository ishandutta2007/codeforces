#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb emplace_back
#define mp make_pair
using namespace std;
typedef int64_t ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=1E5+1;
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
const int p=1E9+7;
int u[N],d[N];
void init()
{
    u[0]=u[1]=d[0]=d[1]=1;
    for(int i=2;i<N;++i)d[i]=(p-p/i)*1LL*d[p%i]%p;
    for(int i=2;i<N;++i)
    {
        u[i]=u[i-1]*1LL*i%p;
        d[i]=d[i-1]*1LL*d[i]%p;
    }
}
void solve()
{
    int n=read(),k=read()-1,ans=1;
    for(int i=1;1;++i)
    {
        int t=n-i*k+k;
        if(t<i)break;
        ans=(ans+u[t]*1LL*u[n-i]%p*d[n]%p*d[t-i])%p;
    }
    write(ans,'\n');
}
int main()
{
    init();
    for(int x=read();x--;)
    {
        solve();
    }
}