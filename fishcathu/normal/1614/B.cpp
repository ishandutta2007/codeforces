#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E5+10;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
bool cmin(auto &l,auto r){return l>r?l=r,1:0;}
bool cmax(auto &l,auto r){return l<r?l=r,1:0;}
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
pii a[N];
int pos[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]={read(),i};
    sort(a,a+1+n,greater<>());
    ll ans=0;
    for(int i=0,j=0;i<=n;++i,j=(j<=0)-j)
    {
        pos[a[i][1]]=j;
        ans=ans+a[i][0]*1LL*abs(j);
    }
    write(ans<<1,'\n');
    for(int i=0;i<=n;++i)write(pos[i],' ');
    putchar('\n');
}
int main()
{
    a[0][0]=inf;
    for(int x=read();x--;)
    {
        solve();
    }
}