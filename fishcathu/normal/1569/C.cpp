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
const int N=2E5+10;
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
const int p=998244353;
int a[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    sort(a+1,a+1+n);
    if(a[n-1]<a[n]-1)puts("0");
    else
    {
        int res=1;
        if(a[n-1]^a[n])
        {
            int t=n-1;
            while(a[--t]==a[n-1]);
            t=n-t;
            res=t-1;
            for(int i=p-2;i;i>>=1)
            {
                if(i&1)res=res*1LL*t%p;
                t=t*1LL*t%p;
            }
        }
        for(int i=1;i<=n;++i)res=res*1LL*i%p;
        write(res,'\n');
    }
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}