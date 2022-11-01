#include<iostream>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E6+10;
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
int a[N],b[N];
ll c[N],r[N];
bool check()
{
    int n=read();
    ll s=0;
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i)
    {
        b[i]=read();
        a[i]-=b[i];
        s+=a[i];
    }
    if(s>0)return 0;
    c[n]=r[n]=0;
    for(int i=n;i>=2;--i)
    {
        c[i-1]=max(c[i]+a[i],0ll);
        r[i-1]=r[i]+a[i];
    }
    for(ll i=1,t=0,mx=0;i<=n;++i)
    {
        if(b[i]<c[i]||b[i]<r[i])return 0;
        t+=a[i];
        mx=max(mx,t);
        r[i+1]+=mx;
    }
    return 1;
}
int main()
{
    for(int x=read();x--;)
    {
        puts(check()?"YES":"NO");
    }
}