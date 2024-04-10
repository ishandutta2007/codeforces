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
const int N=4E5+10,M=18;
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
int a[N][M],n;
int gcd(int l,int r)
{
    while(l)
    {
        if(!(r%=l))return l;
        l%=r;
    }
    return r;
}
bool check(int x)
{
    int y=__lg(x),z=x-(1<<y),k=gcd(a[1][y],a[1+z][y]);
    for(int i=2;i<=n;++i)
    {
        if(gcd(a[i][y],a[i+z][y])!=k)
        {
            return 0;
        }
    }
    return 1;
}
void solve()
{
    n=read();
    for(int i=1;i<=n;++i)a[i][0]=a[i+n][0]=read();
    for(int j=1,k=1;j<M;++j,k<<=1)
    {
        for(int i=n-k<<1;i>=1;--i)
        {
            a[i][j]=gcd(a[i][j-1],a[i+k][j-1]);
        }
    }
    int l=1;
    for(int r=n;l!=r;)
    {
        int m=l+r>>1;
        check(m)?r=m:l=m+1;
    }
    write(l-1,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}