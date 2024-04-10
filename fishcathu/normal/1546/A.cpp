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
const int N=110;
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
int a[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    vct u,v;
    for(int i=1;i<=n;++i)
    {
        int x=read();
        if(a[i]>x)
        {
            for(int j=a[i]-x;j--;)
            {
                u.pb(i);
            }
        }
        else
        {
            for(int j=x-a[i];j--;)
            {
                v.pb(i);
            }
        }
    }
    if(u.size()^v.size())puts("-1");
    else
    {
        write(u.size(),'\n');
        for(int i=u.size();i--;)
        {
            write(u[i],' ');
            write(v[i],'\n');
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