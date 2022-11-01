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
const int N=2E5+10;
const int inf=1<<30;
auto max(auto l,auto r){return l>r?l:r;}
auto min(auto l,auto r){return l<r?l:r;}
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
int a[6]={1,2,3,5,9,17},b[18]={1};
map<int,vector<int>>f[2];
int main()
{
    const int p=998244353;
    int m=read()-1,n=1<<m,y=read(),z=read();
    for(int i=1;i<18;++i)b[i]=b[i-1]*1LL*y%p;
    for(int k=1<<n;k--;)
    {
        vector<int>q;
        int res=0;
        for(int i=1;i<=n;++i)
        {
            int t=m+1;
            for(int j=i+n-1;j&&(k>>j/2^j)&1;j>>=1,--t);
            q.pb(a[t]);
            res=(res+i*1LL*b[a[t]])%p;
        }
        f[k&1][res]=q;
    }
    for(int k=1<<n;k--;)
    {
        vector<int>q;
        int res=z;
        for(int i=n+1;i<=n<<1;++i)
        {
            int t=m+1;
            for(int j=i-1;j&&(k>>j/2^j)&1;j>>=1,--t);
            q.pb(a[t]);
            res=(res+(p-i)*1LL*b[a[t]])%p;
        }
        if(f[k&1^1].count(res))
        {
            for(int x:f[k&1^1][res])write(x,' ');
            for(int x:q)write(x,' ');
            return 0;
        }
    }
    puts("-1");
}