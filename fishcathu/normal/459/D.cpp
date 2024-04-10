#include<bits/extc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E6+10;
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
int a[N],b[N],c[N],f[N],q[N];
void add(int x){while(x)++q[x],x-=x&-x;}
int ask(int x){int res=0;while(x<N)res+=q[x],x+=x&-x;return res;}
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]=b[i]=read();
    sort(b+1,b+1+n);
    int m=unique(b+1,b+1+n)-b-1;
    for(int i=n;i>=1;--i)c[i]=++f[a[i]=lower_bound(b+1,b+1+m,a[i])-b];
    for(int i=1;i<=m;++i)f[i]=0;
    ll ans=0;
    for(int i=1;i<=n;++i)
    {
        ans+=ask(c[i]+1);
        add(++f[a[i]]);
    }
    write(ans,'\n');
}