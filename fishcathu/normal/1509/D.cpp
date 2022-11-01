#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10;
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
char a[3][N],b[3];
int n;
void solvee(char *a,char *b,char c)
{
    int u=0,v=0;
    for(int i=n>>1;i--;)
    {
        while(a[++u]!=c)putchar(a[u]);
        while(b[++v]!=c)putchar(b[v]);
        putchar(c);
    }
    while(++u<=n)putchar(a[u]);
    while(++v<=n)putchar(b[v]);
    putchar('\n');
}
void solve()
{
    n=read()<<1;
    for(int i=0;i<3;++i)
    {
        scanf("%s",a[i]+1);
        int s=0;
        for(int j=1;j<=n;++j)
        {
            a[i][j]==49?++s:--s;
        }
        b[i]=s>0|48;
    }
    for(int i=0;i<3;++i)
    {
        for(int j=i+1;j<3;++j)
        {
            if(b[i]!=b[j])continue;
            solvee(a[i],a[j],b[i]);
            return;
        }
    }
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}