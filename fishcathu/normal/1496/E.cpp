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
const int N=510;
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
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
char a[N][N];
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)scanf("%s",a[i]+1);
    for(int i=1;i<=n;i+=3)
    {
        for(int j=1;j<=m;++j)
        {
            a[i][j]='X';
        }
    }
    for(int i=4;i<=n;i+=3)
    {
        int t=a[i-2][2]=='X'||a[i-1][2]=='X'?2:1;
        a[i-2][t]=a[i-1][t]='X';
    }
    if(!(n%3))
    {
        for(int i=1;i<=m;++i)
        {
            if(a[n][i]=='X')
            {
                a[n-1][i]='X';
            }
        }
   }
   for(int i=1;i<=n;++i)puts(a[i]+1);
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}