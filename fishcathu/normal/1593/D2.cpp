#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=50;
const int inf=1<<30;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
void cmax(auto &l,auto r){if(r>l)l=r;}
void cmin(auto &l,auto r){if(r<l)l=r;}
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
int a[50];
void solve()
{
    int n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    int res=0;
    for(int i=1;i<=n;++i)
    {
        int y=n-1>>1;
        map<int,int>f;
        for(int j=1;j<=n;++j)
        {
            if(j==i)continue;
            int t=abs(a[j]-a[i]);
            if(t)
            {
                int k=1;
                while(k*k<t)
                {
                    if(!(t%k))++f[k],++f[t/k];
                    ++k;
                }
                if(k*k==t)++f[k];
            }
            else --y;
        }
        if(y<=0)res=inf;
        else
        {
            for(auto [u,v]:f)
            {
                if(v>=y)
                {
                    cmax(res,u);
                }
            }
        }
    }
    write(res^inf?res:-1,'\n');
}
int main()
{
    for(int x=read();x--;)
    {
        solve();
    }
}