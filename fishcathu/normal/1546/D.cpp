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
const int p=998244353;
int fac[N],inv[N];
void solve()
{
    int l=0,r=0;
    for(int i=read(),j=1;i--;)
    {
        char c;
        do c=getchar();while(c<48);
        if(c&1)l+=j^=1;
        else ++r,j=1;
    }
    write(fac[l+r]*1LL*inv[l]%p*inv[r]%p,'\n');
}
int main()
{
    fac[0]=fac[1]=inv[0]=inv[1]=1;
    for(int i=2;i<N;++i)inv[i]=(p-p/i)*1LL*inv[p%i]%p;
    for(int i=2;i<N;++i)
    {
        fac[i]=fac[i-1]*1LL*i%p;
        inv[i]=inv[i-1]*1LL*inv[i]%p;
    }
    for(int x=read();x--;)
    {
        solve();
    }
}