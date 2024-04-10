#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E5+10;
const ll inf=1LL<<60;
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
char a[N];
int x,y,n,u,v;
bool check(ll l,ll r,int i,ll m)
{
    l+=u*m;
    r+=v*m;
    m=m*n+i;
    return abs(l-x)+abs(r-y)<=m;
}
int main()
{
    x=read();
    y=read();
    x=read()-x;
    y=read()-y;
    n=read();
    scanf("%s",a+1);
    for(int i=1;i<=n;++i)
    {
        if(a[i]=='U')++v;
        else if(a[i]=='D')--v;
        else if(a[i]=='L')--u;
        else ++u;
    }
    const int s=abs(x)+abs(y)+1;
    ll ans=inf;
    for(int i=1,b=0,c=0;i<=n;++i)
    {
        if(a[i]=='U')++c;
        else if(a[i]=='D')--c;
        else if(a[i]=='L')--b;
        else ++b;
        int l=0;
        for(int r=s;l!=r;)
        {
            int m=l*1LL+r>>1;
            check(b,c,i,m)?r=m:l=m+1;
        }
        if(l!=s)ans=min(ans,l*1LL*n+i);
    }
    write(ans==inf?-1:ans,'\n');
}