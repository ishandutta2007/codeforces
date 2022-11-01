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
const int N=5E5+10;
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
char a[N],c[30];
int b[130];
bool solve()
{
    scanf("%s",a+1);
    int n=strlen(a+1),m=0;
    for(int i=97;i<123;++i)b[i]=0;
    for(int i=n;i>=1;--i)
    {
        if(!b[a[i]]++)
        {
            c[++m]=a[i];
        }
    }
    reverse(c+1,c+1+m);
    int s=0;
    for(int i=1;i<=m;++i)
    {
        if(b[c[i]]%i)return 0;
        s+=b[c[i]]/i;
    }
    for(int i=1,j=s+1,k=0,t=1;j<=n;++i)
    {
        if(i==t)t=j,++k;
        if(a[i]^c[k])
        {
            if(a[i]^a[j])return 0;
            ++j;
        }
    }
    for(int i=1;i<=s;++i)putchar(a[i]);
    putchar(' ');
    for(int i=1;i<=m;++i)putchar(c[i]);
    putchar('\n');
    return 1;
}
int main()
{
    for(int x=read();x--;)
    {
        if(!solve())
        {
            puts("-1");
        }
    }
}