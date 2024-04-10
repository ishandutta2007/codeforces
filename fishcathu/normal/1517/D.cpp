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
int a[N][N][4],f[N][N][11];
const int b[4][2]={0,1,1,0,0,-1,-1,0};
int main()
{
    int n=read(),m=read(),y=read();
    if(y&1)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                printf("-1 ");
            }
            putchar('\n');
        }
        return 0;
    }
    y>>=1;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<m;++j)
        {
            a[i][j][0]=a[i][j+1][2]=read();
        }
    }
    for(int i=1;i<n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            a[i][j][1]=a[i+1][j][3]=read();
        }
    }
    for(int z=1;z<=y;++z)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=m;++j)
            {
                f[i][j][z]=inf;
                for(int k=0;k<4;++k)
                {
                    if(!a[i][j][k])continue;
                    f[i][j][z]=min(f[i][j][z],f[i+b[k][0]][j+b[k][1]][z-1]+a[i][j][k]);
                }
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            write(f[i][j][y]<<1,' ');
        }
        putchar('\n');
    }
}