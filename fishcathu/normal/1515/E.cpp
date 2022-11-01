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
const int N=410;
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
int f[N][N],c[N][N],n,p;
void init()
{
    for(int i=0;i<=n;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
        }
    }
}
int main()
{
    n=read(),p=read();
    init();
    f[1][1]=1;
    for(int i=2;i<=n;++i)
    {
        for(int j=2;j<i;++j)
        {
            for(int k=j+1>>1;k<j;++k)
            {
                f[i][i-j+k]=(f[i][i-j+k]+f[i-j][i-j]*1LL*f[j-1][k]%p*c[i-j+k][k])%p;
            }
        }
        f[i][i]=f[i-1][i-1]*2%p;
    }
    int ans=0;
    for(int i=n>>1;++i<=n;)ans=(ans+f[n][i])%p;
    write(ans,'\n');
}