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
const int N=2010;
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
int f[N][N];
int g(int i,int j){return ~j?f[i][j]:0;}
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        int x=i-read();
        for(int j=0;j<=n;++j)f[i][j]=max(f[i-1][j]+(x==j),g(i-1,j-1));
    }
    int res=0;
    while(res<=n&&f[n][res]<m)++res;
    write(res>n?-1:res,'\n');
}
int main()
{
    for(int i=1;i<N;++i)f[0][i]=-inf;
    for(int x=read();x--;)
    {
        solve();
    }
}