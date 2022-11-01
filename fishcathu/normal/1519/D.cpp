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
const int N=5010;
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
int a[N],b[N];
ll f[N][N];
int main()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=n;++i)b[i]=read();
    ll ans=0;
    for(int k=2;k<=n;++k)
    {
        for(int i=1,j=k;j<=n;++i,++j)
        {
            f[i][j]=f[i+1][j-1]+(a[i]-a[j])*1LL*(b[j]-b[i]);
            ans=max(ans,f[i][j]);
        }
    }
    for(int i=1;i<=n;++i)ans+=a[i]*1LL*b[i];
    write(ans,'\n');
}