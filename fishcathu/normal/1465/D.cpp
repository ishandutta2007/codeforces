#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1E5+10;
int read()
{
    int a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
char a[N];
int l[N][2],r[N][2];
int main()
{
    scanf("%s",a+1);
    int n=strlen(a+1);
    ll ans=0;
    ll b=read(),c=read();
    for(int i=1;i<=n;++i)if(a[i]!='?')a[i]&=1;
    if(b>c)
    {
        swap(b,c);
        for(int i=1;i<=n;++i)if(a[i]!='?')a[i]=!a[i];
    }
    for(int i=1;i<=n;++i)
    {
        l[i+1][0]=l[i][0];
        l[i+1][1]=l[i][1];
        if(a[i]!='?')++l[i+1][a[i]];
    }
    for(int i=n;i>=1;--i)
    {
        r[i-1][0]=r[i][0];
        r[i-1][1]=r[i][1];
        if(a[i]!='?')++r[i-1][a[i]];
    }
    for(int i=1;i<=n;++i)
    {
        if(a[i])ans+=l[i][0]*b;
        else ans+=(i-1-l[i][0])*c;
    }
    for(ll i=1,anss=ans;i<=n;++i)if(a[i]=='?')
    {
        anss-=(i-1-l[i][1])*b+r[i][0]*c;
        anss+=l[i][1]*c+(n-i-r[i][0])*b;
        ans=min(ans,anss);
    }
    printf("%lld",ans);
}