#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1E6+10;
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
int a[N],fac[N];
int main()
{
    const int p=1E9+7;
    fac[0]=1;
    for(int i=1;i<N;++i)fac[i]=fac[i-1]*1LL*i%p;
    for(int n=read();n--;)++a[read()-1];
    for(int i=N-2;i--;)a[i]+=a[i+2];
    int y=0,z=fac[a[0]];
    for(int i=1,s=a[0];i<N;++i)
    {
        y=(y+(s+a[i])*1LL*a[i]%p*i)%p;
        z=z*1LL*fac[a[i]]%p*fac[a[i]]%p;
        s=(s+a[i]*2)%p;
    }
    printf("%d %d\n",y,z);
}