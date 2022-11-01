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
const int p=1E9+7;
int f[N];
int qpow(int x,int n){int res=1;while(n){if(n&1)res=res*1LL*x%p;n>>=1;x=x*1LL*x%p;}return res;}
void solve()
{
    int n=read(),m=read();
    if(n&1)write(qpow(f[n-1]+1,m),'\n');
    else write(((qpow(f[n],m)-qpow(f[n-1]-1,m)+p)*1LL*qpow(f[n-1]+1,p-2)+qpow(f[n-1]-1,m))%p,'\n');
}
int main()
{
    f[0]=1;
    for(int i=1;i<N;++i)f[i]=f[i-1]*2%p;
    for(int x=read();x--;)
    {
        solve();
    }
}