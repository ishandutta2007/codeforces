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
int a[N];
int f(int l,int m,int r)
{
    ll res=(m-l)*1LL*(r-m);
    if(!res)return 0;
    if(res>0)return 1;
    return -1;
}
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    int ans=n*2-1;
    for(int i=n-2;i>=1;--i)
    {
        if(!~f(a[i],a[i+1],a[i+2]))
        {
            ++ans;
        }
    }
    for(int i=n-3;i>=1;--i)
    {
        if(f(a[i+1],a[i],a[i+2])==1&&f(a[i+1],a[i+3],a[i+2])==1)
        {
            ++ans;
        }
    }
    write(ans,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}