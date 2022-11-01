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
int a[N],ans;
const int p=998244353;
void solve1(int n,ll k)
{
    int i=0;
    for(ll s=0;s<k;)s+=a[++i];
    ans=max(n-1-i,0);
}
void solve2(int *a,int n,ll k)
{
    ll s=0;
    int w=1+!(n&1);
    for(int i=w;i<=n;i+=2)s+=a[i];
    for(int i=n,j=w;i>=w;i-=2)
    {
        while(j<i&&s>=k)
        {
            s-=a[j];
            j+=2;
        }
        if(j>i)s+=a[j-=2];
        if(s>=k)
        {
            int t=i+1>>1;
            ans=(ans+t*1LL*(t+1)/2)%p;
            break;
        }
        ans=(ans+(j-1>>1))%p;
        s+=a[i-1];
    }
}
void solve()
{
    int n=read();
    ll k=2;
    for(int i=1;i<=n;++i)k+=a[i]=read();
    k>>=1;
    solve1(n,k);
    solve2(a,n,k);
    solve2(a,n-1,k-a[n]);
    solve2(a,n-1,k);
    solve2(a,n-2,k-a[n-1]);
    k-=a[1];
    solve2(a+3,n-3,k);
    solve2(a+3,n-4,k-a[n]);
    solve2(a+3,n-4,k);
    solve2(a+3,n-5,k-a[n-1]);
    write(ans,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}