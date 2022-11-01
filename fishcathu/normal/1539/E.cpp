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
int a[N],nex[N][2];
pii b[N][2],c[2];
void modify(pii &u,pii v)
{
    u.fi=max(u.fi,v.fi);
    u.se=min(u.se,v.se);
}
bool check(pii u,int x)
{
    return x>=u.fi&&x<=u.se;
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)
    {
        a[i]=read();
        for(int j=0;j<=1;++j)
        {
            b[i][j].fi=read();
            b[i][j].se=read();
        }
    }
    b[n+1][0]=b[n+1][1]={0,m};
    for(int i=n;i>=1;--i)
    {
        c[0]=b[i][0],c[1]=b[i][1];
        for(int j=0;j<=1;++j)
        {
            if(check(c[j],a[i]))
            {
                if(check(b[i+1][j],a[i]))nex[i][j]=!j;
                else
                {
                    modify(b[i][!j],b[i+1][!j]);
                    nex[i][j]=j;
                }
            }
            else b[i][!j]={m,0};
        }
    }
    if(b[1][0].fi&&b[1][1].fi)puts("No");
    else
    {
        puts("Yes");
        for(int i=1,j=!b[1][0].fi;i<=n;j=nex[i++][j])write(j,' ');
    }
}