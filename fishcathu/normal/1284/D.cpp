#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
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
int a[N],b[N],c[N],d[N],n;
pii _a[N],_b[N],_c[N],_d[N];
void solve(int *a,pii *b,bool k)
{
    sort(b+1,b+1+n);
    for(int i=n;i>=1;--i)
    {
        b[i].se^=b[i+1].se;
    }
    for(int i=1;i<=n;++i)
    {
        if(k)a[i]=upper_bound(b+1,b+1+n,make_pair(a[i],inf))->se;
        else a[i]=lower_bound(b+1,b+1+n,make_pair(a[i],0))->se;
    }
}
int main()
{
    n=read();
    const int p=998244353;
    for(int i=1,j=1;i<=n;++i)
    {
        a[i]=_a[i].fi=read();
        b[i]=_b[i].fi=read();
        c[i]=_c[i].fi=read();
        d[i]=_d[i].fi=read();
        _a[i].se=_b[i].se=_c[i].se=_d[i].se=j;
        j=j*2%p;
    }
    solve(a,_b,0);
    solve(b,_a,1);
    solve(c,_d,0);
    solve(d,_c,1);
    for(int i=1;i<=n;++i)
    {
        if((a[i]^b[i])!=(c[i]^d[i]))
        {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}