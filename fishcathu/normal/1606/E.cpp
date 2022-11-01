#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=510;
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
int c[N][N],qpow[N][N],f[N][N];
int main()
{
    const int p=998244353;
    c[0][0]=1;
    for(int i=1;i<N;++i)
    {
        c[i][0]=qpow[i][0]=1;
        for(int j=1;j<N;++j)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
            qpow[i][j]=qpow[i][j-1]*1LL*i%p;
        }
    }
    int n=read(),m=read();
    for(int j=1;j<=m;++j)f[0][j]=1;
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<i;++j)f[i][j]=qpow[j][i];
        for(int j=i;j<=m;++j)
        {
            for(int k=0;k<=i;++k)
            {
                f[i][j]=(f[i][j]+c[i][k]*1LL*qpow[i-1][i-k]%p*f[k][j-i+1])%p;
            }
        }
    }
    write(f[n][m],'\n');
}