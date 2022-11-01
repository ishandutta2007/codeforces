#include<bits/extc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> pii;
const int N=410;
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
int a[N][N],f[N];
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%1d",a[i]+j);
            a[i][j]+=a[i][j-1];
        }
    }
    int res=inf;
    for(int k=4;k<=m;++k)
    {
        for(int j=k-3;j>=1;--j)
        {
            for(int i=1,s=0;i<=n;++i)
            {
                int x=k-j-1-a[i][k-1]+a[i][j],y=a[i][k-1]-a[i][j]+(a[i][j-1]==a[i][j])+(a[i][k-1]==a[i][k]);
                if(i>=5)res=min(res,x+s+f[i-4]);
                s+=y;
                f[i]=min(f[i-1],x-s);
            }
        }
    }
    write(res,'\n');
}
int main()
{
    f[0]=inf;
    for(int x=read();x--;)
    {
        solve();
    }
}