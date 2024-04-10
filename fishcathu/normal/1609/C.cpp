#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=2E5+10,M=1E6+10;
const int inf=1<<30;
template<typename T>bool cmin(T &l,T r){return l>r?l=r,1:0;}
template<typename T>bool cmax(T &l,T r){return l<r?l=r,1:0;}
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
vector<int>pri;
bool b[M];
int a[N];
void solve()
{
    int n=read(),m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    ll ans=0;
    function<bool(int)>check=[&](int i){return i>0&&i<=n&&a[i]==1;};
    for(int i=1;i<=n;++i)if(!b[a[i]])
    {
        int l=0,r=0;
        while(check(i-m*++l));
        while(check(i+m*++r));
        ans+=l*1LL*r-1;
    }
    write(ans,'\n');
}
int main()
{
    b[1]=1;
    for(int i=2;i<M;++i)
    {
        if(!b[i])pri.pb(i);
        for(int j:pri)
        {
            int t=i*j;
            if(t>=M)break;
            b[t]=1;
            if(!(i%j))break;
        }
    }
    for(int x=read();x--;)
    {
        solve();
    }
}