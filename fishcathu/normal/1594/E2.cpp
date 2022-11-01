#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
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
const int p=1E9+7;
map<ll,array<int,3>>f;
int qpow(ll n){int res=1;for(int i=2;n;n>>=1){if(n&1)res=res*1LL*i%p;i=i*1LL*i%p;}return res;}
int main()
{
    ll n=(1LL<<read())-1;
    int m=read(),ans=qpow(n-m);
    while(m--)
    {
        ll x=read();
        char c[10];
        scanf("%s",c);
        if(c[0]=='w'||c[0]=='y')f[x][0]=1;
        else if(c[0]=='g'||c[0]=='b')f[x][1]=1;
        else f[x][2]=1;
    }
    while(f.size()^1)
    {
        ll x=f.rbegin()->fi,t=x>>1;
        if(!f.count(t))f[t]={1,1,1};
        for(int i=3;i--;)f[t][i]=f[t][i]*1LL*(f[x][(i+1)%3]+f[x][(i+2)%3])%p;
        f.erase(x);
        --n;
    }
    array<int,3>a=f.begin()->se;
    for(int i=2;i--;)a[i]=(a[i]+a[i+1])%p;
    write(ans*1LL*qpow(n-1)%p*a[0]%p,'\n');
}