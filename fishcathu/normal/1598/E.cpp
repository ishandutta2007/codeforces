#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1010;
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
bool a[N][N];
int f[N][N][2];
int main()
{
    int n=read(),m=read(),ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            a[i][j]=1;
            f[i][j][0]=f[i][j-1][1]+1;
            f[i][j][1]=f[i-1][j][0]+1;
            ans+=f[i][j][0]+f[i][j][1]-1;
        }
    }
    for(int T=read();T--;)
    {
        int x=read(),y=read(),t=-1;
        int i=1,j=1;
        for(int u=x,v=y;1;++i)
        {
            --(i&1?u:v);
            if(!a[u][v])break;
        }
        for(int u=x,v=y;1;++j)
        {
            ++(j&1?v:u);
            if(!a[u][v])break;
        }
        t+=i*j;
        i=1,j=1;
        for(int u=x,v=y;1;++i)
        {
            --(i&1?v:u);
            if(!a[u][v])break;
        }
        for(int u=x,v=y;1;++j)
        {
            ++(j&1?u:v);
            if(!a[u][v])break;
        }
        t+=i*j;
        write(ans+=((a[x][y]^=1)?t:-t),'\n');
    }
}