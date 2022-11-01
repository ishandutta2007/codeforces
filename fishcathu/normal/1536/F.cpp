#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
const int N=1E6+10;
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
int fac[N],inv[N];
int main()
{
    int n=read();
    const int p=1E9+7;
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<=n;++i)inv[i]=(p-p/i)*1LL*inv[p%i]%p;
    for(int i=2;i<=n;++i)
    {
        fac[i]=fac[i-1]*1LL*i%p;
        inv[i]=inv[i-1]*1LL*inv[i]%p;
    }
    int ans=fac[n-1];
    for(int i=n&1|2,z=n>>1;i<=z;i+=2)
    {
        ans=(ans+fac[n-i-1]*1LL*inv[i]%p*inv[n-i*2]%p*fac[n-i])%p;
    }
    write(ans*2LL*n%p,'\n');
}