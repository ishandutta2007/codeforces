#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=110;
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
int a[N];
bool check(int x)
{
    if(x<2)return 0;
    for(int i=2;i*i<=x;++i)
    {
        if(!(x%i))
        {
            return 0;
        }
    }
    return 1;
}
void solve()
{
    int n=read(),s=0;
    for(int i=1;i<=n;++i)s+=a[i]=read();
    if(!check(s))
    {
        write(n,'\n');
        for(int i=1;i<=n;++i)write(i,' ');
        putchar('\n');
    }
    else
    {
        for(int i=1;i<=n;++i)
        {
            if(check(s-a[i]))continue;
            write(n-1,'\n');
            for(int j=1;j<=n;++j)if(j^i)write(j,' ');
            putchar('\n');
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