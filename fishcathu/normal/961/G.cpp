#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E5+10;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
void cmin(auto &l,auto r){l=l<r?l:r;}
void cmax(auto &l,auto r){l=l>r?l:r;}
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
int inv[N];
int qpow(int x,int n){int ans=1;while(n){if(n&1)ans=ans*1LL*x%p;x=x*1LL*x%p,n>>=1;}return ans;}
int f(int n,int m)
{
    int ans=0;
    for(int i=0;i<=m;++i)ans=(ans+qpow(p-1,i)*1LL*qpow(m-i,n)%p*inv[i]%p*inv[m-i])%p;
    return ans;
}
int main()
{
    int n=read(),m=read(),ans=0;
    inv[0]=inv[1]=1;
    for(int i=2;i<=m;++i)inv[i]=(p-p/i)*1LL*inv[p%i]%p;
    for(int i=2;i<=m;++i)inv[i]=inv[i]*1LL*inv[i-1]%p;
    for(int i=n;i--;)ans=(ans+read())%p;
    write((f(n,m)+(n-1LL)*f(n-1,m))%p*ans%p,'\n');
}