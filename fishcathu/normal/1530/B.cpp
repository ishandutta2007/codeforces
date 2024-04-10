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
const int N=25;
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
bool a[N][N];
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            a[i][j]=0;
        }
    }
    for(int i=1;i<=m;i+=2)a[1][i]=a[n][i]=1;
    for(int i=3;i<n-1;i+=2)a[i][1]=a[i][m]=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            putchar(a[i][j]|48);
        }
        putchar('\n');
    }
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}