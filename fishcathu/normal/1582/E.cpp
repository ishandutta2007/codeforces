#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1E5+10;
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
ll a[N][447],b[N];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)
    {
        a[i][1]=b[i]=read();
        for(int j=2;j<447;++j)a[i][j]=0;
    }
    int res=1;
    for(int i=n;i>=1;--i)
    {
        ll s=0;
        for(int j=i,k=1;j<n&&j<i+446;++j,++k)
        {
            cmax(a[i][k],a[i+1][k]);
            s+=b[j];
            if(s<a[j+1][k-1])cmax(a[i][k],s);
            if(i==1&&a[i][k])res=k;
        }
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