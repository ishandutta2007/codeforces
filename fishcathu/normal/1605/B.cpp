#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1010;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
void cmin(auto &l,auto r){l=l<r?l:r;}
void cmax(auto &l,auto r){l=l>r?l:r;}
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
int b[N],s;
void solve()
{
    int n=read();
    scanf("%s",a+1);
    s=0;
    for(int l=0,r=n+1;1;)
    {
        while(a[++l]=='0');
        while(a[--r]=='1');
        if(l>r)break;
        b[++s]=l;
        b[++s]=r;
    }
    if(!s)puts("0");
    else
    {
        puts("1");
        sort(b+1,b+1+s);
        write(s,' ');
        for(int i=1;i<=s;++i)write(b[i],' ');
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