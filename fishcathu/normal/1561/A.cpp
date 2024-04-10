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
const int N=1010;
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
int a[N],n;
bool check()
{
    for(int i=2;i<=n;++i)
    {
        if(a[i]<a[i-1])
        {
            return 0;
        }
    }
    return 1;
}
void solve()
{
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    int res=0;
    while(!check())
    {
        for(int i=res&1|2;i<=n;i+=2)
        {
            if(a[i]<a[i-1])
            {
                swap(a[i],a[i-1]);
            }
        }
        ++res;
    }
    write(res,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}