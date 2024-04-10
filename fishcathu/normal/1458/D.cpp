#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5E5+10;
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
char a[N];
int s[N<<1];
void solve()
{
    scanf("%s",a+1);
    int n=strlen(a+1);
    for(int i=1,j=n;i<=n;++i)
    {
        if(a[i]=='0')++s[j--];
        else ++s[++j];    
    }
    for(int i=n;i--;)
    {
        if(s[n]>=2||!s[n+1])
        {
            putchar('0');
            --s[n--];
        }
        else
        {
            putchar('1');
            --s[++n];
        }
    }
    putchar('\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}