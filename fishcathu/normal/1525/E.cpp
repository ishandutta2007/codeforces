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
const int N=5E4+10,M=21;
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
int a[N][M],ny[M];
int main()
{
    int m=read(),n=read();
    for(int j=1;j<=m;++j)
    {
        for(int i=1;i<=n;++i)
        {
            a[i][j]=read();
        }
    }
    const int p=998244353;
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        sort(a[i]+1,a[i]+1+m);
        int res=1;
        for(int j=1;j<=m;++j)
        {
            if(a[i][j]>j)res=res*1LL*(a[i][j]-j)%p;
            else
            {
                res=0;
                break;
            }
        }
        ans=(ans+res)%p;
    }
    ny[1]=1;
    for(int i=2;i<=m;++i)
    {
        ny[i]=(p-p/i)*1LL*ny[p%i]%p;
        ans=ans*1LL*ny[i]%p;
    }
    write((n-ans+p)%p,'\n');
}